#include <stdio.h>
#include <stdlib.h>

int compare(char a[2],char b[2])
{
    if(a[0]==b[0])
    {
        if(a[1]==b[1])
        {
            return 0;
        }
        if(a[1]<b[1])
        {
            return -1;
        }
        else
        {
            return 1;
        }

    }
    if(a[0]<b[0])
    {
        return -1;
    }
    else
    {
        return 1;
    }

}

int main()
{

    char playercards[4][13][2];
    char players=fgetc(stdin);
    fgetc(stdin);
    while(players!='#')
    {int i=0;
    while(i<26)
    {

        playercards[i%4][i/4][0]=fgetc(stdin);
        if(playercards[i%4][i/4][0]=='C')
        {
            playercards[i%4][i/4][0]=1;
        }
        if(playercards[i%4][i/4][0]=='D')
        {
            playercards[i%4][i/4][0]=2;
        }
        if(playercards[i%4][i/4][0]=='S')
        {
            playercards[i%4][i/4][0]=3;
        }
        if(playercards[i%4][i/4][0]=='H')
        {
            playercards[i%4][i/4][0]=4;
        }
        playercards[i%4][i/4][1]=fgetc(stdin);
        if(playercards[i%4][i/4][1]=='2')
        {
            playercards[i%4][i/4][1]=2;
        }
        if(playercards[i%4][i/4][1]=='3')
        {
            playercards[i%4][i/4][1]=3;
        }
        if(playercards[i%4][i/4][1]=='4')
        {
            playercards[i%4][i/4][1]=4;
        }
        if(playercards[i%4][i/4][1]=='5')
        {
            playercards[i%4][i/4][1]=5;
        }
        if(playercards[i%4][i/4][1]=='6')
        {
            playercards[i%4][i/4][1]=6;
        }
        if(playercards[i%4][i/4][1]=='7')
        {
            playercards[i%4][i/4][1]=7;
        }
        if(playercards[i%4][i/4][1]=='8')
        {
            playercards[i%4][i/4][1]=8;
        }
        if(playercards[i%4][i/4][1]=='9')
        {
            playercards[i%4][i/4][1]=9;
        }
        if(playercards[i%4][i/4][1]=='T')
        {
            playercards[i%4][i/4][1]=10;
        }
        if(playercards[i%4][i/4][1]=='J')
        {
            playercards[i%4][i/4][1]=11;
        }
        if(playercards[i%4][i/4][1]=='Q')
        {
            playercards[i%4][i/4][1]=12;
        }
        if(playercards[i%4][i/4][1]=='K')
        {
            playercards[i%4][i/4][1]=13;
        }
        if(playercards[i%4][i/4][1]=='A')
        {
            playercards[i%4][i/4][1]=14;
        }
        i++;
    }
    fgetc(stdin);
    while(i<52)
    {

        playercards[i%4][i/4][0]=fgetc(stdin);
        if(playercards[i%4][i/4][0]=='C')
        {
            playercards[i%4][i/4][0]=1;
        }
        if(playercards[i%4][i/4][0]=='D')
        {
            playercards[i%4][i/4][0]=2;
        }
        if(playercards[i%4][i/4][0]=='S')
        {
            playercards[i%4][i/4][0]=3;
        }
        if(playercards[i%4][i/4][0]=='H')
        {
            playercards[i%4][i/4][0]=4;
        }
        playercards[i%4][i/4][1]=fgetc(stdin);
        if(playercards[i%4][i/4][1]=='2')
        {
            playercards[i%4][i/4][1]=2;
        }
        if(playercards[i%4][i/4][1]=='3')
        {
            playercards[i%4][i/4][1]=3;
        }
        if(playercards[i%4][i/4][1]=='4')
        {
            playercards[i%4][i/4][1]=4;
        }
        if(playercards[i%4][i/4][1]=='5')
        {
            playercards[i%4][i/4][1]=5;
        }
        if(playercards[i%4][i/4][1]=='6')
        {
            playercards[i%4][i/4][1]=6;
        }
        if(playercards[i%4][i/4][1]=='7')
        {
            playercards[i%4][i/4][1]=7;
        }
        if(playercards[i%4][i/4][1]=='8')
        {
            playercards[i%4][i/4][1]=8;
        }
        if(playercards[i%4][i/4][1]=='9')
        {
            playercards[i%4][i/4][1]=9;
        }
        if(playercards[i%4][i/4][1]=='T')
        {
            playercards[i%4][i/4][1]=10;
        }
        if(playercards[i%4][i/4][1]=='J')
        {
            playercards[i%4][i/4][1]=11;
        }
        if(playercards[i%4][i/4][1]=='Q')
        {
            playercards[i%4][i/4][1]=12;
        }
        if(playercards[i%4][i/4][1]=='K')
        {
            playercards[i%4][i/4][1]=13;
        }
        if(playercards[i%4][i/4][1]=='A')
        {
            playercards[i%4][i/4][1]=14;
        }
        i++;
    }
    int k=0;
    int j=0;
    i=0;
    while(i<4)
    {
        while(j<13)
        {
            k=j;
            while(k>0)
            {
                if(compare(playercards[i][k],playercards[i][k-1])==-1)
                {
                    char temp[2];
                    temp[0]=playercards[i][k][0];
                    temp[1]=playercards[i][k][1];
                    playercards[i][k][0]=playercards[i][k-1][0];
                    playercards[i][k][1]=playercards[i][k-1][1];
                    playercards[i][k-1][0]=temp[0];
                    playercards[i][k-1][1]=temp[1];
                }
                else
                {
                    break;
                }
                k--;
            }
            j++;
        }
        j=0;
        i++;
    }
    i=0;
    j=0;
    k=0;
    if(players=='S')
    {
        k=3;
    }
    if(players=='W')
    {
        k=2;
    }
    if(players=='N')
    {
        k=1;
    }
    while(i<4)
    {
        if(i==0)
        {
            printf("S: ");
        }
        if(i==1)
        {
            printf("W: ");
        }
        if(i==2)
        {
            printf("N: ");
        }
        if(i==3)
        {
            printf("E: ");
        }

        while(j<13)
        {
            if(playercards[k%4][j][0]==1)
            {
                printf("C");
            }
            if(playercards[k%4][j][0]==2)
            {
                printf("D");
            }
            if(playercards[k%4][j][0]==3)
            {
                printf("S");
            }
            if(playercards[k%4][j][0]==4)
            {
                printf("H");
            }
            if(playercards[k%4][j][1]==10)
            {
                printf("T");
            }
            if(playercards[k%4][j][1]==11)
            {
                printf("J");
            }
            if(playercards[k%4][j][1]==12)
            {
                printf("Q");
            }
            if(playercards[k%4][j][1]==13)
            {
                printf("K");
            }
            if(playercards[k%4][j][1]==14)
            {
                printf("A");
            }
            if(playercards[k%4][j][1]<10)
            {
                printf("%d",playercards[k%4][j][1]);
            }
            j++;
            if(j!=13)
            {
                printf(" ");
            }
        }
        printf("\n");
        j=0;
        i++;
        k++;
    }
    fgetc(stdin);
    players=fgetc(stdin);
    fgetc(stdin);
    }
    return 0;
}
