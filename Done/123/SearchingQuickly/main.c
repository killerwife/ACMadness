#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Titles
{
   int start;
   int end;
   int sentenceNum;
   char keyword[25];
} Title;

void swapping(Title first,Title second)
{
    Title temp;
    strcpy(temp.keyword,first.keyword);
    temp.end=first.end;
    temp.sentenceNum=first.sentenceNum;
    temp.start=first.start;
    strcpy(first.keyword,second.keyword);
    first.end=second.end;
    first.sentenceNum=second.sentenceNum;
    first.start=second.start;
    strcpy(second.keyword,temp.keyword);
    second.end=temp.end;
    second.sentenceNum=temp.sentenceNum;
    second.start=temp.start;
}

void swap(Title *pnode1,Title *pnode2)
{
    Title temp;
    temp=*pnode1;
    *pnode1=*pnode2;
    *pnode2=temp;
}

int compareString(char first[25],int firstlength,char second[12])
{
    int i;
    for(i=0;second[i]!='\n'&&second[i]!='\n'&&firstlength>i;i++)
    {
        if(first[i]>second[i])
        {
            return 1;
        }
        else if(first[i]<second[i])
        {
            return -1;
        }
    }
    if(i==firstlength)
    {return 0;}
    else if(i>=firstlength)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

int compareStrings(char first[25],char second[25])
{
    int i;
    for(i=0;first[i]!='\0'&&second[i]!='\0';i++)
    {
        if(first[i]>second[i])
        {
            return 1;
        }
        else if(first[i]<second[i])
        {
            return -1;
        }
    }
    if(first[i]=='\0'&&second[i]=='\0')
    {return 0;}
    else if(first[i]=='\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void selectionsort(Title sortingarray[3000],int elementnumber)
{
    int i,j;int min;i=j=0;
    while(j<elementnumber)
    {
      i=j+1;min=j;
      while(i<elementnumber)
      {
          int temp;
        if((temp=compareStrings(sortingarray[i].keyword,sortingarray[min].keyword))==-1||(temp==0&&sortingarray[i].sentenceNum<sortingarray[min].sentenceNum))
        {min=i;}
        i++;
      }
      swap(&sortingarray[min],&sortingarray[j]);
      j++;
    }
    return;
}

int main()
{
    int i,k,l;
    int characters;
    int ignoredwords;
    int titles;
    int start;
    int keywordnum;
    char wordsignore[50][12];
    char sentences[200][210];
    char temp[25];
    Title listofkeywords[3000];
    for(i=0;;i++)
    {
        fgets(wordsignore[i],12,stdin);
        if(wordsignore[i][0]==':')
        {
            break;
        }
    }
    ignoredwords=i;
    for(i=0;fgets(sentences[i],210,stdin)!=NULL;i++)
    {
        for(k=0;k<210;k++)
        {
            if(sentences[i][k]!=' ')
            {sentences[i][k]=tolower(sentences[i][k]);}
        }
    }
    titles=i;
    keywordnum=0;
    for(i=0;i<titles;i++)
    {
        characters=0;
        start=0;
        for(k=0;sentences[i][k]!='\0';k++)
        {
            if(characters!=0)
            {
                if(sentences[i][k]==' '||sentences[i][k]=='\n')
                {
                    int check=0;
                    for(l=0;l<ignoredwords;l++)
                    {
                        if(!compareString(temp,characters,wordsignore[l]))
                        {
                            check=-1;
                            break;
                        }
                    }
                    if(check==0)
                    {
                        strcpy(listofkeywords[keywordnum].keyword,temp);
                        listofkeywords[keywordnum].start=start;
                        listofkeywords[keywordnum].end=k-1;
                        listofkeywords[keywordnum].sentenceNum=i;
                        keywordnum++;
                    }
                    characters=0;
                    memset(temp,'\0',25);
                }
                else
                {
                    temp[characters]=sentences[i][k];
                    characters++;
                }
            }
            else
            {
                if(sentences[i][k]!=' ')
                {
                    start=k;
                    temp[characters]=sentences[i][k];
                    characters++;
                }
            }
        }
    }
    selectionsort(listofkeywords,keywordnum);
    for(i=0;i<keywordnum;i++)
    {
        for(k=0;sentences[listofkeywords[i].sentenceNum][k]!='\0';k++)
        {
            if(k>=listofkeywords[i].start&&k<=listofkeywords[i].end)
            {
                printf("%c",toupper(sentences[listofkeywords[i].sentenceNum][k]));
            }
            else
            {
                printf("%c",sentences[listofkeywords[i].sentenceNum][k]);
            }
        }
    }
    return 0;
}
