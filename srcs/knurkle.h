#ifndef		KNURKLE_H
# define		KNURKLE_H
# include	<sys/types.h>
# include	<sys/uio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include	<string.h>
# include	<math.h>

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
	char	*gender;
	char	*name;
}				t_database;

# endif
