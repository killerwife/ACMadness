#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cases;
    int first,second,result;
    int a,b,t,k;
    int a2,b2;
    scanf("%d",&cases);
    while(cases>0)
    {
        scanf("%d%d%d",&first,&second,&result);
         a=first;
         b=second;
         while(b!=0)
         {t=a%b;
         a=b;
         b=t;}
         if(result%a!=0||(result>first&&result>second))
         {
             printf("-1\n");
             cases--;
             continue;
         }
         if(first==result||second==result)
         {
             printf("1\n");
             cases--;
             continue;
         }
         if(result==0)
         {
			printf("0\n");
			cases--;
			continue;
		 }
         a=b=t=0;
         a2=b2=k=0;
         while(a!=result&&b!=result&&a2!=result&&b2!=result)
         {
             if(a==0)
             {
                 a=first;
                 t++;
             }
             else if(b==second)
             {
                 b=0;
                 t++;
             }
             else
             {
                 int temp=second-b;
                 a-=temp;
                 b=second;
                 if(a<0)
                 {
                     b+=a;
                     a=0;
                 }
                 t++;
             }
             if(a2==0)
             {
                 a2=second;
                 k++;
             }
             else if(b2==first)
             {
                 b2=0;
                 k++;
             }
             else
             {
                 int temp=first-b2;
                 a2-=temp;
                 b2=first;
                 if(a2<0)
                 {
                     b2+=a2;
                     a2=0;
                 }
                 k++;
             }
          }


         printf("%d\n",t);
         cases--;
    }
    return 0;
}
