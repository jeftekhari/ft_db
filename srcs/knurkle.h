/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knurkle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:59:59 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 14:11:43 by jeftekha         ###   ########.fr       */
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
#define RESET   "\033[0m"
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

typedef struct	s_database
{
	char	***db;
	char	idn[5];
	char	color[11];
	char	gender[3];
	char	name[26];
	int		table;
	int		row;
	int		type;
	int		rflag;
}				t_database;

void            db_write(t_database db, FILE *fp);
void			db_save(FILE *fp, t_database db);
void			wrong(int error, t_database db);
char			***init_alloc(t_database db);
void			db_store(t_database db);
t_database		info(t_database db);
t_database		readin(t_database db, FILE *fp);
char			*search_ask(t_database *db);
int				search(t_database db);
t_database		format(t_database, FILE *fp);
t_database		loop(t_database);
//int				db_store(t_database db, FILE *fp);
# endif
