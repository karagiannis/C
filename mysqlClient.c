#include <stdio.h>
#include <string.h>
#include <mysql.h>

int main(int argc, char **argv)
{
	/* Get client info*/
	printf("MySQL client version: %s\n",mysql_get_client_info());

	/*Establish a connection*/
	MYSQL *con = mysql_init(NULL);

	/* test the connection 1*/
	if(con == NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(1);

	}
	
	/*test the connection 2*/
	if (mysql_real_connect(con,"localhost","root","4-xV2h_7Simt1", NULL,0,NULL,0)== NULL)
	{
		fprintf(stderr,"%s\n",mysql_error(con));
		mysql_close(con);
		exit(1);
	}

	/*Create database testdb1*/
	if (mysql_query(con,"CREATE DATABASE testdb1"))
	{
		
		fprintf(stderr,"%s\n",mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	
	mysql_close(con);
	return 0;
}
