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
	char *str;
	t_database	*db;

	if (!(db = malloc(sizeof(t_database))))
		return (-1);
	while (1)
	{
		scanf("%s", str);
		if (strstr("exit", str))
		{
			printf("So Long mutha fucka!\n");
			break ;
		}
		printf("Enter IDN");
		scanf("%i", db->idn);
		printf("Enter Name");
		scanf("%s", db->name);
		printf("Enter fav color");
		scanf("%i", db->color);
		printf("Enter Gender");
		scanf("%s", db->gender);
	}
}
