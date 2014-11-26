gll.o:	gll.c GenericLinkedList.h
	gcc -c gll.c

tests.o:	tests.c GenericLinkedList.h gll.o
	gcc -c tests.c

tests:	gll.o GenericLinkedList.h tests.o
	gcc -o tests gll.o tests.o

performance.o:	performance.c GenericLinkedList.h
	gcc -c performance.c

performance:	gll.o GenericLinkedList.h performance.o
	gcc -o performance gll.o performance.o

clean:
	-rm *.o tests performance

