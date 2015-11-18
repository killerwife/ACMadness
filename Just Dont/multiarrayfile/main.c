#include <stdio.h>
#include <stdlib.h>

int main()
{   int i,collumns,rows,type,l,k,range,display;
    char n;
     char nameoffile[46];
    i=l=0;
    k=0;
    srand(time(NULL)*time(NULL));
    printf("Write 0 or read 1\n");
    scanf("%d",&type);
    printf("Name of file?");
     scanf("%s",nameoffile);
    int **z;
    FILE *example;

    if(type==0)
    {

     printf("Size of generated array?");
     scanf("%d%d",&collumns,&rows);
     printf("Range of generated numbers? 1-");
     scanf("%d",&range);

     example= fopen(nameoffile,"w");
    z= (int **) malloc(sizeof(int*)*collumns);
    while(i<collumns)
    {
        z[i]= (int *) malloc(sizeof(int)*rows);
        i++;
    }
    i=0;
    fprintf(example,"%d %d \n",rows,collumns);
    while(i<rows)
    {
        while(l<collumns)
        {
            z[l][i]=rand()%range;
            fprintf(example,"%d ",z[l][i]);
            l++;
        }
        fprintf(example,"\n");
        l=0;
        i++;
    }

    }
    if(type==1)
    {
    example= fopen(nameoffile,"r");
    fscanf(example,"%d%d",rows,collumns);
    z= (int **) malloc(sizeof(int*)*collumns);
    while(i<collumns)
    {
        z[i]= (int *) malloc(sizeof(int)*rows);
        i++;
    }
    i=0;
    while(i<rows)
    {

        fscanf(example,"%d",&z[l][i]);
        l++;
        if(l>=collumns){l=0;i++;}


    }
    }
    i=l=0;
    printf("Do you want to display generated/scanned array?");
    scanf("%d",&display);
    if(display==1){
    printf("     ");
    while(i<collumns)
    {
        printf("%5d ",i+1);
        i++;
    }
    printf("\n");
    i=0;
    while(i<rows)
    {      printf(" %5d ",i+1);
        while(l<collumns)
        {
            printf("%5d ",z[l][i]);
            l++;

        }
        printf("\n");
        l=0;
        i++;
    }}
    free(z);
    fclose(example);
    return 0;
}
