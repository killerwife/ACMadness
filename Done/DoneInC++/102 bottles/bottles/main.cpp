#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    long brown[3];
    long clear[3];
    long green[3];
    while (scanf("%ld%ld%ld%ld%ld%ld%ld%ld%ld", &brown[0], &green[0], &clear[0], &brown[1], &green[1], &clear[1], &brown[2], &green[2], &clear[2]) != EOF)
    {
        long result[6];
        long min = LONG_MAX;
        int pos = 0;
        result[0] = brown[1] + brown[2] + clear[0] + clear[2] + green[0] + green[1];
        result[1] = brown[1] + brown[2] + clear[0] + clear[1] + green[0] + green[2];
        result[2] = brown[0] + brown[2] + clear[1] + clear[2] + green[0] + green[1];
        result[3] = brown[0] + brown[1] + clear[1] + clear[2] + green[0] + green[2];
        result[4] = brown[0] + brown[2] + clear[0] + clear[1] + green[1] + green[2];
        result[5] = brown[0] + brown[1] + clear[0] + clear[2] + green[1] + green[2];
        for (int i = 0; i < 6; i++)
        {
            if (result[i] < min)
            {
                min = result[i];
                pos = i;
            }
        }
        if (pos == 0)
        {
            printf("BCG %ld\n", min);
        }
        else if (pos == 1)
        {
            printf("BGC %ld\n", min);
        }
        else if (pos == 2)
        {
            printf("CBG %ld\n", min);
        }
        else if (pos == 3)
        {
            printf("CGB %ld\n", min);
        }
        else if (pos == 4)
        {
            printf("GBC %ld\n", min);
        }
        else if (pos == 5)
        {
            printf("GCB %ld\n", min);
        }
    }
    return 0;
}
