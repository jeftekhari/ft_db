#include "knurkle.h"
int store(t_db db)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (db.db[i])
    {
      j = 0;
      while (db.db[i][j])
      {
          k = 0;
          while (db.db[i][j][k])
          {
              //add data
              //k++;
          }
          j++;
      } 
      i++;
    }
    
    return (0);
}
int readin(t_db db)
{
   FILE    *fp;
    
    if (!(fp = fopen("knurkle.csv", "rb")))
    {
        printf("Error 52");
        exit(0);
    }
    return (0);
}
