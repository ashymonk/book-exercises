#include <stdio.h>
#include <stdlib.h>

int stext  = 1;
int srdata = 1;
extern int sdata;

int main()
{
        printf("&stext  = 0x%p, stext  = 0x%08x\n", (void*)&stext,  stext);
        printf("&srdata = 0x%p, srdata = 0x%08x\n", (void*)&srdata, srdata);
        printf("&sdata  = 0x%p, sdata  = 0x%08x\n", (void*)&sdata,  sdata);
        exit (0);
}
