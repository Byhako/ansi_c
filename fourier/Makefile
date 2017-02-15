CC = gcc
CFLAGS = -03 -I. -c -I/home/ruben/local/include/
LFLAGS = -L/home/ruben/local/lib -lfftw3 -lm

1d:
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS) -o $@.x

clean:
	rm -rf *.o
	rm -rf *.x
