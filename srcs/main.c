/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:59:42 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/04 20:40:38 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

int main()
{
	t_database	db;
	char		str[25];
	FILE		*fp = NULL;

	db = init_alloc();
	while(1)
	{
		printf("Hello! What can I do for you? 'Read/Write/Search/Exit'\n");
		scanf("%s", str);
		if (strstr("exit", str) || strstr("Exit", str))
		{
			printf("So Long Mutha Fucka!\n");
			break ;
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
		printf("\nAnything Else? (Y/N):\n");
		scanf("%s", str);
		if (strstr("N", str))
		{
			printf("Bye!\n");
			break ;
		}
		if (strstr("Y", str) || strstr("y", str))
			db.table++;
	}
}
