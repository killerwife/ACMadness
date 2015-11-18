#include <stdio.h>
#include <stdlib.h>

void swapping(unsigned int *a,unsigned int *b)
{
    int swaptemp;
    swaptemp=*a;
    *a=*b;
    *b=swaptemp;

}

void insertionsort(unsigned int *sortingarray,int *elementnumber)
{
    int i,j;j=1;
    while(j<*elementnumber)
    {
      i=j-1;
      while(i>=0)
      {
          if(sortingarray[i]>sortingarray[i+1])
          {
              swapping(&sortingarray[i],&sortingarray[i+1]);
              i--;
          }
          else{break;}

      }
      j++;
    }
}



int main()
{
    char input=' ';
    unsigned int words[13];
    while(input!=EOF&&(input=fgetc(stdin))!=EOF)
    {
        int num=1;
        int i,k;
        int check=0;
        unsigned int hash;
        ungetc(input,stdin);
        for(i=0;i<13;i++)
        {
            words[i]=0;
        }
        while((input=fgetc(stdin))!='\n'&&input!=EOF)
        {
            if(input==' ')
            {
                check=1;
            }
            else
            {
                if(check==1)
                {
                    num++;
                    check=0;
                }
                words[num-1]*=32;
                words[num-1]+=input-'a'+1;
            }
            printf("%c",input);
        }
        printf("\n");
        insertionsort(words,&num);
        hash=1;
        check=0;
        while(check==0)
        {
            check=1;
            for(i=0;i<num&&check==1;i++)
            {
                for(k=i+1;k<num&&check==1;k++)
                {
                    if(words[i]<words[k])
                    {
                        if((hash/words[i])%num==(hash/words[k])%num)
                        {
                            check=0;
                            if((hash/words[i]+1)*words[i]<(hash/words[k]+1)*words[k])
                            {
                                hash=(hash/words[i]+1)*words[i];
                            }
                            else
                            {
                                hash=(hash/words[k]+1)*words[k];
                            }
                        }
                    }
                }
            }
        }
        printf("%u\n\n",hash);

    }
    return 0;
}
