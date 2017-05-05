/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:00:28 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/04 19:17:44 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"knurkle.h"

/* Prints Entry to File */
int	db_print(FILE *fp, t_database db)
{
	int		i = 0;
	int		j = 0;

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
	return (0);
}

/* Gets, Stores and Prints Entry to File */
void	db_write(t_database db, FILE *fp)
{
	db = info(db);
	if (!(fp = fopen("knurkle.csv", "w")))
		wrong(3, db);
		fp = fopen("knurkle.csv", "a");
	db_store(db);
	db_print(fp, db);
}
