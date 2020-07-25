#include <stdio.h>
#include <stdlib.h>
#include "elf_linux.h"

int main()
{
	Elf_Ehdr *ehdr;

	ehdr = (Elf_Ehdr*)0x7ffff79e4000;

	printf("0x%02x%c%c%c\n",
			ehdr->e_ident[EI_MAG0],
			ehdr->e_ident[EI_MAG1],
			ehdr->e_ident[EI_MAG2],
			ehdr->e_ident[EI_MAG3]);
	exit(0);
}
