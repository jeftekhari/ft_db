/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:18:27 by ssalaues          #+#    #+#             */
/*   Updated: 2017/05/04 19:43:52 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

int	db_print()
{
	return (0);
}

int	search(t_database db)
{
	int	i = 0;
	int	j = 0;

	while (db[i])
	{
		
		while (db[i][db.type])
		{
			if (strstr(db[i][db.type], s))
				return(print_db(db, i, db.type));
		db.type++;
		}
		db.type = 0;
		i++;
	}
}
