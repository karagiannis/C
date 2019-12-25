#include <stdio.h>
#include <string.h>

	typedef struct Node
	{  char* text;
	   struct Node* pF;
	   struct Node* pB;
	}node;


int main()
{	node n1, *n2Ptr;

	printf("1. node n1 has the adress %p\n\n\n",(void*)&n1);

	printf("2. n2Ptr has the adress %p\n" 
		"and points to adress %p\n\n\n",
		(void*) &n2Ptr,
		(void *) n2Ptr);

	n2Ptr = NULL;
	printf("3. n2Ptr has the adress %p\n" 
		"and points to adress %p\n\n\n",
		(void*) &n2Ptr,
		(void *) n2Ptr);

	n2Ptr = &n1;
	printf("4.  n2Ptr = &n1;\n"
                "Pointer n2Ptr has adress (void *) &(n2Ptr) = %p\n"
                "and points to adress (void *) n2Ptr = %p\n\n\n",
                	(void *)&(n2Ptr),
		  	(void *)n2Ptr);
		
	char str[50] ="This is a string";
	printf("5.  char str[50] =\"This is a string\";\n"
	       "Pointer str has adress (void *) &str = %p \n"
               "and points to adress (void *) str =  %p \n"
	       "which contains the string str = %s\n\n\n",
			(void *) &str,
			(void *) str,
			str);
	
	(&n1)->text = &str; //This gives a warning but should give an error
	printf(	"6.  (&n1)->text = &str; \n"
		"Pointer (&n1)->text has adress"
	        " (void *) &((&n1)->text) = %p\n"
        	"and points to adress (void *) (&n1)->text = %p\n"
		"which contains the string (&n1)->text = %s\n\n\n",
                 	(void *) &((&n1)->text),
		     	(void *) (&n1)->text,
			(&n1)->text);

	(&n1)->text = str;
	printf(	"7.  (&n1)->text = str; \n"
		"Pointer (&n1)->text has adress"
		" (void *) &((&n1)->text) = %p\n"
              	"and points to adress (void *) (&n1)->text = %p\n"
		"which contains the string (&n1)->text = %s\n\n\n",
                 	(void *) &((&n1)->text),
		   	(void *) (&n1)->text,
			(&n1)->text);

	(&n1)->text = "This is a new string";
	printf(	"8.  (&n1)->text = \"This is a new string\"; \n"
		"Pointer (&n1)->text has adress"
		" (void *) &((&n1)->text) = %p\n"
             	"and points to adress (void *) (&n1)->text = %p\n"
		"which contains the string (&n1)->text = %s\n\n\n",
                    	(void *) &((&n1)->text),
		      	(void *) (&n1)->text,
			(&n1)->text);

	printf(	"9.  Printing out n1.text before strcpy: %s\n\n\n",n1.text);
	char str2[50]="String 2";
	//strcpy(n1.text,str2); //Core dumps during run
	//strcpy(&(n1.text),str2);
        /*     ^ Pass the adress to the array and not the adress to the 		  first element
		--No, this doesn't work. Segmentation fault catches up
		after printf("10....  below
	*/
	printf("10. Printing &(n1.text) after strcpy(&(n1.text),str2)" 
		"gives  %s\n\n\n",
		&(n1.text));
	

	//printf("10a.  Printing out n1->text %s\n\n\n",n1->text);
	// Type error


	printf("Printing out before 11.");
	printf(	"11.  Printing out n1->text before strcpy: %s\n\n\n",
			(&n1)->text);

	//strcpy((&n1)->text,str); //Core dumps during run
	//strcpy(&((&n1)->text),str); 
	/*     ^ Pass the adress to the array and not the adress to the 		first element
		-No, this doesn't work. Segmentation fault catches up
		after printf("13....  below

	*/
	printf("12. Printing &((&n1)->text)"
 		"after strcpy(&((&n1)->text),str);"
	 	"gives  %s\n\n\n",
		&((&n1)->text));
	

	(&n1)->pF = &n1;
	printf(	"13.  (&n1)->pF = &n1; \n"
		"Pointer (&n1)->pF has adress (void *) &((&n1)->pF) =  %p\n"
           	"and points to adress (void *) ((&n1)->pF) = %p\n"
		"which is to a struct which contains the string"
 		"(((&n1)->pF)->text) = %s\n\n\n",
                   	(void *) &((&n1)->pF),
		     	(void *) ((&n1)->pF),
			(((&n1)->pF)->text));

	(&n1)->pB = n2Ptr;
	printf(	"14. (&n1)->pF = &n1; \n"
		"Pointer (&n1)->pB has adress (void *) &((&n1)->pB) = %p\n"
              	"and points to adress (void *) ((&n1)->pB) = %p\n"
		"which is to a struct which contains the string"
		"(((&n1)->pB)->text) =  %s\n\n\n",
                  	(void *) &((&n1)->pB),
		    	(void *) (&n1)->pB,
			((&n1)->pB)->text);


/*	&(n1)->pF = &n1;
	printf(	"15.  &(n1->pF) = &n1; \n"
		"Pointer &(n1->pF) has adress (void *) &(&(n1->pF)) =  %p\n"
           	"and points to adress (void *) &(n1->pF) = %p\n"
		"which is to a struct which contains the string"
 		"&((n1->pF)->text) = %s\n\n\n",
                   	(void *) &(n1->pF),
		     	(void *) (n1->pF),
			(n1->pF)->text);

	(n1->pB) = n2Ptr;
	printf(	"16.  &(n1->pF) = &n1; \n"
		"Pointer &(n1->pB) has adress (void *) &(&(n1->pB)) =  %p\n"
           	"and points to adress (void *) &(n1->pB) = %p\n"
		"which is to a struct which contains the string"
 		"&((n1->pB)->text) = %s\n\n\n",
                   	(void *) &(n1->pB),
		     	(void *) &(n1->pB),
			(n1->pB)->text);
*/
       	
	return 0;  
}


