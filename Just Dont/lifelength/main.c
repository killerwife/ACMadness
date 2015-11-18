#include <stdio.h>
#include <stdlib.h>

int main()
{   int a[3];
    int b[3];
    int i,j,k;
    int c[3];
    i=0;
    int months,years,days1,days2,days;
    months=years=0;
    while(i<3)
    {
        scanf("%d",&a[i]);

        i++;
    }
    i=0;
     while(i<3)
    {
        scanf("%d",&b[i]);
        i++;
    }
    while(a[1]>0)
    {
        if(a[1]==1){months=months+31;}
         if(a[1]==2){if(a[2]%4==0){months=months+29;}else{months=months+28;}}
          if(a[1]==3){months=months+31;}
           if(a[1]==4){months=months+30;}
            if(a[1]==5){months=months+31;}
             if(a[1]==6){months=months+30;}
              if(a[1]==7){months=months+31;}
               if(a[1]==8){months=months+31;}
                if(a[1]==9){months=months+30;}
                 if(a[1]==10){months=months+31;}
                  if(a[1]==11){months=months+30;}
                   if(a[1]==12){months=months+31;}
                   a[1]--;
    }
    while(a[2]>0)
    {    if(a[2]%4==0)
         {
             years=years+366;

         }
        else{
        years=years+365;}
        a[2]--;
    }
    days1=years+months+a[0];
    months=years=0;
     while(b[1]>0)
    {
        if(b[1]==1){months=months+31;}
         if(b[1]==2){if(b[2]%4==0){months=months+29;}else{months=months+28;}}
          if(b[1]==3){months=months+31;}
           if(b[1]==4){months=months+30;}
            if(b[1]==5){months=months+31;}
             if(b[1]==6){months=months+30;}
              if(b[1]==7){months=months+31;}
               if(b[1]==8){months=months+31;}
                if(b[1]==9){months=months+30;}
                 if(b[1]==10){months=months+31;}
                  if(b[1]==11){months=months+30;}
                   if(b[1]==12){months=months+31;}
                   b[1]--;
    }
    while(b[2]>0)
    {    if(b[2]%4==0)
         {
             years=years+366;

         }
        else{
        years=years+365;}
        b[2]--;
    }
    days2=months+years+b[1];
    days=days2-days1;
    years=days/365;
    months=(days-years*365)/30;
    days=days-years*365-months*30;
    printf("%d days %d months %d years old",days,months,years);
    return 0;
}
