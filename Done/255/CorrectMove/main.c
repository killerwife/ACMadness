#include <stdio.h>
#include <stdlib.h>

int allowedMove(int king, int moveto)
{
    if(king/8>0&&king-8==moveto)
    {
        return 1;
    }
    if(king/8<7&&king+8==moveto)
    {
        return 1;
    }
    if(king%8<7&&king+1==moveto)
    {
        return 1;
    }
    if(king%8>0&&king-1==moveto)
    {
        return 1;
    }
    return 0;
}

int illegalMove(int king,int queen,int moveto)
{
    if(moveto==king||moveto==queen)
    {
        return 1;
    }
    else if(queen%8!=moveto%8)
    {
        if((queen/8)*8<=moveto&&(queen/8+1)*8>moveto)
        {
            if(king>queen&&king<moveto)
            {
                return 1;
            }
            else if(king<queen&&king>moveto)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if(king%8==queen%8)
        {
            if(king>moveto&&king<queen)
            {
                return 1;
            }
            else if(king<moveto&&king>queen)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int king,queen,moveto;
    char temp=0;
    temp=fgetc(stdin);
    while(temp!=EOF)
    {
        ungetc(temp,stdin);
        scanf("%d%d%d",&king,&queen,&moveto);
        if(king==queen)
        {
            printf("Illegal state\n");
        }
        else if(illegalMove(king,queen,moveto))
        {
            printf("Illegal move\n");
        }
        else if(allowedMove(king,moveto))
        {
            printf("Move not allowed\n");
        }
        else
        {
            if((king==0&&moveto==9)||(king==7&&moveto==14)||(king==56&&moveto==49)||(king==63&&moveto==54))
            {
                printf("Stop\n");
            }
            else
            {
                printf("Continue\n");
            }
        }
        temp=fgetc(stdin);
        if(temp=='\n')
        {
            temp=fgetc(stdin);
        }
    }
    return 0;
}
