#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pictureA[1024];
    int pictureB[1024];
    char current;
    int cases;
    scanf("%d",&cases);
    fgetc(stdin);
    for(;cases>0;cases--)
    {
        int multiplier=1024;
        int i;
        int hlbka=0;
        int k[6];
        int blackpix=0;
        for(i=0;i<6;i++)
        {
            k[i]=0;
        }
        i=0;
        while((current=fgetc(stdin))!='\n')
        {
            if(current=='p')
            {
                multiplier/=4;
                hlbka++;
            }
            else if(current=='f')
            {
                int l;
                for(l=0;l<multiplier;l++)
                {
                    pictureA[i]=1;
                    i++;
                }
                k[hlbka]++;
            }
            else
            {
                int l;
                for(l=0;l<multiplier;l++)
                {
                    pictureA[i]=0;
                    i++;
                }
                k[hlbka]++;
            }
            while(k[hlbka]>3)
            {
                k[hlbka]=0;
                multiplier*=4;
                hlbka--;
                k[hlbka]++;
            }
        }
        multiplier=1024;
        hlbka=0;
        for(i=0;i<6;i++)
        {
            k[i]=0;
        }
        i=0;
        while((current=fgetc(stdin))!='\n'&&current!=EOF)
        {
            if(current=='p')
            {
                multiplier/=4;
                hlbka++;
            }
            else if(current=='f')
            {
                int l;
                for(l=0;l<multiplier;l++)
                {
                    pictureB[i]=1;
                    i++;
                }
                k[hlbka]++;
            }
            else
            {
                int l;
                for(l=0;l<multiplier;l++)
                {
                    pictureB[i]=0;
                    i++;
                }
                k[hlbka]++;
            }
            while(k[hlbka]>3)
            {
                k[hlbka]=0;
                multiplier*=4;
                hlbka--;
                k[hlbka]++;
            }
        }
        for(i=0;i<1024;i++)
        {
            if(pictureA[i]==1||pictureB[i]==1)
            {
                blackpix++;
            }
        }
        printf("There are %d black pixels.\n",blackpix);
    }
    return 0;
}
