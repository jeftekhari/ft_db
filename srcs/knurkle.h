/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knurkle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:59:59 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/04 19:18:08 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		KNURKLE_H
# define		KNURKLE_H
# include	<sys/types.h>
# include	<sys/uio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<string.h>
# include	<math.h>
# include	"../libs/libft/libft.h"

/*
 *
 *
 *
 *
 * ROOM FOR PROTOTYPES AND STRUCTS
 * */

typedef struct	s_database
{
	char	***db;
	char	idn[5];
	char	color[11];
	char	gender[3];
	char	name[26];
	int		table;
	int		row;
}				t_database;

void            db_write(t_database db, FILE *fp);
int				db_print(FILE *fp, t_database db);
void			wrong(int error, t_database db);
t_database		init_alloc(void);
void			db_store(t_database db);
t_database		info(t_database db);
int				readin(t_database db, FILE *fp);
//int				db_store(t_database db, FILE *fp);
# endif
