#include <stdio.h>
#include <stdlib.h>

void swapping(int *a, int *b)
{
    int swaptemp;
    swaptemp=*a;
    *a=*b;
    *b=swaptemp;
}

void xorSwapping(int *a, int *b)
{
    *a^=*b;
    *b=*a^*b;
    *a^=*b;
}

void xorAdding(int *a, int *b)
{
    *a+=*b;
    *b=*a-*b;
    *a=*a-*b;
}

int main()
{   int a,b;
   scanf("%d%d",&a,&b);
   xorAdding(&a,&b);
   printf("\n%d %d",a,b);
    return 0;
}
