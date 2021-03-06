/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:00:28 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 23:08:52 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"knurkle.h"

/* Prints Entry to File */
void	db_save(FILE *fp, t_database db)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (db.db[i][j])
	{
		fprintf(fp, "%s,", db.idn);
		j++;
		fprintf(fp, "%s,", db.name);
		j++;
		fprintf(fp, "%s,", db.color);
		j++;
		fprintf(fp, "%s,", db.gender);
		j++;
		db.db[i][j] = NULL;
	}
}

/* Gets, Stores and Prints Entry to File */
void	db_write(t_database db, FILE *fp)
{
	db = info(db);
	if (!(fp = fopen("knurkle.csv", "a")))
		wrong(3, db);
	db_store(db);
	db_save(fp, db);
	db.table++;
	fclose(fp);
}
