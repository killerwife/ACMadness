#include <stdio.h>
#include <stdlib.h>

int main()
{   printf("Enter ph:");
    double a;
    scanf("%lf",&a);
    if (a<7){
    printf("Solution is acidic.\n");
    if(a<0){printf("Solution is very acidic indeed. EXTREME");}}
    if (a==7){
    printf("Solution is neutral.\n");}
    if (a>7){
    printf("Solution is alkaline\n");
    if(a>14){
    printf("Solution is very alkaline indeed. EXTREME\n");}}

    return 0;
}
