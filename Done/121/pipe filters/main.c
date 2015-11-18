#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double skewHeight;

int gridPattern(double width,double height)
{
    int result=1;
    result*=(int)width;
    result*=(int)height;
    return result;
}

int skewPattern(double width,double height)
{
    int result=0;
    int unitheight=(int)((height-1)/skewHeight)+1;
    int unitwidth=(int)(width);
    double rest=width-(double)unitwidth;
    if(width<1||height<1)
    {
        return 0;
    }
    result=unitheight*unitwidth;
    if(rest<0.5)
    {
        result-=unitheight/2;
    }
    return result;
}

int main()
{
    int checkEOF;
    skewHeight=sqrt(0.75);
    checkEOF=fgetc(stdin);
    while(checkEOF!=EOF)
    {
        int result,tempresult;
        int skewCheck=0;
        double width,height;
        ungetc(checkEOF,stdin);
        scanf("%lf%lf",&width,&height);
        checkEOF=fgetc(stdin);
        if(checkEOF=='\n')
        {
            checkEOF=fgetc(stdin);
        }
        result=tempresult=0;
        result=gridPattern(width,height);
        if((tempresult=gridPattern(height,width))>result)
        {
            result=tempresult;
        }
        if((tempresult=skewPattern(width,height))>result)
        {
            result=tempresult;
            skewCheck=1;
        }
        if((tempresult=skewPattern(height,width))>result)
        {
            result=tempresult;
            skewCheck=1;
        }
        printf("%d ",result);
        if(skewCheck==1)
        {
            printf("skew\n");
        }
        else
        {
            printf("grid\n");
        }
        result=tempresult=0;
    }
    return 0;
}