/*

lasse@Lenovo:~/Documents/C$ gdb testpointer2
GNU gdb (Ubuntu 8.1-0ubuntu3.2) 8.1.0.20180409-git
Copyright (C) 2018 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from testpointer2...done.
(gdb) break 1
Breakpoint 1 at 0x705: file testpointer2.c, line 1.
(gdb) n
The program is not being run.
(gdb) run
Starting program: /home/lasse/Documents/C/testpointer2 

Breakpoint 1, main () at testpointer2.c:12
12	{	node n1, *n2Ptr;
(gdb) print n1
$1 = {text = 0xffffffff <error: Cannot access memory at address 0xffffffff>, 
  pF = 0x0, pB = 0x7ffff7ffb268}
(gdb) print &n1
$2 = (node *) 0x7fffffffdde0
(gdb) print n2Ptr
$3 = (node *) 0x0
(gdb) print &n2Ptr
$4 = (node **) 0x7fffffffddd8
(gdb) n
14		printf("1. node n1 has the adress %p\n\n\n",(void*)&n1);
(gdb) n
1. node n1 has the adress 0x7fffffffdde0


16		printf("2. n2Ptr has the adress %p\n" 
(gdb) n
2. n2Ptr has the adress 0x7fffffffddd8
and points to adress (nil)


21		n2Ptr = NULL;
(gdb) n2Ptr
Undefined command: "n2Ptr".  Try "help".
(gdb) print n2Ptr
$5 = (node *) 0x0
(gdb) n
22		printf("3. n2Ptr has the adress %p\n" 
(gdb) n
3. n2Ptr has the adress 0x7fffffffddd8
and points to adress (nil)


27		n2Ptr = &n1;
(gdb) print n2Ptr
$6 = (node *) 0x0
(gdb) print &n1
$7 = (node *) 0x7fffffffdde0
(gdb) n
28		printf("4.  n2Ptr = &n1;\n"
(gdb) print n2Ptr
$8 = (node *) 0x7fffffffdde0
(gdb) n
4.  n2Ptr = &n1;
Pointer n2Ptr has adress (void *) &(n2Ptr) = 0x7fffffffddd8
and points to adress (void *) n2Ptr = 0x7fffffffdde0


34		char str[50] ="This is a string";
(gdb) print str
$9 = '\000' <repeats 24 times>, "Genu\000\000\000\000\t\000\000\000\000\000\000\000`v\335\367\377\177\000\000\230", <incomplete sequence \336>
(gdb) print &str
$10 = (char (*)[50]) 0x7fffffffde00
(gdb) n
35		printf("5.  char str[50] =\"This is a string\";\n"
(gdb) n
5.  char str[50] ="This is a string";
Pointer str has adress (void *) &str = 0x7fffffffde00 
and points to adress (void *) str =  0x7fffffffde00 
which contains the string str = This is a string


43		(&n1)->text = &str; //This gives a warning but should give an error
(gdb) print (&n1)->text
$11 = 0xffffffff <error: Cannot access memory at address 0xffffffff>
(gdb) print &((&n1)->text)
$12 = (char **) 0x7fffffffdde0
(gdb) n
44		printf(	"6.  (&n1)->text = &str; \n"
(gdb) n
50			     	(void *) (&n1)->text,
(gdb) n
44		printf(	"6.  (&n1)->text = &str; \n"
(gdb) n
6.  (&n1)->text = &str; 
Pointer (&n1)->text has adress (void *) &((&n1)->text) = 0x7fffffffdde0
and points to adress (void *) (&n1)->text = 0x7fffffffde00
which contains the string (&n1)->text = This is a string


53		(&n1)->text = str;
(gdb) n
54		printf(	"7.  (&n1)->text = str; \n"
(gdb) n
60			   	(void *) (&n1)->text,
(gdb) n
54		printf(	"7.  (&n1)->text = str; \n"
(gdb) n
7.  (&n1)->text = str; 
Pointer (&n1)->text has adress (void *) &((&n1)->text) = 0x7fffffffdde0
and points to adress (void *) (&n1)->text = 0x7fffffffde00
which contains the string (&n1)->text = This is a string


63		(&n1)->text = "This is a new string";
(gdb) n
64		printf(	"8.  (&n1)->text = \"This is a new string\"; \n"
(gdb) n
70			      	(void *) (&n1)->text,
(gdb) n
64		printf(	"8.  (&n1)->text = \"This is a new string\"; \n"
(gdb) n
8.  (&n1)->text = "This is a new string"; 
Pointer (&n1)->text has adress (void *) &((&n1)->text) = 0x7fffffffdde0
and points to adress (void *) (&n1)->text = 0x555555554dd1
which contains the string (&n1)->text = This is a new string


73		printf(	"9.  Printing out n1.text before strcpy: %s\n\n\n",n1.text);
(gdb) n
9.  Printing out n1.text before strcpy: This is a new string


74		char str2[50]="String 2";
(gdb) n
76		strcpy(&(n1.text),str2);
(gdb) print n1.text
$13 = 0x555555554dd1 "This is a new string"
(gdb) print &(n1.text)
$14 = (char **) 0x7fffffffdde0
(gdb) n
80		printf("10. Printing &(n1.text) after strcpy(&(n1.text),str2)" "gives  %s\n\n\n",
(gdb) print n1->text
$15 = 0x3220676e69727453 <error: Cannot access memory at address 0x3220676e69727453>
(gdb) print &(n1->text)
$16 = (char **) 0x7fffffffdde0
(gdb) print &((&n1)->text)
$17 = (char **) 0x7fffffffdde0
(gdb) print *(&(n1->text))
$18 = 0x3220676e69727453 <error: Cannot access memory at address 0x3220676e69727453>
(gdb)  *(&(n1->text))='e'
Undefined command: "".  Try "help".
(gdb) n
10. Printing &(n1.text) after strcpy(&(n1.text),str2)gives  String 2


88		printf("Printing out before 11.");
(gdb) n
89		printf(	"11.  Printing out n1->text before strcpy: %s\n\n\n",
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
__strlen_avx2 () at ../sysdeps/x86_64/multiarch/strlen-avx2.S:62
62	../sysdeps/x86_64/multiarch/strlen-avx2.S: No such file or directory.
(gdb) 


*/
