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

void            db_write(t_database db, int n, FILE *fp);
void			parser(FILE *fp, t_database db);
void			wrong(int error, t_database db);
t_database		init_alloc(t_database db);
int				readin(t_database db, FILE *fp);
int				store(t_database db);
t_database		re_alloc(t_database db);
# endif
