#include <stdio.h>
#include <stdlib.h>

int main()
{   srand(time(NULL)*time(NULL));
    int max,min,avg,e,rising,g,h,i,j;
    int valuearray[1440];
    i=max=0;
    min=100;
    j=1;
    avg=0;
    e=rising=g=h=0;
    returnback:
    valuearray[i]=rand()%101;
    if(valuearray[i]>=80){printf("Warning!Critical levels!\n");}
    if(valuearray[i]>max){max=valuearray[i];}
    if(valuearray[i]<min){min=valuearray[i];}
    avg=avg+valuearray[i];
    if(valuearray[i]>valuearray[i-1]){e++;if(e>rising){rising=e;}}
    else{e=0;}
    if(valuearray[i]>valuearray[i-1]){g=valuearray[i]-valuearray[i-1];}
    if(valuearray[i]<valuearray[i-1]){g=valuearray[i-1]-valuearray[i];}
    if(g>h){h=g;}
    printf("Current maximum is %d.\n",max);
    printf("Current minimum is %d.\n",min);
    printf("Current average is %d.\n",avg/j);
    printf("Current longest rising period is %d.\n",rising);
    printf("Current highest difference between two time intervals is %d.\n",h);


    printf("Wanna continue y=1/n=0?");
    int scanfvariable;
    scanf("%d",&scanfvariable);
    if(scanfvariable==1){i++;j++; goto returnback;}
    return 0;
}
