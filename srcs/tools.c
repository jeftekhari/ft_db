#include "knurkle.h"

int	shutdown(int reason, t_db db)
{
	ft_memdel((void*)&db;
	exit(reason);
}

void	wrong(int error, t_db *db)
{
	if (error == 0)
		ft_putstr("Invalid # of Args.\n");
		ft_putstr("");
	if (error == 1)
		ft_putstr("Malloc Failed.\n");
	if (error == 2)
		ft_putstr("Bad File.\n");
	shutdown(0, db);
}
