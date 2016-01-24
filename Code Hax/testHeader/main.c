#include <stdio.h>
#include <stdlib.h>

void test(int m,int n,int (*pole)[n])
{
    printf("5");
}

int main()
{
    int pole[2][3];
    int m=2,n=3;
    test(m,n,pole);
    return 0;
}
