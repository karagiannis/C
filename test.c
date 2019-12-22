//Test structure found in redis test code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static int tests = 0, fails = 0;
#define test(_s) {printf("#%02d ",++tests); printf(_s);}

#define test_cond(_c) if(_c) printf("\033[0;32mPASSED\033[0;0m\n"); else { printf("\033[0;31mFAILED\033[0;0m\n"); fails++;}


int main()
{
	char *cmd;
	int len;
	test("Format command without interpolation: ");
	len = strlen("SET FOO BAR");
	cmd = "SET FOO BAR";
	test_cond(strncmp(cmd,"SET FOO BAR",(size_t) 5 ) == 0 );
	printf("%d\n",(int) strlen("*3\r\r\n"));

	if(fails) {
	    printf("***  %d TESTS FAILED ***\n",fails);
	    return 1;
	}
	printf("\033[0;32m\\o/\033[0;0m ALL TESTS PASSED\n");	
       return 0;
}
