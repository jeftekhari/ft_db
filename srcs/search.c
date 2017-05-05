/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:18:27 by ssalaues          #+#    #+#             */
/*   Updated: 2017/05/04 20:11:29 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

int	db_print(t_database db, int i)
{
	printf("Table ID: %i\n", i); 
	printf("IDN: %s\n", db.db[i][0]);
	printf("NAME: %s\n", db.db[i][1]);
	printf("FAV COLOR: %s\n", db.db[i][2]);
	printf("GENDER: %s\n", db.db[i][3] );
	return (0);
}

int	search(t_database db)
{
	int		i = 0;
	char	*s;

	s = search_ask(db);
	while (db.db[i])
	{
		while (db.db[i][db.type])
		{
			if (strstr(db.db[i][db.type], s))
				return(db_print(db, i));
		db.type++;
		}
		db.type = 0;
		i++;
	}
	return (0);
}
