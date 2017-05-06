/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:18:27 by ssalaues          #+#    #+#             */
/*   Updated: 2017/05/05 19:45:53 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

int		data_check(t_database db)
{
	int i = 0;

	ft_putstr("Checking for Data.");
	sleep(1);
	ft_putstr(".");
	sleep(1);
	ft_putstr(".\n");
	if(db.db[i])
	{
		printf("Data is present!\n");
		sleep(1);
		return (1);
	}
	printf("No Data Stored, try *Reading* or *Writing* some data, you dummy!\n");
	return(0);
}

int		db_print(t_database db, int i)
{
	printf(BOLDGREEN "\nTable ID: %i\n" RESET, i); 
	printf(BOLDRED "IDN: %s\n" RESET, db.db[i][0]);
	printf(BOLDWHITE "NAME: %s\n" RESET, db.db[i][1]);
	printf(KYEL "FAV COLOR: %s\n" RESET, db.db[i][2]);
	printf(KBLU "GENDER: %s\n" RESET, db.db[i][3] );
	return (0);
}

int		search(t_database db)
{
	int		i = 0;
	char	*s;

	if (data_check(db) == 0)
		return (0);
	s = search_ask(&db, "search");
	while (db.db[i])
	{
		if (strstr(db.db[i][db.type], s))
			db_print(db, i);
		i++;
	}
	ft_putstr("\nSearch complete\n");
	return (0);
}

t_database	db_update(t_database db, FILE *fp)
{
	int		i;
	char 	*s1;
	char	*s2;

	if (data_check(db) == 0)
		return (db);
	i = 0;
	s1 = ft_strnew(30);
	printf("Enter IDN you want to update:\n");
	scanf("%s", s1);
	s2 = search_ask(&db, "update to");
	while (db.db[i])
	{
		if (strstr(db.db[i][0], s1))
		{
			if (db.type == 0)
				db.db[i][db.type] = ft_strjoin(s2, ",");
			if (db.type == 1)
				db.db[i][db.type] = ft_strjoin(s2, ",");
			if (db.type == 2)
				db.db[i][db.type] = ft_strjoin(s2, ",");
			if (db.type == 3)
				db.db[i][db.type] = ft_strjoin(s2, ",");
			db_rewrite(db, fp); 
			free(s1);
			return (db);
		}
		i++;
	}
	free(s1);
	printf("Unknown IDN");
	return (db);
}
