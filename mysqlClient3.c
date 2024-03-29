#include <stdio.h>
#include <string.h>
#include <mysql.h>

/*RETRIEVING DATA FROM DATABASE*/

void finish_with_error(MYSQL* con)
{ 
	fprintf(stderr,"%s\n",mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main(int argc, char** argv)
{

	MYSQL *con = mysql_init(NULL);
	if(con == NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(1);
	}
	
	if(mysql_real_connect(con,"localhost","root","4-xV2h_7Simt1","testdb1",0,NULL,0)== NULL)
	{
		finish_with_error(con);
	}

	if(mysql_query(con, "SELECT * FROM Cars"))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);
	
	if(result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	
	MYSQL_ROW row;

	while ((row = mysql_fetch_row(result)))
	{
		for(int i = 0; i < num_fields;i++)
			printf("%s\t\t", row[i] ? row[i] : "NULL");
		printf("\n");
	}

	mysql_free_result(result);

	mysql_close(con);

	return 0;
}
