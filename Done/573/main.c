#include <stdio.h>
#include <stdlib.h>

int main()
{
    int h,u,d,f;
    double fatigue;
    int i;
    int stuff;
    int distance;
    scanf("%d%d%d%d",&h,&u,&d,&f);
    while(h!=0)
    {
        distance=0;
        i=-1;
        fatigue=f;
        fatigue=fatigue/100;
        fatigue=u*fatigue;
        fatigue=fatigue*1000;
        stuff=fatigue;
        do
        {
            i++;
            if(u*1000-stuff*i>0)
            {
                distance=distance+u*1000-stuff*i;
            }
            if(distance>h*1000)
            {
                break;
            }
            distance=distance-d*1000;

        }
        while(distance<=h*1000&&distance>=0);
       if(distance>0)
        {
            printf("success ");
        }
        else
        {
            printf("failure ");
        }
        printf("on day %d\n",i+1);
        scanf("%d%d%d%d",&h,&u,&d,&f);
    }
    return 0;
}
