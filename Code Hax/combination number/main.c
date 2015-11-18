#include <stdio.h>
#include <stdlib.h>


int factorial (int x)
{ int y=1;
  int a=1;
  while(x>=y){a=a*y;
  y++;}
  return a;
}

 int combination(int y,int z,int r)
 {
     int f;
     f=(factorial(y)/((factorial(z))* factorial(r)));
     return f;
 }

int main()
{    int a,b,c,r;
    scanf("%d%d",&a,&b);
    if(a<b){printf("Wrong input.");
    return 2;}
    if(a==0){printf("1");
    return 1;}
    r=a-b;
    printf("%d\n",combination(a,b,r));
    return 0;
}
