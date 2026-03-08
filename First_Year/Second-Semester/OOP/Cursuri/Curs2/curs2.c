#include <stdio.h>

void byValue(int a)
{
    a += 1;
}

void byRef(int *a)
{
    *a += 1;
}

void testArrayParam(int a[])
{
    a[0] = 3;
}

int main()
{
    int a = 10;
    byValue(a);
    printf("Valoarea ramane neschimbata a = %d \n",a);
    byRef(&a);
    printf("Valoarea lui a se schimba = %d \n",a);
    int b[] = {1,2,3};
    testArrayParam(b);
    printf("value is changed %d \n",b[0]);
    return 0;
}








