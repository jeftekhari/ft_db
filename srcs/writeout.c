/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:02:59 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/04 15:10:33 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"knurkle.h"

void	store1( t_database db)
{
	int		j = 0;
	
	db.db[db.table][j++] = strdup(db.idn);
	db.db[db.table][j++] = strdup(db.name);
	db.db[db.table][j++] = strdup(db.color);
	db.db[db.table][j++] = strdup(db.gender);
}

void	parser(FILE *fp, t_database db)
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
}

void	db_write(t_database db, FILE *fp)
{
//	if (n == 0)
//		db = init_alloc(db);
	if (!(fp = fopen("knurkle.csv", "w")))
		wrong(3, db);
//	if (n == 1)
		fp = fopen("knurkle.csv", "a");
//		db = re_alloc(db);
	store1(db);
	parser(fp, db);
}
