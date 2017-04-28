/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_loop_practice.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:03:42 by jeftekha          #+#    #+#             */
/*   Updated: 2017/04/27 21:34:18 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "knurkle.h"

int main()
{
	char str[25];
	t_db	db;

	while (1)
	{
		scanf("%s", str);
		if (strstr("exit", str))
		{
			printf("So Long mutha fucka!\n");
			break ;
		}
		else
		{
			printf("Enter IDN\n");
			scanf("%i", db.idn);
			printf("%i\n", *db.idn);
			printf("Enter Name\n");
			scanf("%s", db.name);
			printf("Enter fav color\n");
			scanf("%i", db.color);
			printf("Enter Gender\n");
			scanf("%s", db.gender);
		}
	}
}
