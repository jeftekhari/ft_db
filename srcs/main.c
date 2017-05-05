/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:59:42 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/04 19:12:04 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

int main()
{
	t_database	db;
	char		str[25];
	FILE		*fp = NULL;

	db = init_alloc();
	db.table = 0;
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
			readin(db, fp);
		if (strstr("Search", str) || strstr("search", str))
			search(db, fp);
		printf("Anything Else? (Y/N):\n");
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
