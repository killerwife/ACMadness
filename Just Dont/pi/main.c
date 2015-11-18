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
{   double i,c,a;
    c=3;

     a= M_PI/180*55; - pow(M_PI/180,c)*(pow(55,c)/factorial(c));
     printf("%lf",a);
    return 0;
}
