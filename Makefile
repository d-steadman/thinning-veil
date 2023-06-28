CC = gcc
CFLAGS = -g -lncurses
SRC_FILES = $(wildcard *.c)

thinning-veil: $(SRC_FILES)
	echo $(SRC_FILES)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f thinning-veil
