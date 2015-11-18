#include <stdio.h>
#include <stdlib.h>
#include <math.h>


intpower(int a,int b){if(b!=0){int i;
i=1;int c;c=a;
while(i<b){a=a*c;i++;}return a;}
else{a=1; return a;}}

int main()
{   int a;
    a=845;
    printf("%d\n",intpower(10,1));
    return 0;
}
