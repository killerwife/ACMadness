#include <stdio.h>
#include <stdlib.h>

int bracketscheck(char *a,int *position,int size)
{
    char parameter;
    int bugtest;
    if(a[*position]=='{'){parameter='}';}
    if(a[*position]=='['){parameter=']';}
    if(a[*position]=='('){parameter=')';}
    *position=*position+1;
    while(a[*position]!=parameter&&*position<size)
    {
        if(a[*position]=='}'||a[*position]==']'||a[*position]==')')
        {
            return 1;
        }

        if(a[*position]=='{'||a[*position]=='['||a[*position]=='(')
        {
            bugtest=bracketscheck(a,position,size);
        }


        if(bugtest==1)
           {
               return 1;
           }
       *position=*position+1;
    }
    return 0;

}

int main()
{   char *input;
    int size;
    int i=0;
    FILE* access;
    int bugtest;
     access= fopen("Input.TXT","r");
     fseek(access,0,SEEK_END);
     size=ftell(access);
     fseek(access,0,SEEK_SET);
     input=(char*) malloc(sizeof(char)*size);
     i=0;
     while(i<size)
     {
         fscanf(access,"%c",&input[i]);
         i++;
     }
     fclose(access);
     i=0;
    while(i<size)
    {
         if(input[i]=='{'||input[i]=='['||input[i]=='(')
         {
           bugtest=bracketscheck(input,&i,size);
         }
         if(bugtest==1)
           {
               return 1;
           }
        i++;
    }
    return 0;
}
