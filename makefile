##this is a make file

main: safe_sleep.c
	gcc -o main safe_sleep.c -lrt

clean:
	rm main *.o

tar:
	tar -cf main.tar safe_sleep.c makefile
