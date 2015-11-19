#include <stdio.h>
#include <stdlib.h>

int main()
{
    char tempchar;
    int number=0;
    int i=0;
    while((tempchar=fgetc(stdin))!=EOF)
    {
        if(tempchar>='0'&&tempchar<='9')
        {
            number=number +tempchar-'0';
        }
        if((tempchar>='A'&&tempchar<='Z')||tempchar=='*')
        {
            while(i<number)
            {
                printf("%c",tempchar);
                i++;
            }
            i=0;
            number=0;
        }
        if(tempchar=='b')
        {
            while(i<number)
            {
                printf(" ");
                i++;
            }
            i=0;
            number=0;
        }
        if(tempchar=='\n'||tempchar=='!')
        {
            printf("\n");
        }

    }
    return 0;
}
