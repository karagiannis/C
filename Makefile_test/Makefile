hellomake : hellomake.o hellofunc.o  #prerquisities
	gcc -o hellomake hellomake.o hellofunc.o  #receipe

hellomake.o : hellomake.c hellofunc.h
	gcc -c hellomake.c  -I.

hellofunc.o : hellofunc.c hellofunc.h
	gcc -c hellofunc.c -I.

hellofunc.h : 
	

clean :
	rm hellomake.o hellofunc.o
