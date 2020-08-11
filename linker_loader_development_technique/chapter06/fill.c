#include <stdio.h>
#include <stdlib.h>

extern int cvalue;
extern int svalue;
extern int lvalue;
extern int lvalue2;

int main()
{
        printf("&cvalue = 0x%p, cvalue = 0x%08x\n",   (void*)&cvalue, cvalue);
        printf("&svalue = 0x%p, svalue = 0x%08x\n",   (void*)&svalue, svalue);
        printf("&lvalue = 0x%p, lvalue = 0x%08x\n",   (void*)&lvalue, lvalue);
        printf("&lvalue2 = 0x%p, lvalue2 = 0x%08x\n", (void*)&lvalue2, lvalue2);
        exit (0);
}
