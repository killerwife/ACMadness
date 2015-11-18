#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int combinations(int size,int letterCounters[30])
{
    int i;
    int max=-1;
    long long numerator=1;
    long long denominator=1;
    long long factorials[20];
    factorials[0]=1;
    for(i=1;i<20;i++)
    {
        denominator*=i;
        factorials[i]=denominator;
    }
    denominator=1;
    for(i=0;i<30;i++)
    {
        if(letterCounters[i]>max)
        {
            max=letterCounters[i];
        }
    }
    for(i=size;i>max;i--)
    {
        numerator*=i;
    }
    for(i=0;i<30;i++)
    {
        if(letterCounters[i]!=0)
        {
            if(letterCounters[i]==max)
            {
                max=-1;
            }
            else
            {
                numerator/=factorials[letterCounters[i]];
            }
        }
    }
    return (int) numerator;
}

int permsUpTo(char word[32],int size,int letterCounters[30])
{
    int i=0;
    int result=0;
    char temp[32];
    while(i+'a'<word[0])
    {
        if(letterCounters[i]!=0)
        {
            letterCounters[i]--;
            result+=combinations(size-1,letterCounters);
            letterCounters[i]++;
        }
        i++;
    }
    letterCounters[i]--;
    for(i=1;i<size;i++)
    {
        temp[i-1]=word[i];
    }
    if(size-1>0)
    {result+=permsUpTo(temp,size-1,letterCounters);}
    return result;
}

int main()
{
    char input[32];
    int size=0;
    fgets(input,32,stdin);
    do
    {
        int i;
        int letterCounters[30];
        size=0;
        for(i=0;input[i]!='\0';i++)
        {
            if(input[i]!=' ')
            {
                size++;
            }
        }
        size-=1;
        for(i=0;i<30;i++)
        {
            letterCounters[i]=0;
        }
        for(i=0;i<size;i++)
        {
            letterCounters[input[i]-'a']++;
        }
        i=permsUpTo(input,size,letterCounters);
        if(size>0)
        {printf("%10d\n",i+1);}
        fgets(input,31,stdin);
    }
    while(input[0]!='#');
    return 0;
}

