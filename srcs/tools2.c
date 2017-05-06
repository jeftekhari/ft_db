/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 22:35:52 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 23:05:22 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "knurkle.h"

char	*idn_help(t_database *db, char *str)
{
	db->type = 0;
	printf("Enter IDN:\n");
	scanf("%s", str);
	free(str);
	return (strdup(str));
}

char	*name_help(t_database *db, char *str)
{
	db->type = 1;
	printf("Enter Name:\n");
	scanf("%s", str);
	free(str);
	return (strdup(str));
}

char	*color_help(t_database *db, char *str)
{
	db->type = 2;
	printf("Enter Color:\n");
	scanf("%s", str);
	free(str);
	return (strdup(str));
}

char	*gender_help(t_database *db, char *str)
{
	db->type = 3;
	printf("Enter Gender:\n");
	scanf("%s", str);
	free(str);
	return (strdup(str));
}

char	*search_ask(t_database *db, char *s)
{
	char str[25];

	db->type = 0;
	printf("What do you want to %s?\n(IDN, Name, Color, Gender)\n", s);
	scanf("%s", str);
	if (strstr("IDN", str) || strstr("Idn", str) || strstr("idn", str))
		return (idn_help(db, strdup(str)));
	else if (strstr("Name", str) || strstr("name", str))
		return (name_help(db, strdup(str)));
	else if (strstr("Color", str) || strstr("color", str))
		return (color_help(db, strdup(str)));
	else if (strstr("Gender", str) || strstr("gender", str))
		return (gender_help(db, strdup(str)));
	else
		wrong(6, *db);
	return (0);
}
