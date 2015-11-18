#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int windowPropertyCheck(char sequence[102],int size,int width)
{
    int check=-1;
    int patternCheck=-1;
    char patterns[100][100];
    int numOfPatterns=0;
    char window[100];
    int i,k,l;
    for(i=0;i<width;i++)
    {
        window[i]=sequence[i];
    }
    strcpy(patterns[numOfPatterns],window);
    numOfPatterns++;
    for(k=0;k<size-width+1;k++)
    {
        l=0;
        for(i=k;i<k+width;i++)
        {
            window[l]=sequence[i];
            l++;
        }
        for(i=0;i<numOfPatterns;i++)
        {
            if(!strcmp(window,patterns[i]))
            {
                patternCheck=0;
                break;
            }
        }
        if(patternCheck==-1)
        {
            strcpy(patterns[numOfPatterns],window);
            numOfPatterns++;
            if(numOfPatterns>width+1)
            {
                check=k+width;
                return check;
            }
        }
        patternCheck=-1;
    }
    return check;
}

int findPatterns(char sequence[102],int size)
{
    int check=-1;
    int i;
    for(i=1;i<=size;i++)
    {
        check=windowPropertyCheck(sequence,size,i);
        if(check!=-1)
        {
            break;
        }
    }
    return check;
}

int main()
{
    char sequence[102];
    while(fgets(sequence,102,stdin)!=NULL)
    {
        if(sequence[0]!='\n')
        {
        int size;
        int i;
        for(i=0;sequence[i]!='\0';i++);
        if(sequence[i-1]=='\n')
        {
            size=i-1;
        }
        else
        {
            size=i;
        }
        i=findPatterns(sequence,size);
        if(i==-1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO:%d\n",i);
        }
        }
    }
    return 0;
}
