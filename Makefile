OBJ_TEST = gll.o tests.o
OBJ_PERF = gll.o performance.o

gll.o:	gll.c GenericLinkedList.h
	gcc -c gll.c

tests.o:	tests.c GenericLinkedList.h
	gcc -c tests.c

performance.o:	performance.c GenericLinkedList.h
	gcc -c performance.c

tests:	$(OBJ_TEST) GenericLinkedList.h
	gcc -o tests $(OBJ_TEST)

performance:	$(OBJ_PERF) GenericLinkedList.h
	gcc -o performance $(OBJ_PERF)

clean:
	-rm *.o tests performance

