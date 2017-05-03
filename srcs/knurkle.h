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
	int		idn;
	int		color;
	char	gender[3];
	char	name[26];
}				t_database;

void            db_write(t_database *db, int n);
void			parser(FILE *fp, t_database db);
void			wrong(int error, t_database *db);
t_database		*init_alloc(t_database *db);
t_database		*re_alloc(t_database *db);
# endif
