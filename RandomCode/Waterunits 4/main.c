#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mocnina(double a,double b)
{
    double c=1;
    while(b>0)
    {
        c=c*a;
        b--;
    }
    return c;
}

double power (int *array, int i)
{   if(i==0){return 1;}
    if(i==1){return array[0];}
    i--;
    double result=array[i];

    for(; i>0; i--)
    {
        result = mocnina(array[i-1],result);
    }
    return result;
}

int intpowa(int a,int b)
{   int c=1;
    while(b>0)
    {
        c=c*a;
        b--;
    }
    return c;
}

int* primefactor(int a,int *b)
{
    int i,j,c;
    i=2;j=0;c=a;
    while(c!=1)
    {
        if(c%i==0)
        {
            c=c/i;
            j++;
        }
        else
        {
            i++;
        }
    }
    *b=j;
    int *p;
    p=(int) malloc(sizeof(int)*j);
    i=2;j=0;c=a;
        while(c!=1)
    {
        if(c%i==0)
        {
            c=c/i;
            p[j]=i;
            j++;
        }
        else
        {
            i++;
        }
    }
    return p;
}

void generate(int *a,int b)
{   int i=0;
    while(i<b)
    {
        a[i]=i+1;
        i++;
    }
}

int calc(int *a,int c,int b)
{   int d;d=1;
    if(b<c-1)
    {
       d=intpowa(&a[b],calc(a,c,b+1));
    }
    else
    {
        d=a[c-1];
    }
    return d;
}

int main()
{   int a,b,c,i,j,k;
    int *back;
    scanf("%d",&c);
    int **factor;
    int *sievearray;
    int *primearray;
    int *counterarray;
    int size;
    int temp;
    i=0;
    sievearray=(int) malloc(sizeof(int)*c);
    generate(sievearray,c);
a=b=2;
j=0;
while(a<sqrt(c))
    {

    b=a+a;
     if(sievearray[a-1]==a)
      {
      while(b<=c)
      {sievearray[b-1]=0;b=b+a;}
     }
     a++;
    }
    i=0;
    while(i<c)
    {
        if(sievearray[i]!=0)
        {
            j++;
        }
        i++;
    }
    i=1;
     size=j-1;
    primearray=(int) malloc(sizeof(int)*(j-1));
     counterarray=(int) calloc((j-1),sizeof(int));
       j=0;
    while(i<c)
    {
        if(sievearray[i]!=0)
        {
            primearray[j]=sievearray[i];
            j++;
        }
        i++;
    }
    i=0;
    while(i<size)
    {  counterarray[i]++;
       a=primearray[i];
       while(a*primearray[i]<=c)
       {
           a=a*primearray[i];
           counterarray[i]++;

       }
       i++;
    }
    i=0;
    back=(int) malloc(sizeof(int)*j);
    factor=(int *) malloc(sizeof(int*)*j);
    while(i<j)
    {
        factor[i]=primefactor(counterarray[i],&back[i]);
        i++;
    }
    i=0;
    while(i<j)
    {
        if(factor[i][back[i]-1]==3&&factor[i][back[i]-2]==2)
        {
            temp=factor[i][back[i]-1];
            factor[i][back[i]-1]=factor[i][back[i]-2];
            factor[i][back[i]-2]=temp;
        }
        i++;
    }
    i=0;k=0;
    while(i<j)
    {
        if(mocnina(primearray[i],power(factor[i],back[i]))>mocnina(primearray[k],power(factor[k],back[k])))
        {
            k=i;
        }
        i++;
    }
    i=0;
    printf("%d^",primearray[k]);
    while(i<back[k])
    {
        printf("%d^",factor[k][i]);
        i++;
    }
    free(back);
    free(factor);
    free(counterarray);
    free(primearray);
    free(sievearray);
    return 0;
}
