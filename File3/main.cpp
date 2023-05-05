#include "database/data.h"
#include "database/sql/sql.h"
#include "entity/line.h"

int main()
{
    function_sql();
    function_data();

    Line line{{100, 100}, {500, 500}};

    return 0;
}
