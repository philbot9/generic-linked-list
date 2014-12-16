OBJ_TEST = src/gll.o tests.o
OBJ_PERF = src/gll.o performance.o

gll.o:	src/gll.c src/gll.h
	gcc -c src/gll.c -o src/gll.o

tests.o:	tests.c src/gll.h
	gcc -c tests.c

performance.o:	performance.c src/gll.h
	gcc -c performance.c

tests:	$(OBJ_TEST) src/gll.h
	gcc -o tests $(OBJ_TEST)

performance:	$(OBJ_PERF) src/gll.h
	gcc -o performance $(OBJ_PERF)

clean:
	-rm *.o src/*.o tests performance

