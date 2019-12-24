#include <stdio.h>
#include <string.h>

	typedef struct Node
	{
		char* text;
		struct Node* pF;
		struct Node* pB;
	}node;

//struct node
//	{
//		char* text;
//		struct node* pF;
//		struct node* pB;
//	};


int main()
{
	int i = 0;
	int* iptr;
	
	//typedef struct Node
 	//{
	//	char text[50];
	//	struct node*  ptrForward;
	//	struct node* ptrBack;
	//} node;

	node n,n1,*n2Ptr;
	i = 1;
	n2Ptr = &n1;
	iptr = &i;
	printf("Pointer has adress %p and points to value %d\n",(void*) iptr,i);
	//n->text = "Detta äre en sträng";
	char str[50] ="Detta är en sträng\0";
	//n->text = &str;
	//(&n)->text = &str;//This gives only warnings but should be an error
	(&n)->text = str;
	(&n)->text = "Detta är en sträng";
//	strcpy(n.text,str);
//	strcpy((&n)->text,str);
	//n->pF = &n1;
	(&n)->pF = &n1;
	n2Ptr->pF = &n1;
	(&n)->pB = &n;
	return 0;  
}

/*
rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1


rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~


rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~

Pointer has adress 0x7fffcc89f4ac and points to value 1


	     

rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~



rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:43:10: error: invalid type argument of ‘->’ (have ‘node {aka struct Node}’)
  strcpy(n->text,str);
          ^~
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~
Makefile:10: recipe for target 'testpointer1' failed
make: *** [testpointer1] Error 1
	     


rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~     

This gave segmentation fault


rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~   



rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~                            



Pointer has adress 0x7fffeb3c20ac and points to value 1





rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1
testpointer1.c: In function ‘main’:
testpointer1.c:31:13: warning: variable ‘n2Ptr’ set but not used [-Wunused-but-set-variable]
  node n,n1,*n2Ptr;
             ^~~~~         



Pointer has adress 0x7fffac2812bc and points to value 1



rm -f testpointer1
gcc -Wall -g  -Wpedantic   testpointer1.c -o testpointer1


Pointer has adress 0x7ffdb9e02c0c and points to value 1


*/
