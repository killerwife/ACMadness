#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swapping(char *a, char *b)
{
    char swaptemp;
    swaptemp=*a;
    *a=*b;
    *b=swaptemp;

}

void selectionsort(char sortingarray[31],int elementnumber)
{
    int i,j;
    int min;
    i=j=0;
    while(j<elementnumber)
    {
      char swaptemp;
      i=j+1;min=j;
      while(i<elementnumber)
      {
        if(sortingarray[i]<sortingarray[j]&&sortingarray[i]<sortingarray[min]){min=i;}
        i++;
      }
      swaptemp=sortingarray[min];
      sortingarray[min]=sortingarray[j];
      sortingarray[j]=swaptemp;
      j++;

    }
}

int stringCompare(char first[31],char second[31],int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(first[i]>second[i])
        {
            return 1;
        }
        if(first[i]<second[i])
        {
            return -1;
        }
    }
    return 0;
}

int ascendancyChecks(int used[31],char letters[31],int depth,char alphabet[31],int length)
{
    int k;
    int i;
    int check=1;
    int counters[26];
    int numofsameletter[31];
    int inverted[31];
    for(k=0;k<26;k++)
    {
        counters[k]=1;
    }
    for(k=0;k<length;k++)
    {
        numofsameletter[k]=counters[alphabet[k]-'a'];
        counters[alphabet[k]-'a']++;
        inverted[used[k]]=k;
    }
    for(k=0;k<26;k++)
    {
        counters[k]=1;
    }
    inverted[30]++;
    k=0;
    i=0;
    while(i<depth)
    {
        if(used[k]!=-1&&numofsameletter[inverted[i]]!=counters[letters[i]-'a'])
        {
            check=0;
            break;
        }
        else if(used[k]!=-1)
        {
            counters[letters[i]-'a']++;
            i++;
        }
        k++;
    }
    return check;
}

int ascendancyCheck(int used[31],char letters[31],int currentchar)
{
    int check=1;
    int i;
    int temp;
    int max=-1;
    int found=-1;
    for(i=0;i<31;i++)
    {
        if(letters[i]==currentchar&&used[i]!=-1)
        {
            temp=used[i];
            if(max<temp)
            {
                max=temp;
            }
            if(max>temp)
            {
                check=0;
                break;
            }
        }
    }
    for(i=30;i>=0;i--)
    {
        if(letters[i]==currentchar)
        {
            if(used[i]!=-1&&found==-1)
            {
                found=0;
            }
            if(used[i]==-1&&found==0)
            {
                check=0;
                break;
            }
        }
    }
    return check;
}

int depthSearch(char letters[31],int length,char word[31])
{
    int counter;
    int depthCounters[31];
    int used[31];
    int depth=0;
    int i;
    int check=0;
    char current[31];
    counter=1;
    for(i=0;i<31;i++)
    {
        depthCounters[i]=0;
        used[i]=-1;
        current[i]=letters[i];
    }
    while(depthCounters[depth]<length)
    {
        if(used[depthCounters[depth]]==-1)
        {
            used[depthCounters[depth]]=depth;
            current[depth]=letters[depthCounters[depth]];
            if(ascendancyCheck(used,letters,letters[depthCounters[depth]]))
            {
            depthCounters[depth]++;
            depth++;
            if('b'==current[0]&&check==0)
            {
                check=1;
                printf("%d",counter);
            }
            if(depth==length)
            {
                if(!stringCompare(current,word,length))
                {
                    break;
                }
                else
                {
                       counter++;
                }
                depthCounters[depth]=length;
            }
            }
            else
            {
                used[depthCounters[depth]]=-1;
                depthCounters[depth]++;
            }
        }
        else
        {
            depthCounters[depth]++;
        }
        while(depthCounters[depth]>=length&&depth>0)
        {
            depthCounters[depth]=0;
            depth--;
            used[depthCounters[depth]-1]=-1;
        }
    }
    return counter;
}

int main()
{
    char input[31];
    char temp[31];
    memset(input,'\0',31);
    do
    {
        int i;
        int size=0;
        scanf("%s",input);
        for(i=0;i<31;i++)
        {
            if(input[i]=='\0'&&input[size]!='\0')
            {
                size=i;
            }
            temp[i]=input[i];
        }
        selectionsort(input,size);
        i=depthSearch(input,size,temp);
        printf("%10d\n",i);
    }
    while(input[0]!='#');
    return 0;
}
