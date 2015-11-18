#include <stdio.h>
#include <stdlib.h>

int main()
{   printf("Enter first part of birthnumber:");
    int a,b;
    scanf("%d",&a);
    b=a/10000;

    printf("The person was born in year 19%d.",b);
    a=a-b*10000;
    if(a/1000>=5){
    printf("The person is female\n");}
    else{printf("The person is male\n");}
    b=a/100;
    if(b>13){b=b-50;}
    printf("The person was born in month %d\n",b);
    a=a-b*100;
    b=a/1;
    printf("The person was born on the %d th day of the month. ",b);
    return 0;
}
