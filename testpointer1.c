#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//typedef struct Node{
//	char text[50];
//	struct node* pF;
//	struct node* pB;
//}node;
	struct node
	{
		char* text;
		struct node* pF;
		struct node* pB;
	};


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

	struct node n,n1,*n2Ptr;
	i = 1;
	iptr = &i;
	printf("Pointer has adress %p and points to value %d\n",(void*) iptr,i);
	//n->text = "Detta äre en sträng";
	char str[20] ="Detta är en sträng";
	//n->text = &str;
	(&n)->text =&str;
	(&n)->text = "Detta är en sträng";
	strcpy(n.text,str);
	//strcpy(n->text,str);
	//n->pF = &n1;
	(&n)->pF = &n1;
	n2Ptr->pF = &n1;
	(&n)->pB = &n;
	return 0;  
}
