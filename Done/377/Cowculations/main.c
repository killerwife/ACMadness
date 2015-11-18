#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tablets;
    scanf("%d",&tablets);
    printf("COWCULATIONS OUTPUT\n");
    while(tablets>0)
    {
        int num1,num2;
        char line[10];
        int i;
        num1=num2=0;
        scanf("%s",line);
        for(i=0;i<5;i++)
        {
            num1*=4;
            if(line[i]=='U')
            {
                num1+=1;
            }
            if(line[i]=='C')
            {
                num1+=2;
            }
            if(line[i]=='D')
            {
                num1+=3;
            }
        }
        scanf("%s",line);
        for(i=0;i<5;i++)
        {
            num2*=4;
            if(line[i]=='U')
            {
                num2+=1;
            }
            if(line[i]=='C')
            {
                num2+=2;
            }
            if(line[i]=='D')
            {
                num2+=3;
            }
        }
        for(i=0;i<3;i++)
        {
            scanf("%s",line);
            if(line[0]=='A')
            {
                num2+=num1;
            }
            if(line[0]=='L')
            {
                num2*=4;
            }
            if(line[0]=='R')
            {
                num2/=4;
            }
        }
        scanf("%s",line);
        num1=0;
        for(i=0;i<8;i++)
        {
            num1*=4;
            if(line[i]=='U')
            {
                num1+=1;
            }
            if(line[i]=='C')
            {
                num1+=2;
            }
            if(line[i]=='D')
            {
                num1+=3;
            }
        }
        if(num1==num2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        tablets--;
    }
    printf("END OF OUTPUT\n");
    return 0;
}
