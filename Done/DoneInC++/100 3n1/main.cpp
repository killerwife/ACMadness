#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]) {
    int i, j, k, l, m, n;
    int low, high;
    int nums[200000];
    int queue[1000];
    memset(nums, 0, 200000 * sizeof(int));
    nums[1] = 1;
    nums[2] = 2;
    l = 2;
    for (k = 2; k < 200000; k *= 2)
    {
        nums[k] = l;
        l++;
    }
    while (scanf("%d%d", &low, &high) !=EOF)
    {
        int max = 0;
        if (low>high)
        {
            i = high;
            j = low;
        }
        else
        {
            i = low;
            j = high;
        }
        for (k = i; k <= j; k++)
        {
            int count;
            int result=0;
            m = k;
            l = -1;
            while (m>=200000||nums[m] == 0)
            {
                l++;
                queue[l] = m;
                if (!(m & 1))
                {
                    m=m >> 1;
                }
                else
                {
                    m = m * 3 + 1;
                }
            }
            result += l + 1 + nums[m];
            count = nums[m];
            for (; l >= 0; l--)
            {
                count++;
                if (queue[l] >= 200000)
                {
                    break;
                }
                nums[queue[l]] = count;
            }
            if (result > max)
            {
                max = result;
            }
        }
        printf("%d %d %d\n", low, high, max);
    }
    return 0;
}
