#include <stdio.h>
#include <string.h>
#include <mysql.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

/*RETRIEVING DATA FROM DATABASE*/

void finish_with_error(MYSQL* con)
{ 
	fprintf(stderr,"%s\n",mysql_error(con));
	mysql_close(con);
	exit(1);
}

int main(int argc, char** argv)
{
	struct timespec start,finish;
	clock_gettime(CLOCK_REALTIME, &start);
	
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

	char *sql = "CREATE TABLE IF NOT EXISTS Writers (Id INT PRIMARY KEY AUTO_INCREMENT, Name TEXT)";

	if(mysql_query(con,sql))
	{
		finish_with_error(con);
	}


	if(mysql_query(con,"INSERT INTO `Writers` (Name) VALUES('Leo Tolstoy')"))
	{
		finish_with_error(con);
	}

	
	if(mysql_query(con,"INSERT INTO  Writers (Name) VALUES('Jack London')"))
	{
		finish_with_error(con);
	}

	
	if(mysql_query(con,"INSERT INTO Writers (Name) VALUES('Honore de Balsac')"))
	{
		finish_with_error(con);
	}

	int id = mysql_insert_id(con);

	clock_gettime(CLOCK_REALTIME,&finish);	
	long seconds = finish.tv_sec -start.tv_sec;
	long ns	= finish.tv_nsec -start.tv_nsec;
	if(start.tv_nsec > finish.tv_nsec){//clock underflow
		--seconds;
		ns += 1000000000;
	}
	printf("seconds without ns: %ld\n", seconds);
	printf("nanoseconds: %ld\n",ns);
	printf("total seconds: %e\n",(double)seconds + (double)ns/(double)1000000000);

	mysql_close(con);
	printf("The last inserted row id is:%d\n",id);
	return 0;
}
