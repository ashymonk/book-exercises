#include <stdio.h>
#include <stdlib.h>

extern int sdata;
extern int edata;
extern int end;

int main()
{
        printf("&sdata = 0x%p\n", &sdata);
        printf("&edata = 0x%p\n", &edata);
        printf("&end   = 0x%p\n", &end);
        exit (0);
}
