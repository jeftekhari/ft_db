#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"knurkle.h"


//int main()
//{
//	FILE *fp;
//	fp = fopen("hello.csv", "w");
//
//	fprintf(fp, "This is a test\n");
///////
//	fclose(fp);
//
//	return (0);
//}
//

void	parser(FILE *fp, t_db db)
{
	int		i = 0;
	int		j = 0;
	int		n = 0;
	char	*str;
	int		tmp;


	while (db.db[i])
	{
		while (db.db[i][j])
		{
			if (db.db[i][j] == db.idn)
			{
				tmp = db.db[i][j][n];
				fprintf(fp, "%i,", tmp);
			}
			if (db.db[i][j] == db.name)
			{
				str = malloc(sizeof(char*) * 26);
				while (db.db[i][j][n])
				{
					str[n] = db.db[i][j][n++];
					fprintf(fp, "%s,", str);
				}
			}
			if (db.db[i][j] == db.gender)
			{
				str= malloc(sizeof(char*) * 3);
				while (db.db[i][j][n])
				{
					str[n] = db.db[i][j][n++];
					fprintf(fp, "%s,", str);
				}
			}
			if (db.db[i][j] == db.color)
			{
				tmp = db.db[i][j][n];
				fprintf(fp, "%i,", tmp);
			}
		n = 0;
		j++;
		}
	j = 0;
	i++;
	}
}

void	db_write(t_db db)
{
	FILE *fp;
	
	fp = fopen("knurkle. csv", "w");

	parser(fp, db);
}

int main ()
{
	t_database db;
	db_write(db);
	return (0);
}