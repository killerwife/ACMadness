#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    int c,d;
    int i,k;
    int depth;
    int verticestack[25];
    int stackcounter[25];
    int matrix[25][25];
    int tempmatrix[25][25];
    scanf("%d%d",&a,&b);
    while(a!=0&&b!=0)
    {
        i=k=0;
        while(i<25)
        {
            while(k<25)
            {
                matrix[i][k]=0;
                tempmatrix[i][k]=0;
                k++;
            }
            stackcounter[i]=0;
            verticestack[i]=-1;
            k=0;
            i++;
        }
        i=0;
        while(i<b)
        {
            scanf("%d%d",&c,&d);
            matrix[c][d]=1;
            matrix[d][c]=1;
            i++;
        }
        i=0;
        depth=0;
        while(i<a)
        {
            verticestack[k]=i;
            stackcounter[k]=0;
            do
            {
                if((matrix[verticestack[k]][stackcounter[k]]==1)&&(tempmatrix[verticestack[k]][stackcounter[k]]!=1))
                {
                    k++;
                    verticestack[k]=stackcounter[k-1];
                    tempmatrix[verticestack[k-1]][verticestack[k]]=1;
                  tempmatrix[verticestack[k]][verticestack[k-1]]=1;
                    stackcounter[k-1]++;
                    if(depth<k)
                    {
                        depth=k;
                    }
                }
                else
                {stackcounter[k]++;}
                while(k>0&&stackcounter[k]>=a+1)
                {
                    tempmatrix[verticestack[k-1]][verticestack[k]]=0;
                    tempmatrix[verticestack[k]][verticestack[k-1]]=0;
                    verticestack[k]=0;
                    stackcounter[k]=0;
                    k--;
                }
            }
            while((k==0&&stackcounter[k]<a+1)||(k<a+1&&stackcounter[k]<a+1));
            i++;
        }
        printf("%d\n",depth);
        scanf("%d%d",&a,&b);
    }
    return 0;
}
