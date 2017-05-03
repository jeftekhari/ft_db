#include "knurkle.h"


/*Re-allocation of memory when a new entry is called */
t_database	re_alloc(t_database db)
{
	if (!(db.db = realloc(db.db, 15/*strlen(db->db + 1*/)))
		wrong(4, db);
	return (db);
}

/* Initial Allocation of memory for the struct and the triple array */
t_database	init_alloc(t_database db)
{
	if (!(db.db = ft_memalloc(sizeof(char*))))
		wrong(1, db);
	if (!(*db.db = ft_memalloc(sizeof(char**))))
		wrong(1, db);
	if (!(**db.db = ft_memalloc(sizeof(char***))))
		wrong(1, db);
	return (db);
}

/* Error Handling and freedom */
int		shutdown(int reason, t_database db)
{
	ft_memdel((void*)&db);
	exit(reason);
}

void	wrong(int error, t_database db)
{
	if (error == 0)
		ft_putstr("Invalid # of Args.\n");
	if (error == 1)
		ft_putstr("Malloc Failed.\n");
	if (error == 2)
		ft_putstr("Bad File.\n");
	if (error == 3)
		ft_putstr("Error Opening File");
	if (error == 4)
		ft_putstr("Bad Realloc");
	shutdown(0, db);
}
