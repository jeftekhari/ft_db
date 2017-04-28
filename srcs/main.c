#include "knurkle.h"

int main()
{
	t_db	db;

	db = init_db();
	readin(db);
	while(1)
	{
		
