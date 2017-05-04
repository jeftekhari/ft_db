/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 13:02:59 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/03 19:23:38 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"knurkle.h"

void	store1( t_database db)
{
	int		i = 0;
	int		j = 0;
	char	**table;

	while(db.db[i])
	{
		table = db.db[i];
		while(table[j])
		{
			table[j++] = strdup(db.idn);
			table[j++] = strdup(db.name);
			table[j++] = strdup(db.color);
			table[j++] = strdup(db.gender);
		}
		i++;
	}
}

void	parser(FILE *fp, t_database db)
{
	int		i = 0;
	int		j = 0;
	int		n = 0;
	char	*str;


	while (db.db[i])
	{
		while (db.db[i][j])
		{
				fprintf(fp, "%s,", db.idn);
				j++;
				fprintf(fp, "%s,", db.name);
				j++;
				fprintf(fp, "%s,", db.gender);
				j++;
				fprintf(fp, "%s,", db.color);
				j++;
		}
	j = 0;
	i++;
	}
}

void	db_write(t_database db, int n, FILE *fp)
{
	if (n == 0)
		db = init_alloc(db);
	if (!(fp = fopen("knurkle.csv", "w")))
		wrong(3, db);
//	if (n == 1)
//		db = re_alloc(db);
	store1(db);
	parser(fp, db);
}
