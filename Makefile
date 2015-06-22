EXEC=cjinja
CFLAGS+=-pedantic -std=c89 -Wall -Wextra

.PHONY: clean

all: $(EXEC)

$(EXEC): cjinja.c
	$(CC) $(CFLAGS) -o cjinja cjinja.c

clean:
	rm -f $(EXEC)
