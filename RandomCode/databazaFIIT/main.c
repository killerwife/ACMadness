#include <stdio.h>
#include <stdlib.h>

typedef struct
{
char Krajina[31];
char Miesto[31];
char Hotel[31];
int Kategoria;
double Cena;
int Datum;
int PocetDni;
}CestovnaDestinacia;

void myflush ( FILE *in )
{
  int ch;

  do
    ch = fgetc ( in );
  while ( ch != EOF && ch != '\n' );

  clearerr ( in );
}


int porovnanieslov(char prveslovo[], char druheslovo[], int i)
{
int vysledok=0;
if(prveslovo[i]=='\0')
{return 1;}
if(prveslovo[i]==druheslovo[i])
{vysledok=porovnanieslov(prveslovo,druheslovo,i+1);}
if(prveslovo[i]<druheslovo[i])
{vysledok=1;}
return vysledok;
}

void copystring(char slovo1[], char slovo2[])
{
int i=0;
while(i<31)
{
slovo2[i]=slovo1[i];
i++;
}
}

void swapping(char slovo1[],char slovo2[])
{
char *temp;
temp=(char *) malloc(sizeof(char)*31);
copystring(slovo1,temp);
copystring(slovo2,slovo1);
copystring(temp,slovo2);
free(temp);
}

void selectionsort(char **databaza,int size)
{
int i=0;
int k=1;
int min=0;
while(i<size)
{
while(k<size)
{
if(porovnanieslov(databaza[k],databaza[min],0)==1)
{min=k;}
k++;
}
swapping(databaza[i],databaza[min]);
i++;
min=i;
k=i+1;
}
}

int main()
{
int i=0;
char pocitacistring[31];
int pocitaciint;
double pocitaciacena;
double *pole=NULL;
FILE *vstup;
if(fopen("zajazdy.txt","r")!=NULL)
{
    vstup=fopen("zajazdy.txt","r");
}
else
{
    printf("Neotvoreny subor.");
    return 1;
}
do
{
/*fscanf(vstup,"%s",&pocitacistring);
fscanf(vstup,"%s",&pocitacistring);
fscanf(vstup,"%s",&pocitacistring);
fscanf(vstup,"%d",&pocitaciint);
fscanf(vstup,"%lf",&pocitaciacena);
fscanf(vstup,"%d",&pocitaciint);
fscanf(vstup,"%d",&pocitaciint);*/
fgets(pocitacistring,31,vstup);
if(pocitacistring[0]=='\n')
{
    fgets(pocitacistring,31,vstup);
}
fgets(pocitacistring,31,vstup);
fgets(pocitacistring,31,vstup);
fscanf(vstup,"%d",&pocitaciint);
fscanf(vstup,"%lf",&pocitaciacena);
fscanf(vstup,"%d",&pocitaciint);
fscanf(vstup,"%d",&pocitaciint);
i++;
}
while(getc(vstup)!=EOF);
int size=i;
CestovnaDestinacia *databaza;
databaza=(CestovnaDestinacia *) malloc(sizeof(CestovnaDestinacia)*size);
fseek(vstup,0,SEEK_SET);
i=0;
do
{
/*fscanf(vstup,"%s",databaza[i].Krajina);
fscanf(vstup,"%s",databaza[i].Miesto);
fscanf(vstup,"%s",databaza[i].Hotel);
fscanf(vstup,"%d",&databaza[i].Kategoria);
fscanf(vstup,"%lf",&databaza[i].Cena);
fscanf(vstup,"%d",&databaza[i].Datum);
fscanf(vstup,"%d",&databaza[i].PocetDni);*/
fgets(databaza[i].Krajina,31,vstup);
if(databaza[i].Krajina[0]=='\n')
{
    fgets(databaza[i].Krajina,31,vstup);
}
fgets(databaza[i].Miesto,31,vstup);
fgets(databaza[i].Hotel,31,vstup);
fscanf(vstup,"%d",&databaza[i].Kategoria);
fscanf(vstup,"%lf",&databaza[i].Cena);
fscanf(vstup,"%d",&databaza[i].Datum);
fscanf(vstup,"%d",&databaza[i].PocetDni);
i++;
}
while(getc(vstup)!=EOF);
i=0;
char mod='a';
while(mod!='k')
{

printf("Zadajte parameter programu:\n");

scanf("%c",&mod);
i=0;
if(mod=='v')
{
while(size>i)
{
printf("Krajina: %s",databaza[i].Krajina);
printf("Miesto: %s",databaza[i].Miesto);
printf("Hotel: %s",databaza[i].Hotel);
int k;
printf("Kategoria: ");
for(k=0;k<databaza[i].Kategoria;k++)
{printf("*");}
printf("\n");
printf("Cena: %.2lf\n",databaza[i].Cena);
printf("Datum: %08d\n",databaza[i].Datum);
printf("Pocet dni: %d\n",databaza[i].PocetDni);
printf("\n");
i++;
}
i=0;
}
if(mod=='n')
{
double vysledok=0;
while(size>i)
{
if(databaza[i].Kategoria==5&&(databaza[i].Cena/databaza[i].PocetDni<vysledok||vysledok==0))
{vysledok=databaza[i].Cena/databaza[i].PocetDni;}
i++;
}
printf("%lf\n",vysledok);
}
if(mod=='c')
{
if(pole!=NULL)
{
    free(pole);
}
pole=(double *) malloc(sizeof(double)*size);

while(i<size)
{
pole[i]=databaza[i].Cena;
i++;
}}
if(mod=='r')
{
if(pole==NULL)
{
printf("Pole nie je vytvorene.\n");
continue;
}
i=0;
while(i<size)
{
printf("%7.2lf\n",pole[i]);
i++;
}
if(pole!=NULL){
free(pole);}}
if(mod=='h')
{
int *histogram;
histogram=(int *) calloc(31,sizeof(int));
i=0;
while(i<size)
{
histogram[databaza[i].PocetDni]+=1;
i++;
}
i=0;
while(i<31)
{
if(histogram[i]!=0)
{printf("%2d: %d\n",i,histogram[i]);}
i++;
}
}
if(mod=='s')
{
char **zoradeny;
zoradeny=(char**) malloc(sizeof(char *)*size);
while(i<size)
{
zoradeny[i]=(char *) malloc(sizeof(char)*31);
i++;
}
i=0;
while(i<size)
{
copystring(databaza[i].Krajina,zoradeny[i]);
i++;
}
selectionsort(zoradeny,size);
i=0;
while(i<size)
{
printf("%s",zoradeny[i]);
i++;
}}
myflush(stdin);
}
return 0;
}
