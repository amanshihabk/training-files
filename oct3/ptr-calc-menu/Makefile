main-debug.o : ptr-calc.c
	gcc -g ptr-calc.c -c -o main-debug.o

debug-executable : main-debug.o
	gcc -o debug-exec main-debug.o

main-release.o : ptr-calc.c
	gcc -g ptr-calc.c -c -o main-debug.o

release-executable : main-debug.o
	gcc -o release-exec main-debug.o -O3

debug : debug-executable

release : release-executable

clean:
	rm *.o main