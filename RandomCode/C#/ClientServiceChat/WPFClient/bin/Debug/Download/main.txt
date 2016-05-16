#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int value;
    struct Slovo* dalsi;
}Slovo;

int main()
{
    Slovo* prvy=(Slovo*) malloc(sizeof(Slovo)*1);
    (*prvy).value=0;
    Slovo* druhy=(Slovo*) malloc(sizeof(Slovo)*1);
    (*druhy).value=1;
    (*prvy).dalsi=druhy;
    (*druhy).dalsi=NULL;
    Slovo*temp=prvy;
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp=temp->dalsi;
    }
    temp=prvy;
    while(temp!=NULL)
    {
        Slovo* bla=temp->dalsi;
        free(temp);
        temp=bla;
    }
    return 0;
}
