#include <stdio.h>
#include <stdlib.h>

int main()
{
     FILE *fp;
   double *a;
   double *b;
   double aa;
   double bb;
   a=&aa;
   b=&bb;
   aa=5;

   /* Open file for both reading and writing */
   fp = fopen("file.txt", "w+");

   /* Write data to the file */
   fwrite(a, sizeof(double), 1, fp);

   /* Seek to the beginning of the file */
   fseek(fp, SEEK_SET, 0);

   /* Read and display data */
   fread(b, sizeof(double), 1, fp);
   printf("%f\n", bb);
   fclose(fp);
    return 0;
}
