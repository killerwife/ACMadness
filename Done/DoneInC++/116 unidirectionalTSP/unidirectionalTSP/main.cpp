#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    long long field[15][105];
    int previous[15][105];
    long long sums[15][105];
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF)
    {
        int minPos = 0;
        for (int i = 0; i < x; i++)
        {
            for (int k = 0; k < y; k++)
            {
                scanf("%lld", &field[i][k]);
            }
        }
        for (int i = x - 1; i >= 0; i--)
        {
            sums[i][y - 1] = field[i][y - 1];
        }
        if (x>1)
        {
            for (int i = y - 2; i >= 0; i--)
            {
                if (sums[0][i + 1]>sums[1][i + 1])
                {
                    if (sums[1][i + 1]>sums[x - 1][i + 1])
                    {
                        sums[0][i] = sums[x - 1][i + 1] + field[0][i];
                        previous[0][i] = x - 1;
                    }
                    else
                    {
                        sums[0][i] = sums[1][i + 1] + field[0][i];
                        previous[0][i] = 1;
                    }
                }
                else
                {
                    if (sums[0][i + 1] > sums[x - 1][i + 1])
                    {
                        sums[0][i] = sums[x - 1][i + 1] + field[0][i];
                        previous[0][i] = x - 1;
                    }
                    else
                    {
                        sums[0][i] = sums[0][i + 1] + field[0][i];
                        previous[0][i] = 0;
                    }
                }
                for (int k = x - 2; k > 0; k--)
                {
                    if (sums[k - 1][i + 1] > sums[k][i + 1])
                    {
                        if (sums[k][i + 1] > sums[k + 1][i + 1])
                        {
                            sums[k][i] = sums[k + 1][i + 1] + field[k][i];
                            previous[k][i] = k + 1;
                        }
                        else
                        {
                            sums[k][i] = sums[k][i + 1] + field[k][i];
                            previous[k][i] = k;
                        }
                    }
                    else
                    {
                        if (sums[k - 1][i + 1] > sums[k + 1][i + 1])
                        {
                            sums[k][i] = sums[k + 1][i + 1] + field[k][i];
                            previous[k][i] = k + 1;
                        }
                        else
                        {
                            sums[k][i] = sums[k - 1][i + 1] + field[k][i];
                            previous[k][i] = k - 1;
                        }
                    }
                }
                if (sums[0][i + 1] > sums[x - 2][i + 1])
                {
                    if (sums[x - 2][i + 1] > sums[x - 1][i + 1])
                    {
                        sums[x - 1][i] = sums[x - 1][i + 1] + field[x - 1][i];
                        previous[x - 1][i] = x - 1;
                    }
                    else
                    {
                        sums[x - 1][i] = sums[x - 2][i + 1] + field[x - 1][i];
                        previous[x - 1][i] = x - 2;
                    }
                }
                else
                {
                    if (sums[0][i + 1] > sums[x - 1][i + 1])
                    {
                        sums[x - 1][i] = sums[x - 1][i + 1] + field[x - 1][i];
                        previous[x - 1][i] = x - 1;
                    }
                    else
                    {
                        sums[x - 1][i] = sums[0][i + 1] + field[x - 1][i];
                        previous[x - 1][i] = 0;
                    }
                }
            }
            long long min = sums[0][0];
            minPos = 0;
            for (int i = 1; i < x; i++)
            {
                if (min > sums[i][0])
                {
                    min = sums[i][0];
                    minPos = i;
                }
            }
            int position = minPos;
            for (int i = 0; i < y - 1; i++)
            {
                printf("%d ", position + 1);
                position = previous[position][i];
            }
            printf("%d\n%lld\n", position + 1, min);
        }
        else
        {
            for (int i = y-2; i >=0; i--)
            {
                sums[0][i] = sums[0][i + 1] + field[0][i];
            }
            for (int i = 1; i < y; i++)
            {
                printf("%d ", 1);
            }
            printf("%d\n%lld\n", 1,sums[0][0]);
        }
              
    }
    return 0;
}
