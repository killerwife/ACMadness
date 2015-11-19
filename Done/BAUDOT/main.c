#include <stdio.h>
#include <stdlib.h>

int power(int a, int power)
{
    int i=1;
    while(power>0)
    {
        i=i*a;
        power--;
    }
    return i;
}

int main()
{
    char firstline[32];
    char secondline[32];
    int i=0;
    while(i<31)
    {
        firstline[i]=fgetc(stdin);
        i++;
    }
    fgetc(stdin);
    i=0;
    while(i<31)
    {
        secondline[i]=fgetc(stdin);
        i++;
    }
    fgetc(stdin);
    i=0;
    int upshift=0;
    char tempchar;
    int tempint;
    while(1)
    {
        int k=4;
        int temp=0;


        while(k>=0)
        {
            tempchar=fgetc(stdin);
            temp=temp+power(2,k)*(((int)tempchar)-48);
            k--;
        }
        if(temp==31)
        {
            upshift=1;
        }
        else
        {if(temp==27)
        {
            upshift=0;
        }
        else
        {
            if(upshift==0)
            {printf("%c",firstline[temp]);}
            if(upshift==1)
            {printf("%c",secondline[temp]);}
        }}
        tempint=fgetc(stdin);
        if(tempint==EOF)
        {
            return 0;
        }
        if(tempint!='\n')
        {
            ungetc(tempint,stdin);
        }
        else{
                printf("\n");
        upshift=0;
        tempint=fgetc(stdin);
        if(tempint==EOF)
        {
            return 0;
        }
        else
            {
                ungetc(tempint,stdin);
            }
        }
    }
    return 0;
}
