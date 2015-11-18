#include <stdio.h>
#include <stdlib.h>

int main()
{
    int heads,knights;
    scanf("%d%d",&heads,&knights);
    while(heads!=0&&knights!=0)
    {
        long i,k;
        long headDia[20001];
        long knightHei[20001];
        for(i=0;i<heads;i++)
        {
            scanf("%ld",&headDia[i]);
        }
        for(k=0;k<knights;k++)
        {
            scanf("%ld",&knightHei[k]);
        }
        if(knights<heads)
        {
            printf("Loowater is doomed!\n");
        }
        else
        {
            int check=0;
            int salary=0;
            for(i=0;i<heads;i++)
            {
                int maxHead=-1;
                int bestKnight=-1;
                for(k=0;k<heads;k++)
                {
                    if(headDia[k]>0)
                    {
                        maxHead=k;
                        break;
                    }
                }
                for(;k<heads;k++)
                {
                    if(headDia[k]>headDia[maxHead])
                    {
                        maxHead=k;
                    }
                }
                for(k=0;k<knights;k++)
                {
                    if(knightHei[k]>=headDia[maxHead])
                    {
                        bestKnight=k;
                        break;
                    }
                }
                if(bestKnight==-1)
                {
                    check=1;
                    break;
                }
                for(;k<knights;k++)
                {
                    if(knightHei[k]>=headDia[maxHead]&&knightHei[k]<knightHei[bestKnight])
                    {
                        bestKnight=k;
                    }
                }
                salary+=knightHei[bestKnight];
                knightHei[bestKnight]=0;
                headDia[maxHead]=0;

            }
            if(check==0)
            {
                printf("%d\n",salary);
            }
            else
            {
                printf("Loowater is doomed!\n");
            }
        }
        scanf("%d%d",&heads,&knights);
    }
    return 0;
}
