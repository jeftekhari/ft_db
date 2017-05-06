/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:50:28 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 22:17:17 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

char			***assignment(t_database db, FILE *fp, char ***db1)
{
	int			i;
	int			j;

	i = 0;
	while (db.db[i])
	{
		j = 0;
		db1[i] = db.db[i];
		while (db.db[i][j])
		{
			db1[i][j] = db.db[i][j];
			fprintf(fp, "%s", db1[i][j++]);
			db1[i][j] = db.db[i][j];
			fprintf(fp, "%s", db1[i][j++]);
			db1[i][j] = db.db[i][j];
			fprintf(fp, "%s", db1[i][j++]);
			db1[i][j] = db.db[i][j];
			fprintf(fp, "%s", db1[i][j++]);
			db1[i][j] = NULL;
		}
		i++;
	}
	return (db1);
}

char			***db_rewrite(t_database db, FILE *fp)
{
	char		***db1;

	db1 = init_alloc(db);
	if (!(fp = fopen("knurkle.csv", "w")))
		wrong(3, db);
	while (db.table > 0)
	{
		db1 = assignment(db, fp, db1);
		db.table--;
	}
	return (db1);
}

t_database		delete_help(t_database db, char *s)
{
	int			i;
	int			j;

	i = 0;
	while (db.db[i])
	{
		if (strstr(db.db[i][db.type], s))
		{
			j = 0;
			ft_strclr(db.db[i][j++]);
			ft_strclr(db.db[i][j++]);
			ft_strclr(db.db[i][j++]);
			ft_strclr(db.db[i][j++]);
			j = i;
			while (db.db[j])
			{
				db.db[j] = db.db[j + 1];
				j++;
			}
		}
		i++;
	}
	return (db);
}

t_database		db_delete(t_database db, FILE *fp)
{
	char		*s;
	char		str[25];

	if (data_check(db) == 0)
		return (db);
	s = search_ask(&db, "delete");
	printf("Are you sure you want to Delete?\n");
	printf("This action %s CANNOT %s be undone.\n", KRED, RESET);
	printf("Y/N: ");
	scanf("%s", str);
	if (strstr("Y", str) || strstr("y", str))
	{
		db = delete_help(db, s);
		db.db = db_rewrite(db, fp);
	}
	return (db);
}

t_database		readin(t_database db, FILE *fp, size_t len)
{
	char		*line;
	int			b;

	b = 1;
	ft_putstr("Read In:");
	if (!(line = (char*)ft_memalloc(sizeof(char))))
		wrong(1, db);
	if (!(fp = fopen("knurkle.csv", "rb")))
		wrong(3, db);
	while (db.db[db.table] && b > 0)
	{
		db.row = 0;
		while (db.row <= 3)
		{
			b = getdelim(&line, &len, ',', fp);
			db.db[db.table][db.row++] = strdup(line);
		}
		db.table++;
	}
	db.rflag = 1;
	db.table++;
	sleep(2);
	printf(KGRN "Complete!\n" RESET);
	sleep(1);
	return (db);
}
