#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int i=1;
    while(a!=0&&b!=0)
    {
    if(a/b>26&&(a/b!=27||a%b!=0))
    {
        printf("Case %d: impossible\n",i);
    }
    else
    {
    if(a%b==0)
    {
        printf("Case %d: %d\n",i,a/b-1);
    }
    else
    {printf("Case %d: %d\n",i,a/b);}}
    i++;
    scanf("%d%d",&a,&b);
    }
    return 0;
}
