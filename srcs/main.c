#include "knurkle.h"

int main()
{
	t_database	db;
	char		str[25];
	FILE		*fp;

	readin(db, fp);
	db = init_alloc(db);
	while(1)
	{
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
		parser(fp, db);
		printf("Anything Else? (Y/N):\n");
		if (strstr("N", str))
		{
			printf("Bye!\n");
			break ;
		}
		if (strstr("Y", str))
		{
			re_alloc(db);
			parser(fp, db);
		}
	}
}
