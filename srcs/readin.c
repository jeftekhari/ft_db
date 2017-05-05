/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:50:28 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 14:17:11 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

char	***db_rewrite(t_database db, FILE *fp, int i)
{
	char	***db1;
	int		j;

	db1 = init_alloc();
//	ft_memdel(db.db[i]);
	if (!(fp = fopen("knurkle.csv", "w")))
		wrong(3, db);
	i = 0;
	while (db.table > 0)
	{
		while (db.db[i])
		{
			j = 0;
			db1[i] = db.db[i];
			while(db.db[i][j])
			{
				db1[i][j] = db.db[i][j];
				j++;
			}
			i++;
		}
		db.table--;
	}
}

	

t_database	db_delete(t_database, FILE *fp)
{
	char	*s;
	char	str[25];
	int		i = 0;

	s = search_ask(&db);
	printf("Are you sure you want to Delete?\n");
	printf("This action %s CANNOT %s be undone", KRED, RESET);
	printf("Y/N");
	scanf("%s", str);
	if (strstr("Y", str))
	{
		while (db.db[i])
		{
			if (strstr(db.db[i][db.type], s))
				db.db = db_rewrite(db, fp, i);
			i++;
		}
	}
}

t_database	readin(t_database db, FILE *fp)
{
	char	*line;
	int		b = 1;
	size_t	len = 100000;

	printf("Read In:");
	if (!(line = (char*)ft_memalloc(sizeof(char))))
		wrong(1, db);
	if (!(fp = fopen("knurkle.csv", "rb")))
		wrong(3, db);
	while (db.db[db.table] && b > 0)
	{
		db.row = 0;
		while (db.row <= 3)
		{
			b = getdelim(&line , &len, ',', fp);
			db.db[db.table][db.row++] = strdup(line);
		}
		db.table++;
	}
	db.rflag = 1;
	db.table++;
	printf(KGRN "Complete!\n" RESET);
    return (db);
}
