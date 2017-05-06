/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:18:27 by ssalaues          #+#    #+#             */
/*   Updated: 2017/05/05 18:25:53 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

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

	s = search_ask(&db, "search");
	while (db.db[i])
	{
//		while (db.db[i][db.type])
//		{
		if (strstr(db.db[i][db.type], s))
			db_print(db, i);
//		db.type++;
//		}
//		db.type = 0;
		i++;
	}
	ft_putstr("\nSearch complete\n");
	return (0);
}

t_database	db_update(t_database db)
{
	int		i;
	char 	*s1;
	char	*s2;

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
				db.db[i][db.type] = s2;
			if (db.type == 1)
				db.db[i][db.type] = s2;
			if (db.type == 2)
				db.db[i][db.type] = s2;
			if (db.type == 3)
				db.db[i][db.type] = s2;
			free(s1);
			return (db);
		}
		i++;
	}
	free(s1);
	printf("Unknown IDN");
	return (db);
}
