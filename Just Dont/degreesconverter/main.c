#include <stdio.h>
#include <stdlib.h>

int main()
{   printf("What do you want to do:\n");
    printf("1 for Fahrenheit to Celsium degrees\n");
    printf("2 for Fahrenheit to Kelvin degrees\n");
    printf("3 for Celsium to Fahrenheit degrees\n");
    printf("4 for Celsium to Kelvin degrees\n");
    printf("5 for Kelvin to Fahrenheit degrees\n");
    printf("6 for Kelvin to Celsium degrees\n");
    int a;
    double b,c,d;
    c=0.555555555555555555555555555555555555555555555555555555555555555555555555555555;
    d=1.8;
    scanf("%d",&a);
    printf("Enter value of chosen degrees:");
    scanf("%lf",&b);
    if(a==1){b=b-32;
    b=b*c;}
    if(a==2){b=(b+459.67)*c;}
    if(a==3){b=b*d+32;}
    if(a==4){b=b-273.15;}
    if(a==5){b=b*d-459.67;}
    if(a==6){b=b+273.15;}
    if(a>6){printf("Die");
    return 1337;}
    printf("Result is %lf",b);
    return 0;
}
