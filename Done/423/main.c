#include <stdio.h>
#include <stdlib.h>

int intpow(int a, int b)
{
    int i=0;
    int result=1;
    while(i<b)
    {
        result=result*a;
        i++;
    }
    return result;
}

int main()
{
    int sizeofmatrix;
    scanf("%d",&sizeofmatrix);
        fgetc(stdin);
    int **matrixoftimes;
    int tempchar;
    matrixoftimes=(int**) malloc(sizeof(int*)*(sizeofmatrix));

    int i=0;
    while(i<sizeofmatrix)
    {
        matrixoftimes[i]=(int*) malloc(sizeof(int)*(sizeofmatrix));
    i++;
    }
    int k=0;
    i=1;
    while(i<sizeofmatrix)
    {
        while(k<=i-1)
        {
            if((tempchar=fgetc(stdin))=='x')
            {
                matrixoftimes[i][k]=999999999;
                matrixoftimes[k][i]=999999999;
                fgetc(stdin);
            }
            else
            {
                matrixoftimes[i][k]=0;
                while(tempchar!=' '&&tempchar!='\n')
                {
                    matrixoftimes[i][k]=matrixoftimes[i][k]*10+(tempchar-'0');
                    tempchar=fgetc(stdin);
                }
                matrixoftimes[k][i]=matrixoftimes[i][k];
            }

            /*printf("%d ",matrixoftimes[i][k]);*/
            k++;
        }
        /*printf("\n");*/
        k=0;
        i++;
    }
    i=0;
    while(i<sizeofmatrix)
    {
        matrixoftimes[i][i]=0;
        i++;
    }
    /*i=0;
    k=0;
    while(i<sizeofmatrix)
    {
        while(k<sizeofmatrix)
        {
            printf("%10d ",matrixoftimes[i][k]);
            k++;
        }
        printf("\n");
        k=0;
        i++;
    }*/
    k=0;
    i=1;
    int l=0;
    while(i<sizeofmatrix)
    {
        while(k<sizeofmatrix)
        {
            while(l<sizeofmatrix)
            {
                if(matrixoftimes[k][i]+matrixoftimes[i][l]<matrixoftimes[k][l])
                {
                    matrixoftimes[k][l]=matrixoftimes[k][i]+matrixoftimes[i][l];
                }

                l++;
            }
            l=0;
            k++;
        }
        k=0;
        i++;
    }
   /* i=0;
    k=0;
    while(i<sizeofmatrix)
    {
        while(k<sizeofmatrix)
        {
            printf("%10d ",matrixoftimes[i][k]);
            k++;
        }
        printf("\n");
        k=0;
        i++;
    }*/
    i=0;
    int maximum=0;
    while(i<sizeofmatrix)
    {
        if(matrixoftimes[i][0]>maximum)
        {
            maximum=matrixoftimes[i][0];
        }
        i++;
    }
    printf("%d\n",maximum);
    free(matrixoftimes);
    return 0;
}
