#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *array;
    int increment;
} Yourstack;

int Isempty(int increment)
{
    if(increment==-1)
    {
        return 0;
    }
    else{return 1;}
}

void Pushintostack(int *array, int *increment,int value)
{
    *increment=*increment+1;
    array[*increment]=value;

}

int Popfromstack(int *array, int *increment)
{
    int temp;
    if(Isempty(*increment)==1)
    {
        temp=array[*increment];
        *increment=*increment+1;
        return temp;
    }
    else{return -1;}
}

int main()
{
    Yourstack testing;
    testing.array=(int*) malloc(sizeof(int)*42);
    Isempty(testing.increment);
    Pushintostack(testing.array,&testing.increment,a);
    Popfromstack(testing.array,&testing.increment);

    return 0;
}
