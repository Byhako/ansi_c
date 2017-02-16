CC = gcc
CFLAGS = -I. -c -I/home/ruben/local/include/
LFLAGS = -L/home/ruben/local/lib -lm -lfftw3

sample1:
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS) -o $@.x

clean:
	rm -rf *.o
	rm -rf *.x
