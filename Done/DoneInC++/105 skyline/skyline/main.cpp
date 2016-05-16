#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int one, two, three;
    int skyline[10001];
    memset(skyline, 0, 10001 * sizeof(int));
    while (scanf("%d%d%d", &one, &two, &three) != EOF)
    {
        for (int i = one; i < three; i++)
        {
            if (skyline[i] < two)
            {
                skyline[i] = two;
            }
        }
    }
    int change = 0;
    int first = 0;
    for (int i = 0; i < 10000; i++)
    {        
        if (skyline[i] != change)
        {
            if (first != 0)
            {
                printf(" ");
            }
            else
            {
                first = 1;
            }
            change = skyline[i];
            printf("%d %d", i, skyline[i]);
        }        
    }
    printf("\n");
    return 0;
}