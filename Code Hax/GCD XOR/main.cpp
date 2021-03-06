#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("Result: %d\n",gcd(a,b));
    return 0;
}
