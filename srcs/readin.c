#include "knurkle.h"

// I only commented some stuff out to test the main function. READ THE README IF YOU WANT TO KNOW MY THOUGHT PROCESS!//
int store(t_database db)
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
int readin(t_database db, FILE *fp)
{
   // if (!(fp = fopen("knurkle.csv", "rb")))
//		db_write(db, 0);
//	else
	//	store(db);
    return (0);
}
