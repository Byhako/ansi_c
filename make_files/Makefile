CC=gcc
CFLAGS=-c -Wall
LDFLAGS= #Puede estar en blanco, una opcion puede ser -lm
SOURCES=main.c hello.c factorial.c
OBJECTS=$(SOURCES:.c=.o) #Esto reemplaza el .c por .o
EXECUTABLE=hello
#El ejecutable terminara en .x

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@.x

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o *.x