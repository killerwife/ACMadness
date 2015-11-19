#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gdc(int x1,int x2)
{
    int temp;
    while(x2!=0)
    {
        temp=x2;
        x2=x1%x2;
        x1=temp;
    }
    return x1;
}

void reduceFraction(int *x1,int *x2)
{
    int temp;
    while((temp=gdc(*x2,*x1))>1)
    {
        *x1/=temp;
        *x2/=temp;
    }
}

int main()
{
    int recurrentpart;
    int total;
    int casenum=1;
    int mocniny[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    scanf("%d",&recurrentpart);
    while(recurrentpart>=0)
    {
        int x1,x2;
        scanf(" 0.%d%n",&x1,&total);
        total=total-3;;
        if(recurrentpart!=0)
        {
            x2=x1;
            x2/=mocniny[recurrentpart];
            x1-=x2;
        }
        x2=mocniny[total];
        if(recurrentpart!=0)
        {
            x2-=mocniny[total-recurrentpart];
        }
        reduceFraction(&x1,&x2);
        printf("Case %d: %d/%d\n",casenum,x1,x2);
        scanf("%d",&recurrentpart);
        casenum++;
    }
    return 0;
}
