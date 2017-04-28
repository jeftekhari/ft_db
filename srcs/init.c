#include "knurkle.h"

t_db	*init_db(void)
{
	t_db	*db;

	if (!(db = ft_memalloc(sizeof(t_fdf))))
		wrong(MALLOC_FAILED, db);
	return (db);
}
