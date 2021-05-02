#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char sdata, edata, end;

int i0, i1 = 1;
double d0, d1 = 0.1;
char *s0, *s1 = "sample string";

/* ����ͤ���¸���� */
char * save_ivalue()
{
        char * p;
        int size = &edata - &sdata;
        p = malloc(size);
        memcpy(p, &sdata, size); /* �ǡ����ΰ�����򤹤� */
        return (p);
}

/* ����ͤ��᤹ */
void reset_ivalue(char * p)
{
        /* �ǡ����ΰ������ */
        memcpy(&sdata, p, (&edata - &sdata));

        /* BSS �ΰ�򥼥����ꥢ���� */
        memset(&edata, 0, (&end - &edata));
}

int main()
{
        char * p;

        /* ����ͤ���¸ */
        p = save_ivalue();
        printf("i0 = %d, i1 = %d, d0 = %f, d1 = %f, s0 = %s, s1 = %s\n",
	 i0, i1, d0, d1, s0, s1);

        /* �ѿ����ͤ��ѹ� */
        i0 = 1; i1 = 2; d0 = 1.1; d1 = 1.2; s0 = "sample1"; s1 = "sample2";
        printf("i0 = %d, i1 = %d, d0 = %f, d1 = %f, s0 = %s, s1 = %s\n",
	 i0, i1, d0, d1, s0, s1);

        /* ����ͤ��᤹ */
        reset_ivalue(p);
        printf("i0 = %d, i1 = %d, d0 = %f, d1 = %f, s0 = %s, s1 = %s\n",
	 i0, i1, d0, d1, s0, s1);

        exit (0);
}