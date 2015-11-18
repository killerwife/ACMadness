#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial( int c )
{
    if ( c <= 1 )
        return 1;
    else
        return  c * factorial( c-1 );
}


int main()
{   double a,b,c,input,i_max, decision;
    int i;
    int input1;
    a=b=i=1;
    i_max=5;
    printf("Enter angle in degrees or radians.\n");
    scanf("%lf",&input);
    printf("Degrees or radians? 1 or 2.\n");
    scanf("%lf",&decision);
    if(decision ==2){input= input*180/M_PI;}
    else{}

    input1= input;
    input1 = input1 %360;
    input = input1;
    if(input > 90 && input <=180){input= -(input -180);}
    if(input > 180 && input <=270){input= -(input -180);}
    if(input > 270 && input <=360){input= input -360;}
    a= M_PI/180*input;
    c=3;
        while(i < i_max){ if (i%2==0){
    a= a + pow(M_PI/180,c)*(pow(input,c)/factorial(c));}
    else {a= a - pow(M_PI/180,c)*(pow(input,c)/factorial(c));}


    c= c+2;
    i++;

    }
    printf("result in degrees or radians, 1 or 2\n");
    scanf("%lf",&decision);
    if(decision ==2){a= a*M_PI/180;}
    printf("degrees %lf\n",a);
    return 0;
}
