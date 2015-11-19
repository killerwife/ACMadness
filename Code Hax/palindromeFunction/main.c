#include <stdio.h>
#include <stdlib.h>



void palindrome(void)
{  int a;
   printf("Enter number for palindrome check.");
    scanf("%d",&a);
   int mod;
   int b;
   b=a;
   mod=0;
   while(b!=0){mod=mod*10+b%10;b=b/10;}
   if(a==mod){printf("Number %d is a palindrome.",a);}
   else{printf("Number %d is not palindrome.",a);}
}



int main()
{
    palindrome();
    return 0;
}
