#include <stdio.h>
#include <stdlib.h>

long longpowa(long a,long b)
{
    int result=1;
    while(b>0)
    {
        result=result*a;
        b--;
    }
    return result;
}

int main()
{
    int lines;
    int temp1;
    int temp2;
    int i,k,l;
    signed long result;
    int signs;
    long max=1073741824;
    long line[100000];
    line[0]=1;
    scanf("%d",&lines);
    while(lines>0)
    {
        scanf("%d%d",&temp1,&temp2);
        if(temp2==0)
        {
            printf("1\n");
        }
        else
        {
            if(temp1==0)
            {
                printf("2\n");
            }
            else
            {
                if(temp1==temp2||-temp1==temp2)
                {
                    printf("4\n");
                }
                else
                {
                    i=3;
                    line[1]=2;
                    line[2]=1;
                    k=3;
                    while(i<1000)
                    {
                        l=k-1;
                        line[k]=1;
                        while(l>0)
                        {
                            line[l]=line[l]+line[l-1];
                            l--;
                        }
                        k++;
                        l=1;
                        signs=-1;
                        result=0;
                        while(l<k)
                        {
                            result=result+line[l]*longpowa(temp1,k-2-l)*longpowa(temp2,l)*signs;
                            signs=-signs;
                            l++;
                            l++;
                        }
                        if(result==0)
                        {
                            break;
                        }
                        i++;
                    }
                    if(result!=0)
                    {
                        printf("TOO COMPLICATED\n");
                    }
                    else
                    {
                        l=0;
                        result=0;
                         while(l<k)
                        {
                            result=result+line[l]*longpowa(temp1,k-2-l)*longpowa(temp2,l)*signs;
                            if(l%2==1)
                            {
                                signs=-signs;
                            }
                            l++;

                        }
                        if(result<max&&result>-max)
                        {printf("%d\n",i);}
                        else
                        {
                            printf("TOO COMPLICATED\n");
                        }
                    }


                }
            }
        }

        lines--;
    }
    return 0;
}
