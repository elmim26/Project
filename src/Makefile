CC := gcc
CFLAGS := -Wall

test_range: pigment.o test_range.o
	$(CC) $(CFLAGS) -o test_range pigment.o test_range.o

paintProgram: pigment.o paintProgram.o
	$(CC) $(CFLAGS) -o paintProgram pigment.o paintProgram.o

test_print: pigment.o test_print.o
	$(CC) $(CFLAGS) -o test_print pigment.o test_print.o

test_value: pigment.o test_value.o
	$(CC) $(CFLAGS) -o test_value pigment.o test_value.o

test_color: pigment.o test_color.o
	$(CC) $(CFLAGS) -o test_color pigment.o test_color.o

test_load: pigment.o test_load.o
	$(CC) $(CFLAGS) -o test_load pigment.o test_load.o

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o test_range paintProgram test_print test_value test_color test_load
