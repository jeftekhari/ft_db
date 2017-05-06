/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:59:42 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 19:08:18 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

t_database	loop(t_database db)
{
	char		str[25];

	printf("\nAnything Else? (Y/N):\n");
	scanf("%s", str);
	if (strstr("N", str) || strstr("n", str))
	{
		printf("Bye!\n");
		exit(0);
	}
	else	
		printf(KRED "BAD INPUT" RESET);
	return (db);
}

void	logo()
{
	char	c;
	FILE 	*logo;

	putchar('\n');
	if ((logo = fopen("logo", "r")))
	{
		while ((c = getc(logo)) != EOF)
			putchar(c);
	}
	putchar('\n');
	putchar('\n');
	fclose(logo);
}
t_database	format(t_database db, FILE *fp)
{
	char		str[25];
	
	printf(BOLDWHITE "Hello! What can I do for you? (Read/Write/Search/Exit/Delete)\n" RESET);
	scanf("%s", str);
	if (strstr("exit", str) || strstr("Exit", str))
	{
		printf("So Long Mutha Fucka!\n");
		exit(0) ;
	}
	else if (strstr("Write", str) || strstr("write", str))
		db_write(db, fp);
	else if (strstr("Read", str) || strstr("read", str))
		db = readin(db, fp);
	else if (strstr("Search", str) || strstr("search", str))
	{
		if (db.rflag == 1)
			search(db);
		else
			wrong(5, db);
	}
	else if (strstr("Delete", str) || strstr("delete", str) || strstr("DELETE", str))
	{
		if (db.rflag == 1)
			db_delete(db, fp);
		else
			wrong(5, db);
	}
	else if (strstr("Update", str) || strstr("update", str) || strstr("UPDATE", str))
	{
		if (db.rflag == 1)
			db = db_update(db);
		else
			wrong(5, db);
	}
	else
		printf(KRED "BAD INPUT" RESET);
	return (db);
}

int main()
{
	t_database	db;
	FILE		*fp = NULL;

	db.table = 0;
	db.rflag = 0;
	db.db = init_alloc(db);
	while(1)
	{
		logo();
		db = format(db, fp);
		db = loop(db);
	}
}
