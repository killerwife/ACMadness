#include <stdio.h>
#include <stdlib.h>

int main()
{   int i,b,a;
    i=0;
    FILE *counting;
    counting = fopen("stringencoding.txt","r+");
    while(1)
    {   b=fgetc(counting);
         if(b==' '){a=1;}
         if(b=='„'){a=1;}
         if(b=='-'){a=1;}
         if(a==1&&b>='a'&&b<='z'){i++;a=0;}
         if(a==1&&b>='A'&&b<='Z'){i++;a=0;}
        if(b==EOF){break;}
    }
    printf("%d\n",i);
    fclose(counting);
    return 0;
}
