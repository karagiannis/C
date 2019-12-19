#include <stdio.h>
#include <string.h>
#include <mysql.h>


void finish_with_error(MYSQL *con)
{
	fprintf(stderr,"%s\n",mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main(int argc, char **argv)
{
	/* connection*/
	MYSQL* con = mysql_init(NULL);

        /*test if any connection*/
	if (con == NULL)
	{	
		fprintf(stderr,"%s\n",mysql_error(con));
		exit(1);
	}

	/*Really connect*/
	if(mysql_real_connect(con,"localhost","root","4-xV2h_7Simt1","testdb1",0,NULL,0)==NULL)
	{
		finish_with_error(con);
	}

	/*CREATE TABLE*/
	/*Check if table already exists*/
	if (mysql_query(con, "DROP TABLE IF EXISTS Cars"))
	{
		finish_with_error(con);
	}
	if(mysql_query(con,"CREATE TABLE Cars(ID INT, NAME TEXT, Price INT)"))
	{
		finish_with_error(con);
	}
		
	if(mysql_query(con,"INSERT INTO Cars VALUES(1,'Audi',52642)"))
	{
		finish_with_error(con);
	}
	
	if(mysql_query(con,"INSERT INTO Cars VALUES(2,'Mercedes',57127)"))
	{
		finish_with_error(con);
	}
	
	if(mysql_query(con,"INSERT INTO Cars VALUES(3,'Skoda',9000)"))
	{
		finish_with_error(con);
	}
	
	if(mysql_query(con,"INSERT INTO Cars VALUES(4,'Volvo',29000)"))
	{
		finish_with_error(con);
	}

	if(mysql_query(con,"INSERT INTO Cars VALUES(5,'Bentley',350000)"))
	{
		finish_with_error(con);
	}
	
	if(mysql_query(con,"INSERT INTO Cars VALUES(6,'Citroen',21000)"))
	{
		finish_with_error(con);
	}
	
	if(mysql_query(con,"INSERT INTO Cars VALUES(7,'Hummer',41400)"))
	{
		finish_with_error(con);
	}
	
	if(mysql_query(con,"INSERT INTO Cars VALUES(8,'Volkswagen',21600)"))
	{
		finish_with_error(con);
	}
	mysql_close(con);
	return 0;

}
