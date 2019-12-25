#include <stdio.h>
#include <string.h>

	typedef struct Node
	{
		char* text;
		struct Node* pF;
		struct Node* pB;
	}node;



int main()
{
	node n,n1,n2,n3,*n2Ptr;
	n2Ptr = &n1;
	char str[50] ="This is a string-1";
	(&n)->text = str;
	n1.text = "This is also a string-2";
	//strcpy(n2.text,str);
	strcpy((&n3)->text,str);
	(&n)->pF = &n1;
	n2Ptr->pF = &n1;
	(&n)->pB = &n;
	return 0;  
}


