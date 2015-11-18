#include <stdio.h>
#include <stdlib.h>

int factorial (int x)
{ int y=1;
  int a=1;
  while(x>=y){a=a*y;
  y++;}
  return a;
}

 int combination(int y,int z)
 {
     int f;
     int r;
     r=y-z;
     f=((factorial(y))/((factorial(z))*(factorial(r))));
     return f;
 }


int main()
{   int a,b,c,d,e,f,j,h;
    a=b=c=d=e=f=j=h=0;
    printf("Enter number of rows.");
    scanf("%d",&b);
    c=1;
    e=b-1;
    a=0;
    while(a<b){
    f=e;
    h=0;
    j=a;
    while(f!=0){
    printf(" ");
    f--;
    }
    while(h<=a){
    printf("%d,",combination(a,h));

    h++;}
    printf("\n");
    c=c+2;

    e=e-1;



    a++;
    }
    return 0;
}
