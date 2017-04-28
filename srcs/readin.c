#include "knurkle.h"
int parse(t_db db)
{
    
    return (0);
}
int readin(t_db db)
{
    FILE    *fp;
    
    if (!(fp = fopen("knurkle.csv", "r")))
        db_write(db);
    return (0);
}
