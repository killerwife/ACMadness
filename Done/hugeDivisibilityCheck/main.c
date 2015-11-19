#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int intpow(int a, int b)
{
    int vysledok=1;
    while(b>0)
    {
        vysledok=vysledok*a;
        b--;
    }
    return vysledok;
}

int isDivisible(char temp[],int length,int a)
{
    int i=0;
    if(a==1)
    {
        return 1;
    }
    if(a==2)
    {
        if(temp[length-1]%2==0)
        {return 1;}
        else{return 0;}
    }
    if(a==3)
    {
        int sucet=0;
        while(i<length)
        {
            sucet=sucet+temp[i]-48;
            i++;
        }
        if(sucet%3==0)
        {return 1;}
        else
        {
            return 0;
        }
    }
    if(a==4)
    {
        int cislo;
        if(length==1)
        {
            cislo=temp[length-1]-48;
        }
        else{cislo=(temp[length-2]-48)*10+temp[length-1]-48;}
        if(cislo%4==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(a==5)
    {
        if(temp[length-1]=='0'||temp[length-1]=='5')
        {return 1;}
        else{return 0;}
    }
    if(a==6)
    {
        int sucet=0;
        while(i<length)
        {
            sucet=sucet+temp[i]-48;
            i++;
        }
        if(temp[length-1]%2==0&&sucet%3==0)
        {return 1;}
        else{return 0;}
    }
    if(a==7)
    {
        long sucet=0;
        int k=0;
        int znamienko=1;
        i=length-1;
        while(i>=0)
        {
            sucet=sucet+((temp[i]-48)*intpow(10,k))*znamienko;
            k++;
            if(k==3)
            {
                znamienko=-znamienko;
                k=0;
            }
            i--;
        }
        if(sucet%7==0)
        {
            return 1;
        }
        else{return 0;}
    }
    if(a==8)
    {
        int cislo;
        if(length==1)
        {
            cislo=temp[length-1]-48;
        }
        else
        {
        if(length==2)
        {
            cislo=(temp[length-2]-48)*10+temp[length-1]-48;
        }
        else{cislo=(temp[length-3]-48)*100+(temp[length-2]-48)*10+temp[length-1]-48;}}
        if(cislo%8==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(a==9)
    {
        int sucet=0;
        while(i<length)
        {
            sucet=sucet+temp[i]-48;
            i++;
        }
        if(sucet%9==0)
        {return 1;}
        else
        {
            return 0;
        }
    }
    if(a==10)
    {
        if(temp[length-1]=='0')
        {return 1;}
        else{return 0;}
    }
    if(a==11)
    {
        int sucet=0;
        int znamienko=1;
        while(i<length)
        {
            sucet=sucet+(temp[i]-48)*znamienko;
            znamienko=-znamienko;
            i++;
        }
        if(sucet%11==0)
        {
            return 1;
        }
        else{return 0;}

    }
    if(a==12)
    {
        int sucet=0;
        while(i<length)
        {
            sucet=sucet+temp[i]-48;
            i++;
        }
        int cislo;
        if(length==1)
        {
            cislo=temp[length-1]-48;
        }
        else
        {cislo=(temp[length-2]-48)*10+temp[length-1]-48;}
        if(cislo%4==0&&sucet%3==0)
        {
            return 1;
        }
        else{return 0;}
    }
    return 0;
}

int main()
{
    int vstupy;
    int wonderful=0;
    int divisor;
    scanf("%d",&vstupy);
    fgetc(stdin);
    while(vstupy>0)
    {
        char temp[1002];
            int length=0;
        scanf("%s",temp);
        while(temp[length]!='\0')
        {
            length++;
        }
        do
        {
            scanf("%d",&divisor);
            if(!isDivisible(temp,length,divisor))
            {
                wonderful=1;
            }
        }
        while(fgetc(stdin)!='\n');
            if(wonderful==1)
        {
            printf("%s - Simple.\n",temp);
        }
        else{printf("%s - Wonderful.\n",temp);}
        wonderful=0;
        vstupy--;
    }
    return 0;
}
