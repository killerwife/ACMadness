#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    double a, b;
    while (scanf("%lf%lf", &a, &b) != EOF)
    {
        double temp = exp((log(b)/a));
        printf("%.0lf\n", temp);
    }
    return 0;
}