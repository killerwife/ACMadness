#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int time;
    int start;
}event;

int main()
{
    int events,rulen,done;
    int i,k;
    int temp;
    int rules[100000][3];
    /*int **rules;*/
    event *array;
    k=1;
    while((temp=fgetc(stdin))!=EOF&&(temp!='\n'))
    {
        ungetc(temp,stdin);
        scanf("%d",&events);
        array=(event*) malloc(sizeof(event)*events);
        /*rules=(int**) malloc(sizeof(int*)*events);
        i=0;
        while(i<events)
        {
            rules[i]=(int*)malloc(sizeof(int)*3);
            i++;
        }*/
        i=0;
        while(i<events)
        {
            scanf("%d",&array[i].time);
            i++;
        }
        i=0;
        while(1)
        {
           fgetc(stdin);
           temp=fgetc(stdin);
           if(temp=='#')
           {
               break;
           }
           else
           {
               fgetc(stdin);
               if(temp=='F')
               {
                   temp=fgetc(stdin);
                   if(temp=='F')
                   {
                       rules[i][0]=0;
                   }
                   else
                   {
                       rules[i][0]=1;
                   }
               }
               else
               {
                   temp=fgetc(stdin);
                   if(temp=='F')
                   {
                       rules[i][0]=2;
                   }
                   else
                   {
                       rules[i][0]=3;
                   }
               }
           }
           scanf("%d%d",&rules[i][1],&rules[i][2]);
           rules[i][1]--;
           rules[i][2]--;
           i++;
        }
        temp=fgetc(stdin);
        rulen=i;
        i=0;
        while(i<rulen)
        {
            array[rules[i][2]].start=-1;
            i++;
        }
        i=0;
        while(i<events)
        {
            if(array[i].start!=-1)
            {
                array[i].start=0;
            }
            i++;
        }
        i=0;
        done=0;
        while(done!=rulen)
        {
            while(i<rulen)
            {
                if((rules[i][0]!=4)&&(array[rules[i][1]].start!=-1))
                {
                    break;
                }
                i++;
            }
            if(i==rulen)
            {
               printf("Case %d:\nimpossible\n\n",k);
               break;
            }
            else
            {
                switch(rules[i][0])
                {
                case 0 : array[rules[i][2]].start=array[rules[i][1]].start+array[rules[i][1]].time-array[rules[i][2]].time;break;
                case 1 : array[rules[i][2]].start=array[rules[i][1]].start-array[rules[i][2]].time;break;
                case 2 : array[rules[i][2]].start=array[rules[i][1]].start+array[rules[i][1]].time;break;
                case 3 : array[rules[i][2]].start=array[rules[i][1]].start;break;
                }
                rules[i][0]=4;
            }
            i=0;
            done++;
        }
        if(i<rulen)
        {
            printf("Case %d:\n",k);
            while(i<events)
            {
                printf("%d %d\n",i+1,array[i].start);
                i++;
            }
            printf("\n");
        }
        k++;
       /* free(rules);*/
    free(array);
    }

    return 0;
}
