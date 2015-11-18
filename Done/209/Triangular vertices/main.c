#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int plotEdge(int vertexA, int vertexB)
{
    int firstA,lastA;
    int firstB,lastB;
    int i,k;
    int length=100000;
    int temp;
    if(vertexA==vertexB)
    {
        return length;
    }
    firstA=lastA=1;
    for(i=1;firstA>vertexA||lastA<vertexA;i++)
    {
        firstA=firstA+i;
        lastA=lastA+i+1;
    }
    firstB=firstA;
    lastB=lastA;
    for(k=i;firstB>vertexB||lastB<vertexB;k++)
    {
        firstB=firstB+k;
        lastB=lastB+k+1;
    }
    temp=vertexA-vertexB;
    if(firstA==firstB)
    {
        length=temp;
    }
    else if(firstA-firstB==temp||lastA-lastB==temp)
    {
        length=i-k;
    }
    length=length>=0?length:-length;
    return length;
}

int main()
{
    char temp=0;
    temp=fgetc(stdin);
    while(temp!=EOF)
    {
        int vertices[6];
        int i=0;
        int k=0;
        int size;
        int check=0;
        int length=0;
        int validcounter=0;
        int hexagondiagonal=0;
        ungetc(temp,stdin);
        do
        {
            scanf("%d",&vertices[i]);
            i++;
        }
        while((temp=fgetc(stdin))!='\n'&&temp!=EOF);
        size=i;
        for(i=0;i<size;i++)
            {
                printf("%d ",vertices[i]);
            }
        if(size==1||size==2||size==5)
        {
            check=-1;
        }
        else
        {
        qsort(vertices, size, sizeof(int), cmpfunc);
        for(i=0;i<size;i++)
        {
            for(k=i+1;k<size;k++)
            {
                 int result=plotEdge(vertices[i],vertices[k]);
                 if(result<100000)
                 {
                     if(length==0)
                     {
                         length=result;
                     }
                     else if(length!=result&&size!=6)
                     {
                         check=-1;
                         break;
                     }
                     else if(size==6&&length!=result)
                     {
                         hexagondiagonal++;
                     }
                     if(result==length)
                     {validcounter++;}
                 }
            }
            if(check==-1)
            {
                break;
            }
        }
        if(size==6)
        {
            if(validcounter!=6&&validcounter!=9)
            {
                check=-1;
            }
            else if(hexagondiagonal!=2&&hexagondiagonal!=3)
            {
                check=-1;
            }
        }
        }
        if(check==-1||(size==4&&validcounter!=5)||(size==3&&validcounter!=3))
        {
            printf("are not the vertices of an acceptable figure\n");
        }
        else
        {
            if(size==3)
            {
                printf("are the vertices of a triangle\n");
            }
            else if(size==4)
            {
                printf("are the vertices of a parallelogram\n");
            }
            else
            {
                printf("are the vertices of a hexagon\n");
            }
        }
        if(temp=='\n')
        {
            temp=fgetc(stdin);
        }
    }
    return 0;
}
