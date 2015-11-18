#include <stdio.h>
#include <stdlib.h>

int main()
{   int i,a,b=0;
    int size;
    i=a=0;
    char filepath[256];
    char *p;
    tryagain:
    printf("Enter filepath to filefinding.\n");
    scanf("%s",filepath);
    FILE *checking;
    if(fopen(filepath,"r")!=NULL) //check if file exists
    {
        checking=fopen(filepath,"r");
    }
    else
    {
       goto tryagain;
    }
    fseek(checking, 0, SEEK_END); // seek to end of file
    size = ftell(checking); //to store position of end of file
    rewind(checking);  // to go to beginning without reopening file
    p= (char *) malloc(sizeof(char)*(size+1));
    printf("Enter word for seeking.\n");
    char word[46]; //largest word in english language is 46 :-D
    scanf("%s",word);
    while(size>i)  // this loop looks for the string in given file
    {
       p[i]=fgetc(checking);  //stores characters of file in an array for postproccesing
       if(p[i]==word[a])  // tieto if statementy zabezpecuju aby, zistovalo ci prve pismeno v subore je aj v nascanfovanom poli a ak ano tak pokracuje k dalsiemu pismenu v poradi, porovna, a ak to
       {                  // sedi aj nadalej incrementuje premennu b

           a++; //a uklada dalsie pismeno v poradi ktore sa ma porovnat, vzdy sa resetuje na nulu ak nepasuje, a naopak ak pasuje zabezpeci aby potom sa porovnavalo dalsie
       }
       else
       {
           a=0;
       }
       if(word[a]=='\0')
       {   printf("Position of word is %d in the file.\n",i+1);
           b++;  // b uklada kolkokrat je tam slovo
           printf("It is the %d-th finding.\n",b);
           a=0;
       }
       i++;
    }
    p[size+1]='\0';
    printf("Word %s was found %d times.",word,b); //printfs the word for scanning and number of finds
    free(p);
    fclose(checking);
    return 0;
}
