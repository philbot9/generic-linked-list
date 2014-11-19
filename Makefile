gll.o:	gll.c gll_defs.h
	gcc -c gll.c

tests:	gll.o gll_defs.h tests.o
	gcc -o tests gll.o tests.o

tests.o:	tests.c gll_defs.h gll.o
	gcc -c tests.c

clean:
	-rm *.o

