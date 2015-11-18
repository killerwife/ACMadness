#include <stdio.h>
#include <stdlib.h>

int main()
{   printf("Enter time in seconds:");
    int a,b,c;
    scanf("%d",&a);
    b=a%1440;
    a=a/1440;
    c=b%60;
    b=b/60;
    printf("It is %d hours %d minutes %d seconds.\n",a,b,c);
    return 0;
}
