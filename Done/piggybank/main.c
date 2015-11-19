#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cases;
    scanf("%d",&cases);
    while(cases>0)
    {
        int piggy,total;
        int numofcoins;
        int coins[501][2];
        int states[10001];
        int k,l;
        int actual;
        scanf("%d%d%d",&piggy,&total,&numofcoins);
        for(k=0;k<numofcoins;k++)
        {
            scanf("%d%d",&coins[k][0],&coins[k][1]);
        }
        states[0]=0;
        for(k=1;k<10001;k++)
        {
            states[k]=1000000000;
        }
        actual=total-piggy;
        for(k=1;k<=actual;k++)
        {
            for(l=0;l<numofcoins;l++)
            {
               if(k-coins[l][1]>=0)
               {
                   if(states[k-coins[l][1]]+coins[l][0]<states[k])
                   {
                       states[k]=states[k-coins[l][1]]+coins[l][0];
                   }
               }
            }
        }
        if(states[actual]==1000000000)
        {

            printf("This is impossible.\n");
        }
        else
        {printf("The minimum amount of money in the piggy-bank is %d.\n",states[actual]);}
        cases--;
    }
    return 0;
}
