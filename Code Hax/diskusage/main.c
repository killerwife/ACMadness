#include <stdio.h>
#include <stdlib.h>


typedef struct
{
   int size;
   char name[46]
} User;
// arg c,char * argv

void swappingofusers(User one,User two)
{
    User temp;
    temp=one;
    one=two;
    two=temp;

}

void selectionsort(User *sortingarray,int *elementnumber)
{
    int i,j;i=j=0;int min;
    while(j<=*elementnumber)
    {
      i=j;min=i;
      while(i<=*elementnumber)
      {
        if(sortingarray[i].size<sortingarray[j].size&&sortingarray[i].size<sortingarray[min].size){min=i;}
        i++;
      }
      swappingofusers(sortingarray[min],sortingarray[j]);
      j++;

    }
}

int main()
{
    FILE* Database;
    Database= fopen("diskusage.txt","r");
    char *DB;
    int size;
    int i=0;
    int k=0;
    int l=0;
    int m=0;
    int word;
    fseek(Database,0,SEEK_END);
    size=ftell(Database);
    fseek(Database,0,SEEK_SET);
    DB=(char*) malloc(sizeof(char)*size);
    while(i<size)
    {
        DB[i]=getc(Database);
        i++;
    }
    fclose(Database);
    i=0;
    while(i<size)
    {
        if(DB[i]=='.')
        {
            i++;
            if(DB[i]=='/')
            {
                k++;
            }
        }
        i++;
    }
    i=0;
    User * array;
    array=(User*) calloc(k,sizeof(User));
    while(i<size)
    {
      if(DB[i]>='0'&&DB[i]<='9')
      {
          array[l].size=array[l].size*10+(DB[i]-48);
      }
      if(DB[i-1]=='.'&&DB[i]=='/')
      {
         word=1;
         i++;
      }
      if(DB[i-1]=='.'&&DB[i]=='v'&&DB[i+1]=='2')
      {
          word=0;
          array[l].name[m]='\0';
          m++;
          m=0;
          l++;
      }
      if(DB[i]=='\n')
      {
          word=0;
          array[l].name[m]='\0';
          m++;
          m=0;
          l++;
      }
      if(word==1)
      {
          array[l].name[m]=DB[i];
          m++;
      }
      i++;
    }
    array[l].name[m]='\0';
    i=0;
    l=0;
    m=0;
    selectionsort(array,&k);
    while(i<k)
    {
        printf("%d",50);
        i++;
    }
    return 0;
}
