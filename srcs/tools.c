#include "knurkle.h"


/*Re-allocation of memory when a new entry is called */
t_database	re_alloc(t_database db)
{
	if (!(db.db = realloc((void*)db.db, db.row + 1)))
		wrong(4, db);
	db.row++;
	return (db);
}

/* Initial Allocation of memory for the struct and the triple array */
t_database	init_alloc(void)
{
	t_database	db;

	if (!(db.db = (char***)ft_memalloc(sizeof(char**) * 100)))
		wrong(1, db);
	for (int i = 0; i < 100; i++)
	{
		if (!(db.db[i] = (char**)ft_memalloc(sizeof(char*) * 5)))
			wrong(1, db);
		for (int j = 0; j < 5; j++)
		{
			if (!(db.db[i][j] = (char*)ft_memalloc(sizeof(char) * 30)))
				wrong(1, db);
		}
	}
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
