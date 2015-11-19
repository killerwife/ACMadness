#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pushintostack(char linestack[40][30],int *linen,char line[])
{
    *linen=*linen+1;
    strcpy(linestack[*linen],line);

}


int main()
{
    char noun[5][9];
    char trans_verb[4][7];
    char intrans_verb[4][7];
    char article[2][4];
    char adjective[4][6];
    char adverb[3][12];
    char preposition[3][9];
    int k=1;
    char linestack[40][30];
    int linen=0;
    strcpy(noun[0],"man");
    strcpy(noun[1],"dog");
    strcpy(noun[2],"fish");
    strcpy(noun[3],"computer");
    strcpy(noun[4],"waves");
    strcpy(trans_verb[0],"struck");
    strcpy(trans_verb[1],"saw");
    strcpy(trans_verb[2],"bit");
    strcpy(trans_verb[3],"took");
    strcpy(intrans_verb[0],"slept");
    strcpy(intrans_verb[1],"jumped");
    strcpy(intrans_verb[2],"walked");
    strcpy(intrans_verb[3],"swam");
    strcpy(article[0],"the");
    strcpy(article[1],"a");
    strcpy(adjective[0],"green");
    strcpy(adjective[1],"small");
    strcpy(adjective[2],"rabid");
    strcpy(adjective[3],"quick");
    strcpy(adverb[0],"nearly");
    strcpy(adverb[1],"suddenly");
    strcpy(adverb[2],"restlessly");
    strcpy(preposition[0],"on");
    strcpy(preposition[1],"over");
    strcpy(preposition[2],"through");

    while(1)
    {
        fgets(linestack[0],30,stdin);
        linestack[0][(strlen(linestack[0])-1)]='\0';
        linen=0;
        while(linen!=-1)
        {
        if(!strcmp(linestack[linen],"sentence"))
        {
            linen--;
            if(k%2==0)
            {

                pushintostack(linestack,&linen,"trans-sentence");
            }
            else
            {
                pushintostack(linestack,&linen,"intrans-sentence");
            }
                    k++;

        }
        if(!strcmp(linestack[linen],"trans-sentence"))
        {
            linen--;
            pushintostack(linestack,&linen,"prep-phrase");
            pushintostack(linestack,&linen,"object");
            pushintostack(linestack,&linen,"verb-phrase");
            pushintostack(linestack,&linen,"subject");
        }
        if(!strcmp(linestack[linen],"intrans-sentence"))
        {
            linen--;
            pushintostack(linestack,&linen,"prep-phrase");
            pushintostack(linestack,&linen,"intrans-verb-phrase");
            pushintostack(linestack,&linen,"subject");
        }
        if(!strcmp(linestack[linen],"subject"))
        {
            linen--;
            pushintostack(linestack,&linen,"noun-phrase");
        }
        if(!strcmp(linestack[linen],"object"))
        {
            linen--;
            pushintostack(linestack,&linen,"noun-phrase");
        }
        if(!strcmp(linestack[linen],"noun-phrase"))
        {
            linen--;
            pushintostack(linestack,&linen,"modified-noun");
            pushintostack(linestack,&linen,"article");
        }
        if(!strcmp(linestack[linen],"modified-noun"))
        {
            linen--;
            if(k%2==0)
            {
                pushintostack(linestack,&linen,"noun");
            }
            else
            {
                pushintostack(linestack,&linen,"noun");
                pushintostack(linestack,&linen,"modifier");
            }
                    k++;
        }
        if(!strcmp(linestack[linen],"modifier"))
        {
            linen--;
            if(k%2==0)
            {
                pushintostack(linestack,&linen,"adjective");
            }
            else
            {
                pushintostack(linestack,&linen,"adjective");
                pushintostack(linestack,&linen,"adverb");
            }
                    k++;
        }
        if(!strcmp(linestack[linen],"verb-phrase"))
        {
            linen--;
            if(k%2==0)
            {
                pushintostack(linestack,&linen,"trans-verb");
            }
            else
            {
                pushintostack(linestack,&linen,"trans-verb");
                pushintostack(linestack,&linen,"adverb");
            }
                    k++;
        }
        if(!strcmp(linestack[linen],"intrans-verb-phrase"))
        {
            linen--;
            if(k%2==0)
            {
                pushintostack(linestack,&linen,"intrans-verb");
            }
            else
            {
                pushintostack(linestack,&linen,"intrans-verb");
                pushintostack(linestack,&linen,"adverb");
            }
                    k++;
        }
        if(!strcmp(linestack[linen],"prep-phrase"))
        {
            linen--;
            if(k%2==0)
            {
                pushintostack(linestack,&linen,"noun-phrase");
                pushintostack(linestack,&linen,"preposition");
            }
            else
            {
                pushintostack(linestack,&linen,"empty");

            }
                    k++;
        }
        if(!strcmp(linestack[linen],"noun"))
        {
            linen--;
            printf("%s",noun[k%5]);
                    k++;
                    if(linen!=-1&&(strcmp(linestack[linen],"prep-phrase")||k%2==0))
            {
                printf(" ");
            }
        }
        if(!strcmp(linestack[linen],"trans-verb"))
        {
            linen--;
            printf("%s",trans_verb[k%4]);
                    k++;
                    if(linen!=-1&&(strcmp(linestack[linen],"prep-phrase")||k%2==0))
            {
                printf(" ");
            }
        }
        if(!strcmp(linestack[linen],"intrans-verb"))
        {
            linen--;
            printf("%s",intrans_verb[k%4]);
                    k++;
                    if(linen!=-1&&(strcmp(linestack[linen],"prep-phrase")||k%2==0))
            {
                printf(" ");
            }
        }
        if(!strcmp(linestack[linen],"article"))
        {
            linen--;
            printf("%s",article[k%2]);
                    k++;
                    if(linen!=-1&&(strcmp(linestack[linen],"prep-phrase")||k%2==0))
            {
                printf(" ");
            }
        }
        if(!strcmp(linestack[linen],"adjective"))
        {
            linen--;
            printf("%s",adjective[k%4]);
                    k++;
                    if(linen!=-1&&(strcmp(linestack[linen],"prep-phrase")||k%2==0))
            {
                printf(" ");
            }
        }
        if(!strcmp(linestack[linen],"adverb"))
        {
            linen--;
            printf("%s",adverb[k%3]);
                    k++;
                    if(linen!=-1&&(strcmp(linestack[linen],"prep-phrase")||k%2==0))
            {
                printf(" ");
            }
        }
        if(!strcmp(linestack[linen],"preposition"))
        {
            linen--;
            printf("%s",preposition[k%3]);
            if(linen!=-1&&(strcmp(linestack[linen],"prep-phrase")||k%2==0))
            {
                printf(" ");
            }
            k++;
        }
        if(!strcmp(linestack[linen],"empty"))
        {
            linen--;
        }
        }
        printf("\n");
        int tempchar=fgetc(stdin);
        if(tempchar==EOF)
        {
            break;
        }
        else{ungetc(tempchar,stdin);}
    }
    return 0;
}
