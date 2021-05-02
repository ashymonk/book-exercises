#include <stdio.h>
#include <stdlib.h>

int func(int x, int y)
{
        (void)x;
        (void)y;

        return 0;
}

int main()
{
        exit( func(1, 2) );
}
