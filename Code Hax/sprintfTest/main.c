#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cislo=5;
    char msg[80];
   sprintf(msg,"Karty hraca spolu: %d",cislo);
   printf("\n%s",msg);
    return 0;
}
