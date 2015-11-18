#include <stdio.h>
#include <stdlib.h>

int nasobky(int x[101], int y[50], int pocet, int k)
{   int i;
    i=0;
    while(pocet>0){if(x[pocet]%k==0){y[i]=x[pocet];i++;}pocet--;}


    return i;
}



int main()
{
    int array1[101];
    int array2[50];
    int i;i=0;
    while(i<100){array1[i]=i+1;i++;}
    int a;
    scanf("%d",&a);
    printf("%d",nasobky(&array1,&array2,100,a));

    return 0;
}
