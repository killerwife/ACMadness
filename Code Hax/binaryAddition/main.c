#include <stdio.h>
#include <stdlib.h>

void pricitanie(int vysledok[],int i)
{
    i=i-1;
    while(i>=0)
    {
        if(vysledok[i]>1&&vysledok[i]%2==1)
        {
            vysledok[i-1]=vysledok[i-1]+vysledok[i]/2;
            vysledok[i]=1;
        }
        if(vysledok[i]>1&&vysledok[i]%2==0)
        {
            vysledok[i-1]=vysledok[i-1]+vysledok[i]/2;
            vysledok[i]=0;
        }
        i--;
    }
}

int *binarnescitanie(int cislo1[], int cislo2[],int velkost1, int velkost2)
{
    int *vysledok;
    int i=velkost1;
    int l=velkost1-1;
    int k=velkost2-1;
    if(velkost1==velkost2)
    {
        vysledok=(int*) calloc((velkost1+2),sizeof(int));
        i++;
    }
    else
    {
        vysledok=(int*) calloc((velkost1+1),sizeof(int));
    }
    while(i>0)
    {
        if(k>=0&&l>=0)
        {
            vysledok[i]=cislo1[l]+cislo2[k];
        }
        if(k<0&&l>=0)
        {
            vysledok[i]=cislo1[l];
        }
        i--;
        k--;
        l--;
    }
    if(velkost1==velkost2)
    {
        pricitanie(vysledok,velkost1+2);
    }
    else
    {
        pricitanie(vysledok,velkost1+1);
    }
    return vysledok;
}


int main()
{
    int *p;
    char vstup[253];
    int i=0;
    int *cislo1;
    int *cislo2;
    int velkost;
    int velkost1=0;
    int velkost2=0;
    int pocitadlo=0;
    printf("Zadejte dve binarni cisla:\n");
    fgets(vstup,253,stdin);
    while(i<253)
    {
        if(vstup[i]=='\n'&&pocitadlo!=1)
        {
            printf("Nespravny vstup.");
            return 1;
        }
        if(vstup[i]=='\n'&&pocitadlo==1)
        {
            break;
        }
        if(vstup[i]!='1'&&vstup[i]!='0'&&vstup[i]!=' ')
        {
            printf("Nespravny vstup.");
            return 1;
        }
        if(vstup[i]==' ')
        {
            pocitadlo++;
        }
        if(pocitadlo==0)
        {
            velkost1++;
        }
        if(pocitadlo==1&&vstup[i-1]!=' ')
        {
            velkost2++;
        }
        i++;
    }
    i=0;
    cislo1=(int *) malloc(sizeof(int)*velkost1);
    cislo2=(int *) malloc(sizeof(int)*velkost2);
    while(i<velkost1)
    {
        if(vstup[i]==49)
        {cislo1[i]=1;}
        else
        {
            cislo1[i]=0;
        }
        i++;
    }
    i=0;
    while(i<velkost2)
    {
         if(vstup[i+velkost1+1]==49)
        {cislo2[i]=1;}
        else
        {
            cislo2[i]=0;
        }
        i++;
    }
    if(velkost1<velkost2)
    {
        int *temp;
        int trololo;
        temp=cislo1;
        cislo1=cislo2;
        cislo2=temp;
        trololo=velkost1;
        velkost1=velkost2;
        velkost2=trololo;
    }
    p=binarnescitanie(cislo1,cislo2,velkost1,velkost2);
    if(velkost1==velkost2)
    {
        velkost=velkost1+2;
    }
    else
    {
        velkost=velkost1+1;
    }
    i=0;
    printf("Soucet: ");
    while(i<velkost)
    {
        int pocitadlo;
        if(p[i]!=0||pocitadlo==1)
        {
            printf("%d",p[i]);
            pocitadlo=1;
        }

        i++;
    }
    if(velkost1==1&&cislo1[0]==0&&cislo2[0]==0)
    {
        printf("0");
    }
    free(cislo1);
    free(cislo2);
    free(p);
    return 0;
}
