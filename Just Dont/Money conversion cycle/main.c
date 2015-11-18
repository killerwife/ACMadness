#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i;
int i_max;
int i_increment;
i = 1;
i_increment = 1;
i_max = 1000000;
    while(i <= i_max){

    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    int var6;
    int var7;
    var7 = 0;
    var4 = 0;
    var5 = 0;
    var6 = 0;
    var1 = 0;
      var2 = 0;
        var3 = 0;
    if(i<10)
    {
        var1 = i;
        var7 = var1;
    }
    if(i<100&&i>9){
    var2 = i/10;
    var3 = (i- var2*10);
    var7 = var2*var2 + var3*var3;

    }
 if(i<1000&&i>99){
    var1 = i / 100;
    var2 = (i - var1*100)/ 10;
    var3 = i - (var2*10 +var1*100);
    var7 = var4*var4*var4 + var3*var3*var3 + var2*var2*var2 + var1*var1*var1;
 }

    if(i<10000&&i>999){
    var4 = i/ 1000;
    var1 = (i - var4*1000)/100;
    var2 = (i - var1*100 - var4*1000)/ 10;
    var3 = i - (var2*10 +var1*100 + var4*1000);
    var7 = var4*var4*var4*var4 + var3*var3*var3*var3 + var2*var2*var2*var2 + var1*var1*var1*var1;
    }

if(i<100000&&i>9999)
    {
    var5 = i / 10000;
    var4 = (i-var5*10000)/ 1000;
    var1 = (i - var4*1000 - var5*10000)/100;
    var2 = (i - var1*100- var5*10000 - var4*1000)/ 10;
    var3 = i - (var2*10 +var1*100 + var4*1000 + var5*10000);
     var7 = var4*var4*var4*var4*var4 + var3*var3*var3*var3*var3 + var2*var2*var2*var2*var2 + var1*var1*var1*var1*var1 + var5*var5*var5*var5*var5;
    }
    if(i<1000000&&i>99999)
    {
    var6 = i / 100000;
    var5 = (i - var6*100000) / 10000;
    var4 = (i - var5*10000 - var6*100000)/ 1000;
    var1 = (i - var4*1000 - var5*10000 - var6*100000)/100;
    var2 = (i - var1*100- var5*10000 - var4*1000 - var6*100000)/ 10;
    var3 = i - (var2*10 +var1*100 + var4*1000 + var5*10000 + var6*100000);
     var7 = var4*var4*var4*var4*var4*var4 + var3*var3*var3*var3*var3*var3 + var2*var2*var2*var2*var2*var2 + var1*var1*var1*var1*var1*var1 + var5*var5*var5*var5*var5*var5+ var6*var6*var6*var6*var6*var6;
    }


    +  var5*var5*var5+ var6*var6*var6;
    if (var7 == i)
{


    printf("%d\n",i);
}


    i= i++;

    }
    return 0;
}
