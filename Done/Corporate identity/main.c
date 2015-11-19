#include <stdio.h>
#include <stdlib.h>

int strdlzka(char a[])
{
    int i=0;
    while(a[i]!='\0')
    {

        i++;
    }
    return i;
}

int strvalue(char a[],char b[])
{
    int i=0;
    while(a[i]!='\0')
    {
        if(a[i]<b[i])
        {
            return 1;
        }
        if(a[i]>b[i])
        {
            return 0;
        }
        i++;
    }

    return 0;
}

char* findsubstring(char a[], char b[])
{
    int i=0;
    int k=0;
    int l=0;
    int n=0;
    while(b[i]!='\0')
    {
        i++;
    }
    int length=i;
    i=0;
    while(a[i]!='\0')
    {
        if(a[i]==b[k])
        {
            while(a[i]!='\0'&&b[k]!='\0')
            {
               if(a[i]==b[k])
               {
                   n++;
                   k++;
               }
               else
               {
                   break;
               }

               i++;


            }



        }


            if(l==0&&b[k]=='\0')
            {
                return b;
            }
            if(l>=0&&b[k]=='\0')
            {
                char *temp;
                temp=(char *) malloc(sizeof(char)*201);
                i=0;
                while(l<=k&&n)
                {
                    temp[i]=b[l];
                    n--;
                    l++;
                    i++;
                }
                temp[i]='\0';
                return temp;
            }
        i++;
        if(a[i+length-1]=='\0'&&n==0)
               {
                   l++;
                   length--;
                   k=l;
                   n=0;
               }
    }
    return NULL;
}


int main()
{
    int riadky;
    char a[4000][201];
    char *b;
    b=(char *) malloc(sizeof(char)*201);
    char *longest=NULL;
    //int pismena[2][26];
    scanf("%d",&riadky);
    while(riadky!=0)
    {
       int i=0;
       while(i<riadky)
       {
           scanf("%s",a[i]);
           i++;
       }
       int k=0;
       i=0;
       int najmensi=202;
       while(i<riadky)
       {
           while(a[i][k]!='\0')
           {
               k++;
           }
           if(najmensi>k-1)
           {
               najmensi=k;
           }
           i++;
       }
       i=k=0;

           k=0;
           int dlzka1=0;
           int dlzka2=0;
           while(a[0][dlzka1]!='\0')
           {
               dlzka1++;
           }
           while(a[1][dlzka2]!='\0')
           {
               dlzka2++;
           }
           int l,m;
           int pocet=0;
           l=m=0;
           while(i<dlzka1)
           {
               while(k<dlzka2)
               {
                   if(a[0][i]==a[1][k])
                   {
                       l=i;
                       m=k;
                       while(l<dlzka1&&m<dlzka2)
                       {
                           l++;
                           m++;
                           if(a[0][l]!=a[1][m])
                           {
                               break;
                           }
                       }
                       if(m-k>1)
                       {
                           l=0;
                           while(k<m)
                           {
                               b[l]=a[1][k];
                               l++;
                               k++;
                           }
                           b[l]='\0';
                           l=2;
                           while(l<riadky)
                           {
                               b=findsubstring(a[l],b);
                               if(b==NULL)
                               {
                                   break;
                               }
                               l++;
                           }
                           if(l==riadky)
                           {
                               if(longest==NULL)
                               {
                                   l=0;
                                   longest=(char *) malloc(sizeof(char)*201);
                                   while(b[l]!='\0')
                                   {
                                       longest[l]=b[l];
                                       l++;
                                   }
                                   longest[l]='\0';
                                   b[0]='\0';
                               }
                               else
                               {


                               int temp1=strdlzka(b);
                               int temp2=strdlzka(longest);
                               if((temp1>temp2))
                               {
                                   l=0;
                                   while(b[l]!='\0')
                                   {
                                       longest[l]=b[l];
                                       l++;
                                   }
                                   longest[l]='\0';
                                   b[0]='\0';
                               }
                               if(temp1==temp2&&strvalue(b,longest))
                               {
                                   l=0;
                                   while(b[l]!='\0')
                                   {
                                       longest[l]=b[l];
                                       l++;
                                   }
                                   longest[l]='\0';
                                   b[0]='\0';
                               }
                               }
                               l=0;
                               b[0]='\0';
                           }
                           else{
                                if(b==NULL)
                                {
                                   b=(char *) malloc(sizeof(char)*201);
                                }
                            b[0]='\0';
                           }
                           pocet++;
                       }

                   }
                   k++;
               }
               k=0;
               i++;
           }
    if(longest!=NULL)
    {printf("%s\n",longest);
    longest=NULL;}
    else{printf("IDENTITY LOST\n");}
       fgetc(stdin);
       scanf("%d",&riadky);
    }
    free(b);
    free(longest);
    return 0;
}
