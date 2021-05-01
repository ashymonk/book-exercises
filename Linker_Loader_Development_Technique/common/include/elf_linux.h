#ifndef _LINUX_DEPEND_H_
#define _LINUX_DEPEND_H_

#include <elf.h>

#if defined(__x86_64__)
typedef Elf64_Ehdr Elf_Ehdr;
typedef Elf64_Shdr Elf_Shdr;
typedef Elf64_Phdr Elf_Phdr;
typedef Elf64_Sym Elf_Sym;
typedef Elf64_Rel Elf_Rel;
# define ELF_CLASS ELFCLASS64
# define ELF_ST_TYPE(st_info) ELF64_ST_TYPE(st_info)
# define ELF_R_SYM(r_info) ELF64_R_SYM(r_info)
#elif defined(__i386__)
typedef Elf32_Ehdr Elf_Ehdr;
typedef Elf32_Shdr Elf_Shdr;
typedef Elf32_Phdr Elf_Phdr;
typedef Elf32_Sym Elf_Sym;
typedef Elf32_Rel Elf_Rel;
# define ELF_CLASS ELFCLASS32
# define ELF_ST_TYPE(st_info) ELF32_ST_TYPE(st_info)
# define ELF_R_SYM(r_info) ELF32_R_SYM(r_info)
#endif

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
# define ELF_DATA ELFDATA2LSB
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
# define ELF_DATA ELFDATA2MSB
#endif

#define IS_ELF(ehdr) ( \
	((ehdr).e_ident[EI_MAG0] == ELFMAG0) && \
	((ehdr).e_ident[EI_MAG1] == ELFMAG1) && \
	((ehdr).e_ident[EI_MAG2] == ELFMAG2) && \
	((ehdr).e_ident[EI_MAG3] == ELFMAG3))

#endif /* _LINUX_DEPEND_H_ */
