/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:18:27 by ssalaues          #+#    #+#             */
/*   Updated: 2017/05/04 19:16:14 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

int	search_int(t_database db, char *s)
{
}

int	search(t_database db, int v, char *s)
{
	int	i = 0;
	int	j = 0;

	while (db[i])
	{
		
		while (db[i][v])
		{
			if (strstr(db[i][v], s))
				return(print_db(db, i, v));
		v++;
		}
		v = 0;
		i++;
	}
}
