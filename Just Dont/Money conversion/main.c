#include <stdio.h>
#include <stdlib.h>

int main()
{
int var1;
int var2;
int var3;
int var4;
int var5;
int var6;
int var7;
int var8;
int var9;
int var10;
int var11;
int var12;
int var13;
int var14;
int var15;
int var16;
float var17;
printf("enter a number ");
scanf("%f",&var17);
printf("%f",var17);

    var1 = var17 * 100;
    var2 = var1 / 50000;
    var1 = var1- var2 * 50000;
    var3 = var1 / 10000;
    var1 = var1- var3 * 10000;
    var4 = var1 / 5000;
    var1 = var1- var4 * 5000;
    var5 = var1 / 2000;
    var1 = var1- var5 * 2000;
    var6 = var1 / 1000;
    var1 = var1- var6 * 1000;
    var7 = var1 / 500;
    var1 = var1- var7 * 500;
    var8 = var1 / 200;
    var1 = var1- var8 * 200;
    var9 = var1 / 100;
    var1 = var1- var9 * 100;
    var10 = var1 / 50;
    var1 = var1- var10 * 50;
    var11 = var1 / 20;
    var1 = var1- var11 * 20;
    var12 = var1 / 10;
    var1 = var1- var12 * 10;
    var13 = var1 / 5;
    var1 = var1- var13 * 5;
    var14 = var1 / 2;
    var1 = var1- var14 * 2;
    var15 = var1 / 1;
    printf("500 %d,100 %d,50 %d,20 %d, 10 %d, 5 %d, 2 %d, 1 %d, 50c %d, 20c %d, 10c %d, 5c %d, 2c %d, 1c %d from %f\n",var2, var3,var4,var5,var6,var7,var8,var9,var10,var11,var12,var13,var14,var15,var17);
    return 0;
}
