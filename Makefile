all : 
	gcc matrix.h matrix.c -o test

clean :
	rm -rf test
