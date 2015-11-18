#include <stdio.h>
#include <stdlib.h>

int * rpermute(int n) {
    int *a = malloc(n*sizeof(int));
    int k;
    for (k = 0; k < n; k++)
	a[k] = k;
    for (k = n-1; k > 0; k--) {
	int j = rand() % (k+1);
	int temp = a[j];
	a[j] = a[k];
	a[k] = temp;
    }
    return a;
}

int checker(int *a)
{
    int i=4;
    while(i>=0)
    {
        if(a[i]==1&&i>=1&&a[i-1]==2)
        {
            return 1;
        }
        if(a[i]==2&&i>=1&&a[i-1]==1)
        {
            return 1;
        }
        i--;
    }
    return 0;
}

int main()
{
    int i;
    double k;
    i=0;
    k=0;
    int* a;
    int b;
    int operations;
    scanf("%d",&operations);
    srand(time(NULL)*time(NULL));
    while(i<operations)
    {


        a=rpermute(5);
        b=checker(a);
        if(b==1)
        {
            k++;
        }
        free(a);

        i++;
    }
    printf("The result is %lf.",k/operations);
    return 0;
}
