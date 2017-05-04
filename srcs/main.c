#include "knurkle.h"

int main()
{
	t_database	db;
	char		str[25];
	FILE		*fp;
	int			n = 0;

//	db = init_alloc(db);
	while(1)
	{
//		readin(db, fp);
		printf("Hello! What can I do for you? (If done type 'exit')\n");
		scanf("%s", str);
		if (strstr("exit", str))
		{
			printf("so Long Mutha Fucka!\n");
			break ;
		}
		else
		{
			printf("Enter IDN:\n");
			scanf("%s", db.idn);
			printf("Enter Name:\n");
			scanf("%s", db.name);
			printf("Enter Favorite Color:\n");
			scanf("%s", db.color);
			printf("Enter Gender:\n");
			scanf("%s", db.gender);
		}
//		parser(fp, db);
		if (n == 1)
			db_write(db, 1, fp);
		else
			db_write(db, 0, fp);
		printf("Anything Else? (Y/N):\n");
		scanf("%s", str);
		if (strstr("N", str))
		{
			printf("Bye!\n");
			break ;
		}
		if (strstr("Y", str))
			n = 1;
	}
}
