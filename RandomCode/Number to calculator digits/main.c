#include <stdio.h>
#include <stdlib.h>
#include <math.h>

intpower(int a,int b){if(b!=0){int i;
i=1;int c;c=a;
while(i<b){a=a*c;i++;}return a;}
else{a=1; return a;}}


int main()
{   int a,b,c,d,i,s,e,f;
    printf("Enter number for normalization:\n");
    scanf("%d",&a);
    i=1;
    c=0;
    while(d!=0){d=a/pow(10,i);
    i++;
    c++;}
    printf("Enter size of numbers:\n");
    scanf("%d",&s);
    b=1;
    i=1;
    e=a;
    f=1;

        if(i==1){
    while(b<=c){
    d=1;
    if(a/intpower(10,c-b)==1){printf(" ");while(d<=s){printf(" ");d++;}printf(" ");}
     if(a/intpower(10,c-b)==2){printf("_");while(d<=s){printf("_");d++;}printf("_");}
      if(a/intpower(10,c-b)==3){printf("_");while(d<=s){printf("_");d++;}printf("_");}
       if(a/intpower(10,c-b)==4){printf(" ");while(d<=s){printf(" ");d++;}printf(" ");}
        if(a/intpower(10,c-b)==5){printf("_");while(d<=s){printf("_");d++;}printf("_");}
         if(a/intpower(10,c-b)==6){printf("_");while(d<=s){printf("_");d++;}printf("_");}
          if(a/intpower(10,c-b)==7){printf("_");while(d<=s){printf("_");d++;}printf("_");}
           if(a/intpower(10,c-b)==8){printf("_");while(d<=s){printf("_");d++;}printf("_");}
            if(a/intpower(10,c-b)==9){printf("_");while(d<=s){printf("_");d++;}printf("_");}
             if(a/intpower(10,c-b)==0){printf("_");while(d<=s){printf("_");d++;}printf("_");}
     printf(" ");a=a-(a/intpower(10,c-b))*intpower(10,c-b); b++;
    }i++;printf("\n");}
    a=e;b=1;
    if(i==2){while(f<s){b=1;a=e;
   while(b<=c){d=1;
    if(a/intpower(10,c-b)==1){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
     if(a/intpower(10,c-b)==2){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
      if(a/intpower(10,c-b)==3){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
       if(a/intpower(10,c-b)==4){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
        if(a/intpower(10,c-b)==5){printf("|");while(d<=s){printf(" ");d++;}printf(" ");}
         if(a/intpower(10,c-b)==6){printf("|");while(d<=s){printf(" ");d++;}printf(" ");}
          if(a/intpower(10,c-b)==7){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
           if(a/intpower(10,c-b)==8){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
            if(a/intpower(10,c-b)==9){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
             if(a/intpower(10,c-b)==0){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
             a=a-(a/intpower(10,c-b))*intpower(10,c-b);b++;printf(" ");}printf("\n");f++;}
            if(f==s){b=1;a=e;while(b<=c){d=1;
    if(a/intpower(10,c-b)==1){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
     if(a/intpower(10,c-b)==2){printf(" ");while(d<=s){printf("_");d++;}printf("|");}
      if(a/intpower(10,c-b)==3){printf(" ");while(d<=s){printf("_");d++;}printf("|");}
       if(a/intpower(10,c-b)==4){printf("|");while(d<=s){printf("_");d++;}printf("|");}
        if(a/intpower(10,c-b)==5){printf("|");while(d<=s){printf("_");d++;}printf(" ");}
         if(a/intpower(10,c-b)==6){printf("|");while(d<=s){printf("_");d++;}printf(" ");}
          if(a/intpower(10,c-b)==7){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
           if(a/intpower(10,c-b)==8){printf("|");while(d<=s){printf("_");d++;}printf("|");}
            if(a/intpower(10,c-b)==9){printf("|");while(d<=s){printf("_");d++;}printf("|");}
             if(a/intpower(10,c-b)==0){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
             a=a-(a/intpower(10,c-b))*intpower(10,c-b);b++;printf(" ");}i++;printf("\n");}
             }
             f=1;
    if(i==3){while(f<s){b=1;a=e;
   while(b<=c){d=1;
    if(a/intpower(10,c-b)==1){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
     if(a/intpower(10,c-b)==2){printf("|");while(d<=s){printf(" ");d++;}printf(" ");}
      if(a/intpower(10,c-b)==3){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
       if(a/intpower(10,c-b)==4){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
        if(a/intpower(10,c-b)==5){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
         if(a/intpower(10,c-b)==6){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
          if(a/intpower(10,c-b)==7){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
           if(a/intpower(10,c-b)==8){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
            if(a/intpower(10,c-b)==9){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
             if(a/intpower(10,c-b)==0){printf("|");while(d<=s){printf(" ");d++;}printf("|");}
             a=a-(a/intpower(10,c-b))*intpower(10,c-b);b++;printf(" ");}printf("\n");f++;}i++;}
      if(f==s){b=1;a=e;while(b<=c){d=1;
    if(a/intpower(10,c-b)==1){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
     if(a/intpower(10,c-b)==2){printf("|");while(d<=s){printf("_");d++;}printf(" ");}
      if(a/intpower(10,c-b)==3){printf(" ");while(d<=s){printf("_");d++;}printf("|");}
       if(a/intpower(10,c-b)==4){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
        if(a/intpower(10,c-b)==5){printf(" ");while(d<=s){printf("_");d++;}printf("|");}
         if(a/intpower(10,c-b)==6){printf("|");while(d<=s){printf("_");d++;}printf("|");}
          if(a/intpower(10,c-b)==7){printf(" ");while(d<=s){printf(" ");d++;}printf("|");}
           if(a/intpower(10,c-b)==8){printf("|");while(d<=s){printf("_");d++;}printf("|");}
            if(a/intpower(10,c-b)==9){printf(" ");while(d<=s){printf("_");d++;}printf("|");}
             if(a/intpower(10,c-b)==0){printf("|");while(d<=s){printf("_");d++;}printf("|");}
             a=a-(a/intpower(10,c-b))*intpower(10,c-b);b++;printf(" ");}i++;printf("\n");}
























    return 0;}

