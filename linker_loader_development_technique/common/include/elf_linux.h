#ifndef _LINUX_DEPEND_H_
#define _LINUX_DEPEND_H_

#include <elf.h>

#if __x86_64__
typedef Elf64_Ehdr Elf_Ehdr;
typedef Elf64_Shdr Elf_Shdr;
#else
typedef Elf32_Ehdr Elf_Ehdr;
typedef Elf32_Shdr Elf_Shdr;
#endif /* __x86_64__ */

#define IS_ELF(ehdr) ( \
	((ehdr).e_ident[EI_MAG0] == ELFMAG0) && \
	((ehdr).e_ident[EI_MAG1] == ELFMAG1) && \
	((ehdr).e_ident[EI_MAG2] == ELFMAG2) && \
	((ehdr).e_ident[EI_MAG3] == ELFMAG3))

#endif /* _LINUX_DEPEND_H_ */
