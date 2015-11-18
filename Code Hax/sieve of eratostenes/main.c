#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void generate(int *a,int b)
{   int i=0;
    while(i<b)
    {
        a[i]=i+1;
        i++;
    }
}


int main()
{int sievearray[1001]; int i=0;int a,b,c;int j=0;
generate(sievearray,1001);
a=b=2;
while(a<500)
    {

    b=a+a;
     if(sievearray[a-1]==a)
      {
      while(b<1000)
      {sievearray[b-1]=0;b=b+a;}
     }
     a++;
    }
    i=0;
    while(i<100){if(sievearray[i]!=0){printf("%d\n",sievearray[i]);j++;}i++;}
    printf("%d",j);
    return 0;
}
