#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int arrivee,arriveo;
    unsigned int leavee,leaveo;
    unsigned long time;
    unsigned int expres[100000][2];
    unsigned int ordinary[100000][2];
    unsigned long i;
    unsigned int j,k,l;
    unsigned int write;
    unsigned int starte,startl,starta;
    scanf("%u%u%u%u%lu",&arrivee,&arriveo,&leavee,&leaveo,&time);
    i=j=k=l=starte=startl=write=0;
    while(i<=time)
    {
        if(i%arrivee==0)
        {
            expres[k][0]=i;
            k++;
            if(k>100000)
            {
                return 0;
            }
            write=1;
        }
        if(i%arriveo==0&&i!=0)
        {
            ordinary[l][0]=i;
            l++;
            if(l>100000)
            {
                return 0;
            }
            write=1;
        }
        if(j==0)
        {
            if(k>0)
            {
                expres[starte][1]=i-expres[starte][0];
                starte++;
                j=leavee;
            }
            else
            {
                if(l>0)
                {
                    ordinary[startl][1]=i-ordinary[startl][0];
                    startl++;
                    j=leaveo;
                }
            }
        }
        if(write==1)
        {
            write=0;
            printf("%d %d %d\n",i,k-starte,l-startl);
        }
        if(j>0)
        {
            j--;
        }
        i++;
    }
    printf("0\n");
    i=starte;
    while(i<k)
    {
        expres[i][1]=time-expres[i][0];
        i++;
    }
    i=startl;
    while(i<l)
    {
        ordinary[i][1]=time-ordinary[i][0];
        i++;
    }
    i=0;
    starte=startl=starta=0;
    while(i<k)
    {
        starta=starta+expres[i][1];
        starte=starte+expres[i][1];
        i++;
    }
    i=0;
    while(i<l)
    {
        starta=starta+ordinary[i][1];
        startl=startl+ordinary[i][1];
        i++;
    }
    printf("%u %u %u\n0\n",starte/(k),startl/(l),starta/(l+k));
    i=0;
    while(i<k)
    {
        printf("E%u %u\n",i+1,expres[i][1]);
        i++;
    }
    i=0;
    while(i<l)
    {
        printf("O%u %u\n",i+1,ordinary[i][1]);
        i++;
    }
    return 0;
}
