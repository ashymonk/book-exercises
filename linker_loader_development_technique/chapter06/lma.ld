SECTIONS
{
        value = 0x7ffffedc0000;
        . = 0x7ffff79e4000 + SIZEOF_HEADERS;
        PROVIDE_HIDDEN (__init_array_start = .);
        PROVIDE_HIDDEN (__init_array_end = .);
        PROVIDE_HIDDEN (__fini_array_start = .);
        PROVIDE_HIDDEN (__fini_array_end = .);
        .text   : AT(value) { stext = .; *(.text) etext = .; }
        .rodata : { srdata = .; *(.rodata) erdata = .; }
        .data   : { sdata = .; *(.data) edata = .; }
        .bss    : { sbss = .; *(.bss) ebss = .; }
}
