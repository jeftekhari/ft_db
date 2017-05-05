/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:50:28 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 11:34:45 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

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
	printf(KGRN "Complete!\n" RESET);
    return (db);
}
