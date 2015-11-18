#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[1025];
    fgets(input,1024,stdin);
    while(input[0]!='#')
    {
        long calculator=0;
        long remainder=0;
        int i;
        for(i=0;input[i]!='\n';i++)
        {
            calculator=calculator*256;
            calculator+=input[i];
            calculator=calculator%34943;
        }
        calculator=calculator*256;
        calculator=calculator%34943;
        calculator=calculator*256;
        calculator=calculator%34943;
        if(calculator>0)
        {calculator=34943-calculator;
        remainder=calculator%256;
        calculator/=256;}
        printf("%02X %02X\n",calculator,remainder);
        fgets(input,1024,stdin);
    }
    return 0;
}
