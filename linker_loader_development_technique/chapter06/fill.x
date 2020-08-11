SECTIONS
{
        . = 0x7ffff79e4000 + SIZEOF_HEADERS;
        PROVIDE_HIDDEN (__init_array_start = .);
        PROVIDE_HIDDEN (__init_array_end = .);
        PROVIDE_HIDDEN (__fini_array_start = .);
        PROVIDE_HIDDEN (__fini_array_end = .);
        .text   : { *(.text) }
        .rodata : { *(.rodata) }
        .data   : {
                cvalue = .;
                . += 1;
                . = ALIGN(2);
                svalue = .;
                . += 2;
                . = ALIGN(4);
                lvalue = .;
                . += 4;
                lvalue2 = .;
                . += 4;
                *(.data)
        } = 0x90909090
        .bss    : { *(.bss) }
}
