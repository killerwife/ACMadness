#include <stdio.h>

int factorial ( int x );

int main()
{
  int x;
  printf( "Please input factorial: " );
  scanf( "%d", &x );
  printf( "The factorial is %d\n", factorial( x ) );
  getchar();
}

int factorial (int x)
{ int y=1;
  int a=1;
  while(x>=y){a=a*y;
  y++;}
  return a;
}
