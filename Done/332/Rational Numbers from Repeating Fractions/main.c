#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
    while(b) b ^= a ^= b ^= a %= b;
    return a;
}

void reduceFraction(int *x1,int *x2)
{
    int temp;
    while((temp=gcd(*x2,*x1))>1)
    {
        *x1/=temp;
        *x2/=temp;
    }
}

int main()
{
    char number[35];
    int casenum=1;
    int mocniny[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    fgets(number,35,stdin);
    while(number[0]!='-')
    {
        int i;
        int x1,x2;
        int recurrentpart;
        int total;
        x1=x2=0;
        recurrentpart=number[0]-'0';
        for(i=4;number[i]!='\n';i++)
        {
            x1=x1*10+number[i]-'0';
        }
        total=i-4;
        x2=x1;
        if(recurrentpart!=0)
        {
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
        fgets(number,35,stdin);
        casenum++;
    }
    return 0;
}
