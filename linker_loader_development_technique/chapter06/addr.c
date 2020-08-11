#include <stdio.h>
#include <stdlib.h>

extern int value;
extern int stext,  etext;
extern int srdata, erdata;
extern int sdata,  edata;
extern int sbss,   ebss;

int main()
{
        printf("&value  = 0x%p\n", (void*)&value);
        printf("stext   = 0x%08x, etext   = 0x%08x\n", stext, etext);
        printf("sdata   = 0x%08x, edata   = 0x%08x\n", sdata, edata);
        printf("&stext  = 0x%p, &etext  = 0x%p\n", (void*)&stext,  (void*)&etext);
        printf("&srdata = 0x%p, &erdata = 0x%p\n", (void*)&srdata, (void*)&erdata);
        printf("&sdata  = 0x%p, &edata  = 0x%p\n", (void*)&sdata,  (void*)&edata);
        printf("&sbss   = 0x%p, &ebss   = 0x%p\n", (void*)&sbss,   (void*)&ebss);
        exit (0);
}
