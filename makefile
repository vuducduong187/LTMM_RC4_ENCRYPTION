CC = gcc 
DEPS = rc4_encrypt.h rc4_init.h rc4_stream.h 
CFLAGS = -I.
%.o: %.c $(DEPS)
	$(CC) -c $< $(CFLAGS) -o $@
all: main.o rc4_encrypt.o rc4_init.o rc4_stream.o
	$(CC) -o main main.o rc4_encrypt.o rc4_init.o rc4_stream.o
clean:
	rm -f *.o main
