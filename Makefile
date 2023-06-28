CC = gcc
CFLAGS = -g -lncurses

thinning-veil: $(wildcard *.c)
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f thinning-veil
