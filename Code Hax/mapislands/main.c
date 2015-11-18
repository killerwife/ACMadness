#include <stdio.h>
#include <stdlib.h>

int intpowa(int a, int b)
{ int result=1;
  while(b>0)
  {
      result=result*a;
      b--;

  }
  return result;
}

void searching(int **earth,int **earthcopy,int i,int j,int collumns,int rows)
{   int l,m;
    l=i;
    m=j;
    earthcopy[i][j]=1;
    if(i+1>=collumns){i=0;}
    if(earth[i+1][j]==1&&earthcopy[i+1][j]==0)
    {
        searching(earth,earthcopy,i+1,j,collumns,rows);
    }
    i=l;
    j=m;
    if(j+1>=rows)
    {j=0;}

     if(earth[i][j+1]==1&&earthcopy[i][j+1]==0)
    {
        searching(earth,earthcopy,i,j+1,collumns,rows);
    }
    i=l;
    j=m;
    if(i-1<0)
    {i=collumns-1;}

     if(earth[i-1][j]==1&&earthcopy[i-1][j]==0)
    {
        searching(earth,earthcopy,i-1,j,collumns,rows);
    }
    i=l;
    j=m;
    if(j-1<0)
    {j=rows-1;}

     if(earth[i][j-1]==1&&earthcopy[i][j-1]==0)
    {
        searching(earth,earthcopy,i,j-1,collumns,rows);
    }
}

int main()
{
    int i,j,k,l,rows,collumns,islands,display,comprimation,number,numbercopy;
    int **earth;
    int **earthcopy;
    char filename[46];
    FILE *earthmap;
    i=k=l=0;
    printf("Enter name of file:\n");
    scanf("%s",filename);
     if(fopen(filename,"r")!=NULL)
    {
        earthmap=fopen(filename,"r");
    }
    printf("Comprimation?");
    scanf("%d",&comprimation);
    fscanf(earthmap,"%d",&rows);
    printf("%d\n",rows);
    fscanf(earthmap,"%d",&collumns);
    printf("%d\n",collumns);

    earth = (int *) calloc(collumns,sizeof(int*));
    while(i<collumns)
    {
       earth[i]=(int) calloc(rows,sizeof(int));
       i++;
    }
i=j=0;
    if(comprimation==1)
    {   i=0;
        j=30;
        fscanf(earthmap,"%d",&number);
        numbercopy=number;
        while(numbercopy>0)
        {   if(intpowa(2,j)<=numbercopy)
            {   i=1;
                numbercopy=numbercopy-intpowa(2,j);
                if(i==1){earth[k][l]=1;}
            }
            else{ if(i==1){earth[k][l]=0;}}
            if(i==1){k++;if(k>=collumns){k=0;l++;}}
            j--;
        }
    }
    if(comprimation==0){
    while(j<rows )
    {
        fscanf(earthmap,"%d",&earth[i][j]);
        i++;
        if(i>=collumns)
        {
            i=0;
            j++;
        }

    }}
    i=0;
    earthcopy = (int *) calloc(collumns,sizeof(int*));
    while(i<collumns)
    {
       earthcopy[i]=(int) calloc(rows,sizeof(int));
       i++;
    }
    i=j=0;
    islands=0;
    while(j<rows)
    {   if(earth[i][j]==1&&earthcopy[i][j]==0)
        {
            searching(earth,earthcopy,i,j,collumns,rows);
            islands++;
        }
        i++;
        if(i>=collumns)
        {
            i=0;
            j++;
        }

    }
    i=j=0;
    printf("\n");
    printf("Do you want to display scanned arrays?");
    scanf("%d",&display);
    if(display==1){
    while(j<rows )
    {
        printf("%d ",earth[i][j]);
        printf("%d ",earthcopy[i][j]);
        i++;
        if(i>=collumns)
        {   printf("\n");
            i=0;
            j++;
        }

    }}
    printf("Number of islands is %d.",islands);
    free(earth);
    fclose(earthmap);
    return 0;
}
