#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int faktorial(int a)
{
    int temp=1;
    while(a>=1)
    {
        temp=temp*a;
        a--;
    }
    return temp;
}

typedef struct
{
    double *array;
    int increment;
} Yourstack;

int Isempty(int increment)
{
    if(increment==-1)
    {
        return 0;
    }
    else{return 1;}
}

void Pushintostack(int *array, int *increment,int value)
{
    *increment=*increment+1;
    array[*increment]=value;

}

int Popfromstack(int *array, int *increment)
{
    int temp;
    if(Isempty(*increment)==1)
    {
        temp=array[*increment];
        *increment=*increment+1;
        return temp;
    }
    else{return -1;}
}


int main()
{
    int numberofcondensators;
    double capacitance;
    scanf("%d%lf",&numberofcondensators,&capacitance);
    int *p;
    int i=1;
    double a;
    a=pow(2,numberofcondensators);
    p=(int*) malloc(sizeof(int)*a);
    p[0]=42;
    int k,l;
    k=l=i=0;
    while(i<numberofcondensators)
    {
        p[i]=1;
        p[i+1]=0;
        i=i+2;
    }
    Yourstack Calculation;
    Calculation.array=(double *) malloc(sizeof(double)*numberofcondensators);

    return 0;
}
