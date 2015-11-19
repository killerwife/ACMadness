#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int increment;
} heap;

void swapping(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int insertintoheap(int *heap,int *increment,int value)
{
    int check;
    int i;
    check=1;
    i=*increment;
    heap[i]=value;
    while(i>0&&check==1)
    {
        if(heap[i]>heap[(i-1)/2])
        {
            swapping(&heap[i],&heap[(i-1)/2]);
        }
        else
        {
            check=0;
        }
        i=(i-1)/2;
    }
    *increment=*increment+1;
}

int popfromheap(int *heap,int *increment)
{
    int returnvalue;
    int i=0;
    returnvalue=heap[0];
    heap[0]=0;
    while(i<*increment)
    {
        if(*increment>i*2+1&&*increment<=i*2+2)
        {
            swapping(&heap[i],&heap[(i*2)+1]);
            break;
        }
        if(*increment>i*2+2)
        {

            if(heap[(i*2)+1]>heap[(i*2)+2])
            {
                swapping(&heap[i],&heap[(i*2)+1]);
                i=(i*2)+1;
            }
            else
            {
                swapping(&heap[i],&heap[(i*2)+2]);
                i=(i*2)+2;
            }
        }

        else
        {
            break;
        }
    }
    return returnvalue;
}

int main()
{
    heap tester;
    printf("Enter size of generated heap/number of displayed elements.");
    int a;
    int b;
    int i;
    srand(time(NULL)*time(NULL));
    scanf("%d",&a);
    tester.increment=0;
    tester.array= (int *) malloc(sizeof(int)*a);
    while(tester.increment<a)
    {
        insertintoheap(tester.array,&tester.increment,(rand()%100));

    }
    while(tester.array[0]!=0)
    {
        b=popfromheap(tester.array,&tester.increment);
        printf("%d\t",b);
    }
    return 0;
}
