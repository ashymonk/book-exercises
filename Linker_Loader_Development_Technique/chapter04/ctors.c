#include <stdio.h>
#include <stdlib.h>

int count = 0;

void init1()
{
        count++;
        printf("ctors test. (init1) count=%d\n", count);
}

void init2()
{
        count++;
        count++;
        printf("ctors test. (init2) count=%d\n", count);
}

void fini1()
{
        count--;
        count--;
        printf("dtors test. (fini1) count=%d\n", count);
}

void fini2()
{
        count--;
        printf("dtors test. (fini2) count=%d\n", count);
}

void (*fp1)(void) __attribute__((section(".ctors"))) = init1;
void (*fp2)(void) __attribute__((section(".ctors"))) = init2;

void (*fp3)(void) __attribute__((section(".dtors"))) = fini1;
void (*fp4)(void) __attribute__((section(".dtors"))) = fini2;

int main()
{
        printf("%d\n", count);
        exit (0);
}
