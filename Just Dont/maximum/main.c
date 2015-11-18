#include <stdio.h>
#include <stdlib.h>

int main()
{   printf("Enter 3 numbers");
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if (a<b){a=b;}
    if (a<c) {a=c;}
    printf("The max is %d\n",a);
    return 0;
}
