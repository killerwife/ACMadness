#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cases;
    int starsys[1000][2];
    int wormholes[2000][3];
    int sys,hole;
    int i,k;
    scanf("%d",&cases);
    while(cases>0)
    {
        scanf("%d%d",&sys,&hole);
        i=0;
        while(i<hole)
        {
            scanf("%d%d%d",&wormholes[i][0],&wormholes[i][1],&wormholes[i][2]);
            i++;
        }
        starsys[0][0]=0;
        starsys[0][0]=0;
        i=1;
        while(i<sys)
        {
            starsys[i][0]=10000000;
            starsys[i][1]=-1;
            i++;
        }
        i=0;
        k=0;
        while(i<sys)
        {
            while(k<hole)
            {
                if(starsys[wormholes[k][0]][0]+wormholes[k][2]<starsys[wormholes[k][1]][0])
                {
                    starsys[wormholes[k][1]][0]=starsys[wormholes[k][0]][0]+wormholes[k][2];
                    starsys[wormholes[k][1]][1]=wormholes[k][0];
                }
                k++;
            }
            k=0;
            i++;
        }
        k=0;
        while(k<hole)
        {
            if(starsys[wormholes[k][0]][0]+wormholes[k][2]<starsys[wormholes[k][1]][0])
            {
                printf("possible\n");
                k=-1;
                break;
            }
            k++;
        }
        if(k!=-1)
        {
            printf("not possible\n");
        }
        cases--;
    }
    return 0;
}
