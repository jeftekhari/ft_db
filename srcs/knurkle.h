/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   knurkle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeftekha <jeftekha@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 15:59:59 by jeftekha          #+#    #+#             */
/*   Updated: 2017/05/05 22:15:44 by jeftekha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KNURKLE_H
# define KNURKLE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../libs/libft/libft.h"

# define MAX_DB		100000
# define RESET		"\033[0m"
# define KNRM		"\x1B[0m"
# define KRED		"\x1B[31m"
# define KGRN		"\x1B[32m"
# define KYEL		"\x1B[33m"
# define KBLU		"\x1B[34m"
# define KMAG		"\x1B[35m"
# define KCYN		"\x1B[36m"
# define KWHT		"\x1B[37m"
# define BOLDBLACK	"\033[1m\033[30m"
# define BOLDRED	"\033[1m\033[31m"
# define BOLDGREEN	"\033[1m\033[32m"
# define BOLDWHITE	"\033[1m\033[37m"

typedef struct		s_database
{
	char			***db;
	char			idn[5];
	char			color[11];
	char			gender[3];
	char			name[26];
	int				table;
	int				row;
	int				type;
	int				rflag;
}					t_database;

void				db_write(t_database db, FILE *fp);
void				db_save(FILE *fp, t_database db);
void				wrong(int error, t_database db);
char				***init_alloc(t_database db);
void				db_store(t_database db);
t_database			info(t_database db);
t_database			readin(t_database db, FILE *fp, size_t len);
char				*search_ask(t_database *db, char *s);
int					search(t_database db);
t_database			format(t_database db, FILE *fp);
t_database			loop(t_database db);
t_database			db_delete(t_database db, FILE *fp);
char				***db_rewrite(t_database db, FILE *fp);
t_database			db_update(t_database db, FILE *fp);
int					data_check(t_database db);
t_database			error_check(t_database db, FILE *fp, int n);

#endif
