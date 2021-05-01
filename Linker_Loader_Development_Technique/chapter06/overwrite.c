#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int value;
char buffer[100];

void func1(int *value) { *value += 1; }
void func2(int *value) { *value += 2; }
void func3(int *value) { *value += 4; }

int main()
{
        value = 0; func1(&value); func2(&value); func3(&value);
        printf("value = %d\n", value);

        memcpy(func1,  func2, (char *)func3 - (char *)func2);
        memcpy(buffer, func3, (char *)main  - (char *)func3);

        value = 0; func1(&value); func2(&value);
        ((void(*)())buffer)(&value);
        printf("value = %d\n", value);

        exit (0);
}
