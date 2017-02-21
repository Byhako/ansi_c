CC = gcc
CFLAGS = -I. -c -I/home/ruben/local/include/
LFLAGS = -L/home/ruben/local/lib -lfftw3 -lm

fft1d_1:
	$(CC) $(CFLAGS) $@.c -o $@.o
	$(CC) $@.o $(LFLAGS) -o $@.x

clean:
	rm -rf *.o
	rm -rf *.x
