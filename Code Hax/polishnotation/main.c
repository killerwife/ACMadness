#include <stdio.h>
#include <stdlib.h>

int main()
{   int a,i,k,num;
    int *stack;
    int size;
    char *input;
    printf("1 for input mode\n0 for file mode");
    scanf("%d",&a);
    if(a==1)
    {
        size = 100;
    input=(char*) malloc(sizeof(char)*size);
    scanf("%s",input);
    }
    if(a==0)
    {
     FILE* access;
     access= fopen("Input.TXT","r");
     fseek(access,0,SEEK_END);
     size=ftell(access);
     fseek(access,0,SEEK_SET);
     input=(char*) malloc(sizeof(char)*size);
     i=0;
     while(i<size)
     {
         fscanf(access,"%c",input[i]);
         i++;
     }
     fclose(access);
    }
    i=0;
    k=0;
    while(i<size)
    {
      if(input[i]>='0'&&input[i]<='9'&&num==0)
      {
          k++; num=1;
      }
      if(input[i]==' ')
      {
          num=0;
      }
      i++;
    }
    stack=(int*) calloc(k+1,sizeof(int));
    i=0;
    stack[0]=1;
    while(i<size)
    {
       if(input[i]=='1')
       {
         stack[stack[0]]= stack[stack[0]]*10+1;

       }
       if(input[i]=='2')
       {
         stack[stack[0]]= stack[stack[0]]*10+2;
       }
       if(input[i]=='3')
       {
         stack[stack[0]]= stack[stack[0]]*10+3;
       }
       if(input[i]=='4')
       {
         stack[stack[0]]= stack[stack[0]]*10+4;
       }
       if(input[i]=='5')
       {
         stack[stack[0]]= stack[stack[0]]*10+5;
       }
       if(input[i]=='6')
       {
         stack[stack[0]]= stack[stack[0]]*10+6;
       }
       if(input[i]=='7')
       {
         stack[stack[0]]= stack[stack[0]]*10+7;
       }
       if(input[i]=='8')
       {
         stack[stack[0]]= stack[stack[0]]*10+8;
       }
       if(input[i]=='9')
       {
         stack[stack[0]]= stack[stack[0]]*10+9;
       }
       if(input[i]=='0')
       {
         stack[stack[0]]*10;
       }
       if(input[i]=='+')
       {
         if(input[i-1]==' ')
         {
             stack[0]--;
         }
         stack[stack[0]-1]=stack[stack[0]-1]+stack[stack[0]];
         stack[0]--;
       }
       if(input[i]=='-')
       {
           if(input[i-1]==' ')
         {
             stack[0]--;
         }
         stack[stack[0]-1]=stack[stack[0]-1]-stack[stack[0]];
         stack[0]--;
       }
       if(input[i]=='*')
       {
           if(input[i-1]==' ')
         {
             stack[0]--;
         }
         stack[stack[0]-1]=stack[stack[0]-1]*stack[stack[0]];
         stack[0]--;
       }
       if(input[i]=='/')
       {
           if(input[i-1]==' ')
         {
             stack[0]--;
         }
         stack[stack[0]-1]=stack[stack[0]-1]/stack[stack[0]];
         stack[0]--;
       }
       if(input[i]==' ')
       {
           stack[0]++;
       }

       i++;
    }
    if(stack[0]==0)
    {
       return 1;
    }
    printf("%d",stack[1]);
    return 0;
}
