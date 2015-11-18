#include <stdio.h>
#include <stdlib.h>

int depthSearching(int matrix[100][100],int numofpoints,int excludedpoint)
{
    int used[100];
    int i;
    int stack[100];
    int counters[100];
    for(i=0;i<100;i++)
    {
        used[i]=0;
        counters[i]=0;
        stack[i]=0;
    }
    i=0;
    stack[0]=excludedpoint!=0 ? 0 : 1;
    used[stack[0]]=1;
    while(i>=0)
    {
        if(counters[stack[i]]!=excludedpoint)
        {
            if(matrix[stack[i]][counters[stack[i]]]==1&&used[counters[stack[i]]]==0)
            {
                used[counters[stack[i]]]=1;
                stack[i+1]=counters[stack[i]];
                counters[stack[i]]++;
                i++;
            }
        }
        counters[stack[i]]++;
        if(counters[stack[i]]>=numofpoints)
        {
            i--;
        }
    }
    for(i=0;i<numofpoints;i++)
    {
        if(used[i]!=1&&i!=excludedpoint)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int points;
    scanf("%d",&points);
    while(points!=0)
    {
        int i,k;
        int a,b;
        char temp;
        int numofcrit=0;
        int matrix[100][100];
        a=1;
        for(i=0;i<100;i++)
        {
            for(k=0;k<100;k++)
            {
                matrix[i][k]=0;
            }
        }
        while(a!=0)
        {
            scanf("%d",&a);
            while((temp=fgetc(stdin))!='\n')
            {
                scanf("%d",&b);
                matrix[a-1][b-1]=1;
                matrix[b-1][a-1]=1;
            }
        }
        for(i=0;i<points;i++)
        {
            int iscritical=depthSearching(matrix,points,i);
            if(iscritical==1)
            {
                numofcrit++;
            }
        }
        printf("%d\n",numofcrit);
        scanf("%d",&points);
    }
    return 0;
}
