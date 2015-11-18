#include <stdio.h>
#include <stdlib.h>

int main()
{   printf("Enter number of coefficients:\n");
    int a,b,c;
    int coefficientarray[100];
    scanf("%d",&a);
    b=a;
    while(a!=-1){printf("Enter %d-th coefficient.\n",a);
    scanf("%d",&coefficientarray[a]);a--;}
    printf("Enter x value:\n");
    scanf("%d",&a);
    c=coefficientarray[b]*a;
    while(b>1){c=c+coefficientarray[b-1];c=c*a;b--;
    }
    printf("%d",c);
    return 0;
}
