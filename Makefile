OBJ_TEST = src/gll.o bin/tests.o
OBJ_PERF = src/gll.o bin/performance.o

all:	build/libgll.a

build/libgll.a:	src/gll.o src/gll.h
	-mkdir -p build
	ar rcs build/libgll.a src/gll.o

src/gll.o:	src/gll.c src/gll.h
	gcc -c src/gll.c -o src/gll.o

bin/tests.o:	tests.c src/gll.h
	-mkdir -p bin
	gcc -c tests.c -o bin/tests.o

bin/performance.o:	performance.c src/gll.h
	-mkdir -p bin
	gcc -c performance.c -o bin/performance.o

tests:	$(OBJ_TEST) src/gll.h
	gcc -o tests $(OBJ_TEST)

performance:	$(OBJ_PERF) src/gll.h
	gcc -o performance $(OBJ_PERF)

clean:
	-rm -fr build bin *.o src/*.o tests performance

