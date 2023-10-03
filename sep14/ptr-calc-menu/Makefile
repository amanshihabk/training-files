#this is MKEFILE Environment

#recipie

main.o : ptr-calc.c
	gcc -c ptr-calc.c -o main.o

executable : main.o
	gcc -o executable main.o

clean:
	rm *.o
	rm executable

