#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lines;
    int i=1;
    int k=0;
    int order[1000];
    int orderstack[1000];
    int counter=-1;
    int state=0;
    scanf("%d",&lines);
    while(lines!=0)
    {
        scanf("%d",&order[0]);
        while(order[0]!=0)
        {
        while(i<lines)
        {
            scanf("%d",&order[i]);
            i++;
        }
        i=0;
        while(i<lines&&k<=lines)
        {
            if(state==0)
            {counter++;
            k++;

            orderstack[counter]=k;}
            if(counter!=-1&&orderstack[counter]==order[i])
            {
                i++;
                counter--;
                state=1;
            }
            else
            {
                state=0;
            }

        }
        if(i==lines)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        i=1;
        k=0;
        state=0;
        counter=-1;
        scanf("%d",&order[0]);
        }
        printf("\n");
        scanf("%d",&lines);
    }
    return 0;
}
