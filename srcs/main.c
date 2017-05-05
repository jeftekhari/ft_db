/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:59:42 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 12:12:25 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

t_database	loop(t_database db)
{
	char		str[25];

	printf("\nAnything Else? (Y/N):\n");
	scanf("%s", str);
	if (strstr("N", str))
	{
		printf("Bye!\n");
		exit(0);
	}
	if (strstr("Y", str) || strstr("y", str))
		db.table++;
	return (db);
}

t_database	format(t_database db, FILE *fp)
{
	char		str[25];

	printf("Hello! What can I do for you? 'Read/Write/Search/Exit'\n");
	scanf("%s", str);
	if (strstr("exit", str) || strstr("Exit", str))
	{
		printf("So Long Mutha Fucka!\n");
		exit(0) ;
	}
	if (strstr("Write", str) || strstr("write", str))
		db_write(db, fp);
	if (strstr("Read", str) || strstr("read", str))
		db = readin(db, fp);
	if (strstr("Search", str) || strstr("search", str))
	{
		if (db.rflag == 1)
			search(db);
		else
			wrong(5, db);
	}
	return (db);
}



int main()
{
	t_database	db;
	FILE		*fp = NULL;

	db = init_alloc();
	while(1)
	{
		db = format(db, fp);
		db = loop(db);
	}
}
