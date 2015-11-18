#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(int forest[5000][3],int k,int i)
{
    int x=forest[k][0]-forest[i][0];
    int y=forest[k][1]-forest[i][1];
    int z=forest[k][2]-forest[i][2];
    double result=sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    return result;
}

double closest(int forest[5000][3],int k,int size)
{
    double min=1000000000;
    double temp;
    int i;
    for(i=0;i<size;i++)
    {
        if(i!=k)
        {
            if((temp=distance(forest,k,i))<min)
            {
                min=temp;
            }
        }
    }
    return min;
}

int main()
{
    int x,y,z;
    int forest[5000][3];
    int result[10];
    int k;
    int i=0;
    scanf("%d%d%d",&x,&y,&z);
    while(x!=0||y!=0||z!=0)
    {
        forest[i][0]=x;
        forest[i][1]=y;
        forest[i][2]=z;
        scanf("%d%d%d",&x,&y,&z);
        i++;
    }
    for(k=0;k<10;k++)
    {
        result[k]=0;
    }
    for(k=0;k<i;k++)
    {
        double length=closest(forest,k,i);
        if(length<10)
        {
            int typing=(int)length;
            result[typing]++;
        }
    }
    for(k=0;k<10;k++)
    {
        printf("%4d",result[k]);
    }
    printf("\n");
    return 0;
}
