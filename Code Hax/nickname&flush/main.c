#include <stdio.h>
#include <stdlib.h>

void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in );
  while ( ch != EOF && ch != '\n' );

  clearerr ( in );
}

void mypause ( void )
{
  printf ( "Press [Enter] to continue . . ." );
  fflush ( stdout );
  getchar();
}

int main()
{   int i;
    i=0;
    printf("*  * * *    *    **** **** *   *   * * **** ****\n");
    printf("* *  * *    *    *    *  *  * * * *  * *    *\n");
    printf("**   * *    *    **** ***   * * * *  * **** ****\n");
    printf("* *  * *    *    *    * *    *   *   * *    *\n");
    printf("*  * * **** **** **** *  *   *   *   * *    ****\n");
myflush ( stdin );
  mypause();
    return 0;
}
