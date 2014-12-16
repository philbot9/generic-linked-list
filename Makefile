OBJ_TEST = gll.o tests.o
OBJ_PERF = gll.o performance.o

gll.o:	gll.c gll.h
	gcc -c gll.c

tests.o:	tests.c gll.h
	gcc -c tests.c

performance.o:	performance.c gll.h
	gcc -c performance.c

tests:	$(OBJ_TEST) gll.h
	gcc -o tests $(OBJ_TEST)

performance:	$(OBJ_PERF) gll.h
	gcc -o performance $(OBJ_PERF)

clean:
	-rm *.o tests performance

