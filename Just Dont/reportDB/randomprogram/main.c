#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int serviceID;
  int customerID;
  int bitmaskday;
  int secondsstart;
  int length_data;

} reports;

typedef struct
{
   int serviceID;
   int type;
   int price;
   int callfrom;
   int callto;
   int servicetime;

} service;


int main()
{   char b;
    int i,j,k;
    char scanning[5];
    int servicerows,reportrows;
    service *servicedb;
    reports *reportdb;
    i=1;
    j=0;
    FILE *report;
    FILE *services;
    report=fopen("report.txt","r");
    services=fopen("services.txt","r");
    while(b)
    {
        b=getc(services);
        if(b==10){i++;}
        if(b==EOF){break;}
    }
    fseek(services,0,SEEK_SET);
    servicerows=i;
    servicedb=(service*) malloc(sizeof(service)*(servicerows/6));
    i=0;
    while(i<servicerows)
    {
        fscanf(services,"%d",&servicedb[j].serviceID);
        i++;
        while(getc(services)!='\n');
        fscanf(services,"%s",scanning);
        if(scanning[0]=='c'){servicedb[j].type=0;}
        if(scanning[0]=='d'){servicedb[j].type=1;}
        if(scanning[0]=='S'){servicedb[j].type=2;}
        i++;
        while(getc(services)!='\n');
        fscanf(services,"%d",&servicedb[j].price);
        i++;
        while(getc(services)!='\n');
        fscanf(services,"%d",&servicedb[j].callfrom);
        i++;
        while(getc(services)!='\n');
        fscanf(services,"%d",&servicedb[j].callto);
        i++;
        while(getc(services)!='\n');
        fscanf(services,"%d",&servicedb[j].servicetime);
        i++;
        while(b)
        {
            b=getc(services);
            if(b=='\n'||b==EOF){break;}
        }
        j++;
    }
    j=0;
    i=1;
     while(b)
    {
        b=getc(report);
        if(b==10){i++;}
        if(b==EOF){break;}
    }
    fseek(report,0,SEEK_SET);
    reportrows=i;
    reportdb=(reports*) malloc(sizeof(reports)*(reportrows/5));
    i=0;
    while(i<reportrows)
    {
        fscanf(report,"%d",&reportdb[j].serviceID);
        i++;
         fscanf(report,"%d",&reportdb[j].customerID);
          i++;
          fscanf(report,"%d",&reportdb[j].bitmaskday);
           i++;
           fscanf(report,"%d",&reportdb[j].secondsstart);
            i++;
            fscanf(report,"%d",&reportdb[j].length_data);
            i++;
            j++;
    }

    fclose(servicedb);
    fclose(reportdb);
    return 0;
}
