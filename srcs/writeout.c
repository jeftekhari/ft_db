/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:02:59 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/02 14:11:30 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	parser(FILE *fp, t_database db)
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
			if (ft_atoi(db.db[i][j]) == db.idn)
			{
				tmp = db.db[i][j][n];
				fprintf(fp, "%i,", tmp);
			}
			if (db.db[i][j] == db.name)
			{
				str = malloc(sizeof(char*) * 26);
				while (db.db[i][j][n])
				{
					str[n] = db.db[i][j][n];
					fprintf(fp, "%s,", str);
					n++;
				}
			}
			if (db.db[i][j] == db.gender)
			{
				str= malloc(sizeof(char*) * 3);
				while (db.db[i][j][n])
				{
					str[n] = db.db[i][j][n];
					fprintf(fp, "%s,", str);
					n++;
				}
			}
			if (ft_atoi(db.db[i][j]) == db.color)
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

void	db_write(t_database db, int n)
{
	FILE *fp;
	
	fp = fopen("knurkle.csv", "w");
	if (n == 1)
		db = re_alloc(db);
	parser(fp, db);
}

int main ()
{
	t_database	db;

	db = init_alloc(db);
	db_write(db, 0);
	return (0);
}
