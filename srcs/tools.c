/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 16:01:06 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/04 19:50:13 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"


char	*search_ask(t_database db)
{
	char str[25];

	db.type = 0;
	printf("How do you want to search?\n(IDN, Name, Color, Gender)");
	scanf("%s", str);
	if (strstr("IDN", str) || strstr("Idn", str) || strstr("idn", str))
	{
		db.type = 1;
		printf("Enter IDN");
		scanf("%s", str);
		return(strdup(str));
	}
	 if (strstr("NAME", str) || strstr("Name", str) || strstr("name", str))
	 {
		db.type = 2;
		printf("Enter Name");
		scanf("%s", str);
		return(strdup(str));
	 }
	if (strstr("COLOR", str) || strstr("Color", str) || strstr("color", str))
	{
		db.type = 3;
		printf("Enter Color");
		scanf("%s", str);
		return(strdup(str));
	}
	if (strstr("GENDER", str) || strstr("Gender", str) || strstr("gender", str))
	{
		db.type = 4;
		printf("Enter Gender");
		scanf("%s", str);
		return(strdup(str));
	}
	return (0);
}

/* Used on entry creation. User enters in key information into struct variables */
t_database	info(t_database db)
{
	printf("Enter IDN:\n");
	scanf("%s", db.idn);
	printf("Enter Name:\n");
	scanf("%s", db.name);
	printf("Enter Favorite Color:\n");
	scanf("%s", db.color);
	printf("Enter Gender:\n");
	scanf("%s", db.gender);
	return (db);
}

/* Stores data into 3d array, use db.table to move throughout*/
void	db_store( t_database db)
{
	int		j = 0;
	
	db.db[db.table][j++] = strdup(db.idn);
	db.db[db.table][j++] = strdup(db.name);
	db.db[db.table][j++] = strdup(db.color);
	db.db[db.table][j++] = strdup(db.gender);
}

/* Initial Allocation of memory for the struct and the triple array */
t_database	init_alloc(void)
{
	t_database	db;

	if (!(db.db = (char***)ft_memalloc(sizeof(char**) * 100)))
		wrong(1, db);
	for (int i = 0; i < 100; i++)
	{
		if (!(db.db[i] = (char**)ft_memalloc(sizeof(char*) * 5)))
			wrong(1, db);
		for (int j = 0; j < 5; j++)
		{
			if (!(db.db[i][j] = (char*)ft_memalloc(sizeof(char) * 30)))
				wrong(1, db);
		}
	}
	return (db);
}

/* Error Handling and freedom */
int		shutdown(int reason, t_database db)
{
	ft_memdel((void*)&db);
	exit(reason);
}

void	wrong(int error, t_database db)
{
	if (error == 0)
		ft_putstr("Invalid # of Args.\n");
	if (error == 1)
		ft_putstr("Malloc Failed.\n");
	if (error == 2)
		ft_putstr("Bad File.\n");
	if (error == 3)
		ft_putstr("Error Opening File");
	if (error == 4)
		ft_putstr("Bad Realloc");
	shutdown(0, db);
}
