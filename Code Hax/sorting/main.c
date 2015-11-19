#include <stdio.h>
#include <stdlib.h>

void swapping(int *a, int *b)
{
    int swaptemp;
    swaptemp=*a;
    *a=*b;
    *b=swaptemp;

}

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

void nickname(void)
{
    printf("\n");
    printf("*  * * *    *    **** **** *   *   * * **** ****\n");
    printf("* *  * *    *    *    *  *  * * * *  * *    *\n");
    printf("**   * *    *    **** ***   * * * *  * **** ****\n");
    printf("* *  * *    *    *    * *    *   *   * *    *\n");
    printf("*  * * **** **** **** *  *   *   *   * *    ****\n");
myflush ( stdin );
  mypause();
}
//tieto tri funkcie su na vymazanie databazy posledneho stlaceneho pismena, na pockanie aby program neskoncil po stlacenie enter, a moje logo, zvysok je uloha//
void arraygenerate(int *array,int *elementnumber)
{   int i= *elementnumber-1;

     while(i>=0){
    array[i]=rand();
    i--;}
    i=i+1;
    //while(i<=*elementnumber){printf("%d\t",array[i]);i++;}i=0;printf("\n\n");
}

void bubblesort(int *sortingarray,int *elementnumber)
{ int b=500;
 int i=0;int c;
  printf("Bubble or shaker:0 or 1\n");
 scanf("%d",&c);
 while(b!=0){

     b=0;
    while(i<*elementnumber-1)
    {
      if(sortingarray[i]>sortingarray[i+1]){swapping(&sortingarray[i],&sortingarray[i+1]);b++;}
      i++;
    }
    if(c==0){i=0;}
    if(c==1){do{
     if(sortingarray[i]<sortingarray[i-1]){swapping(&sortingarray[i],&sortingarray[i-1]);b++;}
      i--;}
      while(i>0);}
    }


}

void selectionsort(int *sortingarray,int *elementnumber)
{
    int i,j;i=j=0;int min;
    while(j<*elementnumber)
    {
      i=j;min=i;
      while(i<*elementnumber)
      {
        if(sortingarray[i]<sortingarray[j]&&sortingarray[i]<sortingarray[min]){min=i;}
        i++;
      }
      swapping(&sortingarray[min],&sortingarray[j]);
      j++;

    }
}

void insertionsort(int *sortingarray,int *elementnumber)
{
    int i,j;j=1;
    while(j<*elementnumber)
    {
      i=j-1;
      while(i>=0)
      {
          if(sortingarray[i]>sortingarray[i+1])
          {
              swapping(&sortingarray[i],&sortingarray[i+1]);
              i--;
          }
          else{break;}

      }
      j++;
    }
}

int main()
{
    int *sortingarray;
    int i,a,b,c;
    srand(time(NULL)*time(NULL));
    printf("Enter size of array:\n");
    scanf("%d",&a);
    sortingarray=(int) malloc(sizeof(int)*a);
    arraygenerate(sortingarray,&a);
    i=0;
    printf("What sorting mechanism?\n Bubble/shaker -1\nSelection -2\nInsertion -3");
    scanf("%d",&c);
    if(c==1){bubblesort(sortingarray,&a);}
    if(c==2){selectionsort(sortingarray,&a);}
    if(c==3){insertionsort(sortingarray,&a);}
   while(i<=a){printf("%d\t",sortingarray[i]);i++;}
    nickname();
    return 0;
}
