/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:50:28 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/04 17:32:32 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

int readin(t_database db, FILE *fp)
{
	char	*line;
	size_t	len = 1;

	if (!(line = (char*)ft_memalloc(sizeof(char))))
		wrong(1, db);
	if (!(fp = fopen("knurkle.csv", "rb")))
		wrong(3, db);
	while (db.db[db.table])
	{
		db.row = 0;
		while (db.row <= 3)
		{
			getdelim(&line , &len, ',', fp);
			db.db[db.table][db.row++] = strdup(line);
		}
		db.table++;
	}
    return (0);
}
