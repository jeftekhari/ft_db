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
	int	idn[25];
	int	color[25];
	char	gender[3];
	char	name[26];
}				t_db;

void            db_write(t_db);
# endif
