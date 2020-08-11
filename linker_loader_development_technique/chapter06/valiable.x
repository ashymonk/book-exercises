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
                BYTE(1)
                . = ALIGN(2);
                svalue = .;
                SHORT(12345)
                . = ALIGN(4);
                lvalue = .;
                LONG(87654321);
                lvalue2 = .;
                . += 8;
                *(.data)
        }
        .bss    : { *(.bss) }
}
