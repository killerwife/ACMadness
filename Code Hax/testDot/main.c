#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows=5,cols=10;
    int *array= malloc(sizeof(int)*rows*cols);
    for(int i=0;i<rows;i++)
    {
        for(int k=0;k<cols;k++)
        {
            array[i*rows+cols]=10;
        }
    }
    free(array);
    return 0;
}
