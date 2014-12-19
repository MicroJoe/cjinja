all: cjinja

cjinja: cjinja.c
	$(CC) -o cjinja cjinja.c
