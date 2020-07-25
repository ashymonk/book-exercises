#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "elf_linux.h"

static int elfdump(char *head)
{
	Elf_Ehdr *ehdr;
	Elf_Shdr *shdr, *shstr, *str, *sym, *rel;
	Elf_Phdr *phdr;
	Elf_Sym *symp;
	Elf_Rel *relp;
	int i, j, size;
	char *sname;

	ehdr = (Elf_Ehdr*)head;

	if (!IS_ELF(*ehdr)) {
		fprintf(stderr, "This is not ELF file.\n");
		return 1;
	}

	if (ehdr->e_ident[EI_CLASS] != ELF_CLASS) {
		fprintf(stderr, "unknown class. (%d)\n", (int)ehdr->e_ident[EI_CLASS]);
		return 1;
	}

	if (ehdr->e_ident[EI_DATA] != ELF_DATA) {
		fprintf(stderr, "unknown endian. (%d)\n", (int)ehdr->e_ident[EI_DATA]);
		return 1;
	}

	/* get .shstrtab section header offset */
	shstr = (Elf_Shdr*) (head + ehdr->e_shoff + ehdr->e_shentsize * ehdr->e_shstrndx);

	/* show sections */
	printf("Sections:\n");
	for (i = 0; i < ehdr->e_shnum; i++) {
		shdr = (Elf_Shdr*) (head + ehdr->e_shoff + ehdr->e_shentsize * i);
		sname = (char*) (head + shstr->sh_offset + shdr->sh_name);
		printf("\t[%d]\t%s\n", i, sname);
		if (!strcmp(sname, ".strtab")) str = shdr;
	}

	return 0;
}

int main(int argc, char **argv)
{
	int fd;
	struct stat sb;
	char *head;

	(void)argc;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) exit(1);
	fstat(fd, &sb);
	head = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	elfdump(head);
	munmap(head, sb.st_size);
	close(fd);

	exit(0);
}
