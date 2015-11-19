#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,k,j,l,m;
    int matrix[20][20];
    int number;
    int origin;
    int destination;
    int temp;
    m=1;
    temp=-2;
    do
    {
    if(temp!=-2)
    {
        ungetc(temp,stdin);
    }
    i=k=0;
    while(i<20)
    {
        while(k<20)
        {
            matrix[i][k]=1000;
            if(i==k)
            {
                matrix[i][k]=0;
            }
            k++;
        }
        k=0;
        i++;
    }
    i=k=l=j=0;
    while(i<19)
    {
    scanf("%d",&number);
    while(number>0)
    {
        scanf("%d",&destination);
        matrix[i][destination-1]=1;
        matrix[destination-1][i]=1;
        number--;
    }
    i++;
    }
    i=k=0;
    while(k<20)
    {
        while(i<20)
        {
            while(l<20)
            {
                if(matrix[i][l]>matrix[i][k]+matrix[k][l])
                {
                    matrix[i][l]=matrix[i][k]+matrix[k][l];
                }
                l++;
            }
            l=0;
            i++;
        }
        i=0;
        k++;

    }
    k=0;
    scanf("%d",&number);
    printf("Test Set #%d\n",m);
    while(number>0)
    {
        scanf("%d",&origin);
        scanf("%d",&destination);
        printf("%2d to %2d: %d\n",origin,destination,matrix[origin-1][destination-1]);
        number--;
    }
    printf("\n");
    fgetc(stdin);
    m++;
    }
    while((temp=fgetc(stdin))!=EOF);
    return 0;
}
