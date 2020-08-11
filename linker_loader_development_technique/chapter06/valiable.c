#include <stdio.h>
#include <stdlib.h>

extern char cvalue;
extern short int svalue;
extern int lvalue;
extern int lvalue2;

int main()
{
        printf("&cvalue  = 0x%p, cvalue  = %d\n", (void*)&cvalue,  (int)cvalue);
        printf("&svalue  = 0x%p, svalue  = %d\n", (void*)&svalue,  (int)svalue);
        printf("&lvalue  = 0x%p, lvalue  = %d\n", (void*)&lvalue,  (int)lvalue);
        printf("&lvalue2 = 0x%p, lvalue2 = %d\n", (void*)&lvalue2, (int)lvalue2);
        exit (0);
}
