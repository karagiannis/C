#include <stdio.h>
#include <string.h>

	typedef struct Node
	{  char* text;
	   struct Node* pF;
	   struct Node* pB;
	}node;


int main()
{	node n1, *n2Ptr;

	printf("a. node n1 has the adress %p\n\n\n",(void*)&n1);

	printf("b. n2Ptr has the adress %p\n" 
		"and points to adress %p\n\n\n",
		(void*) &n2Ptr,
		(void *) n2Ptr);

	n2Ptr = NULL;
	printf("c. n2Ptr has the adress %p\n" 
		"and points to adress %p\n\n\n",
		(void*) &n2Ptr,
		(void *) n2Ptr);

	n2Ptr = &n1;
	printf("1.  n2Ptr = &n1;\n"
                "Pointer n2Ptr has adress (void *) &(n2Ptr) = %p\n"
                "and points to adress (void *) n2Ptr = %p\n\n\n",
                	(void *)&(n2Ptr),
		  	(void *)n2Ptr);
		
	char str[50] ="This is a string";
	printf("2.  char str[50] =\"This is a string\";\n"
	       "Pointer str has adress (void *) &str = %p \n"
               "and points to adress (void *) str =  %p \n"
	       "which contains the string str = %s\n\n\n",
			(void *) &str,
			(void *) str,
			str);
	
	(&n1)->text = &str; //This gives a warning but should give an error
	printf(	"3.  (&n1)->text = &str; \n"
		"Pointer (&n1)->text has adress"
	        " (void *) &((&n1)->text) = %p\n"
        	"and points to adress (void *) (&n1)->text = %p\n"
		"which contains the string (&n1)->text = %s\n\n\n",
                 	(void *) &((&n1)->text),
		     	(void *) (&n1)->text,
			(&n1)->text);

	(&n1)->text = str;
	printf(	"4.  (&n1)->text = str; \n"
		"Pointer (&n1)->text has adress"
		" (void *) &((&n1)->text) = %p\n"
              	"and points to adress (void *) (&n1)->text = %p\n"
		"which contains the string (&n1)->text = %s\n\n\n",
                 	(void *) &((&n1)->text),
		   	(void *) (&n1)->text,
			(&n1)->text);

	(&n1)->text = "This is a new string";
	printf(	"5.  (&n1)->text = \"This is a new string\"; \n"
		"Pointer (&n1)->text has adress"
		" (void *) &((&n1)->text) = %p\n"
             	"and points to adress (void *) (&n1)->text = %p\n"
		"which contains the string (&n1)->text = %s\n\n\n",
                    	(void *) &((&n1)->text),
		      	(void *) (&n1)->text,
			(&n1)->text);

	printf(	"6.  Printing out n1.text before strcpy: %s\n\n\n",n1.text);
	//strcpy(n1.text,str); //Core dumps during run



	//printf("7.  Printing out n1->text %s\n\n\n",n1->text); Type error



	printf(	"8.  Printing out n1->text before strcpy: %s\n\n\n",
			(&n1)->text);
	//strcpy((&n1)->text,str); //Core dumps during run


	(&n1)->pF = &n1;
	printf(	"9.  (&n1)->pF = &n1; \n"
		"Pointer (&n1)->pF has adress (void *) &((&n1)->pF) =  %p\n"
           	"and points to adress (void *) ((&n1)->pF) = %p\n"
		"which is to a struct which contains the string"
 		"(((&n1)->pF)->text) = %s\n\n\n",
                   	(void *) &((&n1)->pF),
		     	(void *) ((&n1)->pF),
			(((&n1)->pF)->text));

	(&n1)->pB = n2Ptr;
	printf(	"10. (&n1)->pF = &n1; \n"
		"Pointer (&n1)->pB has adress (void *) &((&n1)->pB) = %p\n"
              	"and points to adress (void *) ((&n1)->pB) = %p\n"
		"which is to a struct which contains the string"
		"(((&n1)->pB)->text) =  %s\n\n\n",
                  	(void *) &((&n1)->pB),
		    	(void *) ((&n1)->pB),
			(((&n1)->pB)->text));



       	
	return 0;  
}


/*

a. node n1 has the adress 0x7ffe673ad570


b. n2Ptr has the adress 0x7ffe673ad568
and points to adress 0x756e6547


c. n2Ptr has the adress 0x7ffe673ad568
and points to adress (nil)


1.  n2Ptr = &n1;
Pointer n2Ptr has adress (void *) &(n2Ptr) = 0x7ffe673ad568
and points to adress (void *) n2Ptr = 0x7ffe673ad570


2.  char str[50] ="This is a string";
Pointer str has adress (void *) &str = 0x7ffe673ad590 
and points to adress (void *) str =  0x7ffe673ad590 
which contains the string str = This is a string


3.  (&n1)->text = &str; 
Pointer (&n1)->text has adress (void *) &((&n1)->text) = 0x7ffe673ad570
and points to adress (void *) (&n1)->text = 0x7ffe673ad590
which contains the string (&n1)->text = This is a string


4.  (&n1)->text = str; 
Pointer (&n1)->text has adress (void *) &((&n1)->text) = 0x7ffe673ad570
and points to adress (void *) (&n1)->text = 0x7ffe673ad590
which contains the string (&n1)->text = This is a string


5.  (&n1)->text = "This is a new string"; 
Pointer (&n1)->text has adress (void *) &((&n1)->text) = 0x7ffe673ad570
and points to adress (void *) (&n1)->text = 0x55dd4781bc61
which contains the string (&n1)->text = This is a new string


6.  Printing out n1.text before strcpyThis is a new string


8.  Printing out n1->text before strcpyThis is a new string


9.  (&n1)->pF = &n1; 
Pointer (&n1)->pF has adress (void *) &((&n1)->pF) =  0x7ffe673ad578
and points to adress (void *) ((&n1)->pF) = 0x7ffe673ad570
which is to a struct which contains the string(((&n1)->pF)->text) = This is a new string


10. (&n1)->pF = &n1; 
Pointer (&n1)->pB has adress (void *) &((&n1)->pB) = 0x7ffe673ad580
and points to adress (void *) ((&n1)->pB) = 0x7ffe673ad570
which is to a struct which contains the string(((&n1)->pB)->text) =  This is a new string



*/
