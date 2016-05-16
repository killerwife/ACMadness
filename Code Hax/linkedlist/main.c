#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mesiace[] = {31,29,31,30,31,30,31,31,30,31,30,31};

typedef struct
{
    char value[50]; // treba asi dynamicky meno nezabudni na uvolnenie
    struct Meno* dalsi;
} Meno;

void vlozDoPola(int den,int mesiac,char meno[50],Meno*** pole)
{
    if(mesiac>12||mesiac<1)
    {
        return;
    }
    mesiac--;
    if(mesiace[mesiac]<den||den<0)
    {
        return;
    }
    den--;
    Meno* novy=(Meno*) malloc(sizeof(Meno));
    memcpy(novy->value,meno,sizeof(char)*50);
    vlozDoZoznamu(&pole[mesiac][den],novy);
}

void vlozDoZoznamu(Meno** prvok,Meno* novy)
{
    novy->dalsi=*prvok;
    *prvok=novy;
}

void vypisPole(Meno*** pole)
{
    int i,k;
    for(i=0; i<12; i++)
    {
        for(k=0; k<mesiace[i]; k++)
        {
            printf("Mena pre datum %d. %d.: ",k+1,i+1);
            vypisZoznam(pole[i][k]);
            printf("\n");
        }
    }
}

void vypisZoznam(Meno* prvok)
{
    while(prvok!=NULL)
    {
        printf("%s,",prvok->value);
        prvok=prvok->dalsi;
    }
}

int main(int argc, char* argv[])
{
    Meno*** pole=(Meno***)malloc(sizeof(Meno**)*12);
    int i,k;
    int mesiac, den;
    char meno[50];
    FILE* vstup=fopen("data.txt","r");
    for(i=0; i<12; i++)
    {
        pole[i]=(Meno**) malloc(sizeof(Meno*)*mesiace[i]);

        for(k=0; k<mesiace[i]; k++)
        {
            pole[i][k]=0;
        }
    }
    if(vstup!=NULL)
    {
        while(fscanf(vstup,"%d%d",&mesiac,&den)!=EOF)
        {
            if(mesiac==den&&mesiac==0)
            {
                break;
            }
            fgets(meno,50,vstup);
            for(i=0;i<50;i++)
            {
                if(meno[i]=='\n')
                {
                    meno[i]='\0';
                    break;
                }
            }
            if(den==12&&mesiac==12)
            {
                printf("bla");
            }
            vlozDoPola(den,mesiac,meno,pole);
        }
        fclose(vstup);
    }
    vypisPole(pole);
    for(i=0; i<12; i++)
    {
        for(k=0; k<mesiace[i]; k++)
        {
            Meno* temp=pole[i][k];
            while(temp!=NULL)
            {
                Meno* predosly=temp;
                temp=temp->dalsi;
                free(predosly);
            }
        }
        free(pole[i]);
    }
    free(pole);
    return 0;
}
