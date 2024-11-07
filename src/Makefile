CC := gcc
CFLAGS := -c -Wall

.PHONY: clean install Package

q04: q04.o
	$(CC) -o $@ $^ -lm


%.o: %.c
	$(CC) $(CFLAGS) $<


.PHONY: clean
clean:
	rm -f *.o project