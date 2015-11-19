#include <stdio.h>
#include <stdlib.h>

int main()
{   int **database;
    FILE *DB;
    int *friends;
    int numberoffriends;
    int i=0;
    int j=0;
    int k=0;
    int l=0;
    int friendsoffriends=0;
    int *friendsnumberoffriends;
    DB=fopen("Database.txt","r");
    fscanf(DB,"%d",&numberoffriends);
    friends=(int) malloc(sizeof(int)*numberoffriends);
    friendsnumberoffriends=(int) malloc(sizeof(int)*numberoffriends);
    database=(int *) malloc(sizeof(int*)*numberoffriends);
    while(i<numberoffriends)
    {
        fscanf(DB,"%d",&friends[i]);
        fscanf(DB,"%d",&friendsnumberoffriends[i]);
        database[i]=(int) malloc(sizeof(int)*friendsnumberoffriends[i]);
        while(j<friendsnumberoffriends[i])
        {
            fscanf(DB,"%d",&database[i][j]);
            j++;
        }
        j=0;
        i++;
    }
    i=j=0;
    while(i<numberoffriends)
    {
      while(k<numberoffriends)
      {
          while(j<friendsnumberoffriends[k])
          {
              if(database[k][j]==friends[i])
              {
                  database[k][j]=0;
              }
              j++;
          }
          j=0;
          k++;
      }
      k=0;
      i++;
    }
    i=0;
    while(i<numberoffriends)
    {

      while(l<friendsnumberoffriends[i])
      {
        k=i+1;
        while(k<numberoffriends)
        {
          while(j<friendsnumberoffriends[k])
          {
              if(database[k][j]==database[i][l])
              {
                  database[k][j]=0;
              }
              j++;
          }
          j=0;
          k++;
        }
        l++;
       }
      l=0;
      i++;

    }
    i=j=0;
    printf("%d\n",numberoffriends);
    while(i<numberoffriends)
    {
        printf("%d ",friends[i]);
        printf("%d ",friendsnumberoffriends[i]);

        while(j<friendsnumberoffriends[i])
        {
            printf("%d ",database[i][j]);
            if(database[i][j]!=0)
            {
                friendsoffriends++;
            }
            j++;
        }
        j=0;
        printf("\n");
        i++;
    }
    printf("%d",friendsoffriends);
    return 0;
}
