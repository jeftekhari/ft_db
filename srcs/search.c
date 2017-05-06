/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:18:27 by ssalaues          #+#    #+#             */
/*   Updated: 2017/05/05 17:32:15 by ssalaues         ###   ########.fr       */
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
	int i = 0;
	char *s;

	s = search_ask(&db, "update");
	while (db.db[i])
	{
		if (strstr(db.db[i][db.type], s))
		{
			if (db.type == 0)
				db.db[i][db.type] = db.idn;
			if (db.type == 1)
				db.db[i][db.type] = db.name;
			if (db.type == 2)
				db.db[i][db.type] = db.color;
			if (db.type == 3)
				db.db[i][db.type] = db.gender;
		}
		i++;
	}
	return (db);
}
