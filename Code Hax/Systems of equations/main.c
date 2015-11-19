#include <stdio.h>
#include <stdlib.h>

void multiplyarray(double *p,double a, double b,int length)
{
    while(length>0)
    {
        p[length-1]=p[length-1]*a/b;
        length--;
    }
}

int main()
{   int collumns,rows;
    int i=0;int k=0;
    FILE * Subor;
    Subor=fopen("Subor.txt","r");
    fscanf(Subor,"%d",&collumns);
     fscanf(Subor,"%d",&rows);
    double **matrix;
    matrix=(double**) malloc(sizeof(double*)*rows);
    while(i<collumns)
    {
        matrix[i]=(double*) malloc(sizeof(double)*collumns);
        i++;
    }
    i=0;
    while(k<rows)
    {
        i=0;
        while(i<collumns)
        {
            fscanf(Subor,"%lf",&matrix[k][i]);
            printf("%lf\t",matrix[k][i]);
            i++;
        }
        printf("\n");
        k++;
    }
    k=1;
    i=0;
    int a;
    int usedrow;
    int l,m;
    int offset;
    offset=0;
    l=m=0;
    usedrow=0;
    double *temp;
    while(usedrow<rows-1)
    {
        if(matrix[k][offset]!=0)
        {
            multiplyarray(matrix[k],matrix[usedrow][offset],matrix[k][offset],collumns);
             l=offset;
             while(l<collumns)
             {

                 matrix[k][l]= matrix[usedrow][l]-matrix[k][l];
                 l++;
             }

             k++;

        }

       if(matrix[k][offset]==0&&k<rows-1)
       {
           m=k;
           while(matrix[m][offset]==0)
           {

               m++;
           }
           temp=matrix[k];
           matrix[k]=matrix[m];
           matrix[m]=temp;
       }
        if(k>=rows)
        {
            usedrow++;
            offset++;
            k=usedrow+1;
        }
    }
    k=i=0;
    while(k<rows)
    {
        i=0;
        while(i<collumns)
        {
            printf("%lf\t",matrix[k][i]);
            i++;
        }
        printf("\n");
        k++;
    }
    double *p;
    double variable;
    i=collumns-2;
    k=rows-1;
    p=(double*) malloc(sizeof(double)*(collumns-1));
    while(k>=0)
    {
        l=i+1;
        variable=matrix[k][collumns-1];
        while(l<collumns-1)
        {
            variable=variable-matrix[k][l]*p[l];
            l++;
        }
        if(matrix[k][i]!=0){
        p[i]=variable/matrix[k][i];}
        i--;
        k--;
    }
    i=0;
    while(i<collumns-1)
    {
        printf("%lf\t",p[i]);
        i++;
    }
    free(matrix);
    return 0;
}
