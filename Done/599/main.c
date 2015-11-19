#include <stdio.h>
#include <stdlib.h>

int main()
{
    int checkline;
    int graph[26][26];
    int temp1;
    int temp2;
    int beenthere[26];
    int verticestack[26];
    int i,k,l,n,m;
    int acorns=0;
    int trees=0;
    int checker=0;
    int verticescounter[26];
    int letters[26];
    int a;
    int edges[650][2];
    scanf("%d",&a);
    fgetc(stdin);
    i=k=m=n=l=0;
    while(i<26)
    {
        while(k<26)
        {
            graph[i][k]=0;
            k++;
        }
        k=0;
        i++;
    }
    i=k=0;
    while(a>0)
    {
        m=0;
        while((checkline=fgetc(stdin))!='*')
        {
            temp1=fgetc(stdin);
            fgetc(stdin);
            temp2=fgetc(stdin);
            fgetc(stdin);
            fgetc(stdin);
            edges[m][0]=temp1;
            edges[m][1]=temp2;
            m++;
          /*  graph[temp1-'A'][temp2-'A']=1;
            graph[temp2-'A'][temp1-'A']=1;*/
        }
        while((checkline=fgetc(stdin))=='*');
        do
        {
            letters[i]=fgetc(stdin);
            i++;
        }
        while((checkline=fgetc(stdin))!='\n');
        while(k<26)
        {
            verticescounter[k]=0;
            k++;
        }
        n=l=0;
        while(n<m)
        {
            while(edges[n][0]!=letters[l])
            {
                l++;
            }
            temp1=l;
            l=0;
            while(edges[n][1]!=letters[l])
            {
                l++;
            }
            temp2=l;
            l=0;
            graph[temp1][temp2]=1;
            graph[temp2][temp1]=1;
            n++;
        }
        l=k=0;
       /* while(l<26)
        {
            while(k<26)
            {
                if(graph[l][k]!=1)
                {
                    printf("0 ");
                }
                else
                {
                    printf("1 ");
                }
                k++;
            }
            printf("\n");
            k=0;
            l++;
        }*/
        k=0;
        m=-1;
        while(k<i)
        {
            if(beenthere[k]!=1||verticescounter[k]<i)
            {
                beenthere[k]=1;
                while(verticescounter[k]<i&&(graph[k][verticescounter[k]]!=1||beenthere[verticescounter[k]]==1))
                {
                    verticescounter[k]++;
                }
                if(beenthere[verticescounter[k]]!=1&&verticescounter[k]<i)
                {
                    m++;
                    verticestack[m]=k;
                    checker=1;
                    k=verticescounter[k];
                }
                else
                {
                    if(m==-1)
                    {
                        if(checker==0)
                        {
                            acorns++;
                        }
                        else
                        {
                            checker=0;
                            trees++;
                        }
                    }
                    else
                    {
                        k=verticestack[m];
                        m--;
                    }
                }
            }
            else
            {
                k++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n",trees,acorns);
        k=0;
        m=-1;
        acorns=0;
        trees=0;
        checker=0;
        i=0;
        while(i<26)
        {
            beenthere[i]=0;
            i++;
        }
        i=0;
        a--;
        i=k=0;
        while(i<26)
        {
            while(k<26)
            {
                graph[i][k]=0;
                k++;
            }
            k=0;
            i++;
        }
        i=k=0;
    }
    return 0;
}
