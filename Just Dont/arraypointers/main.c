#include <stdio.h>
#include <stdlib.h>

int main()
{   int *pointer;
    int *a;double b;
    scanf("%lf",&b);
    pointer=(int *) malloc(b*sizeof(int));
    a=&pointer[35535];
    pointer[35535]=100;
    b=*a;
    printf("%lf",b);
    free(pointer);
    return 0;
}
