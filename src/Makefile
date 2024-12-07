CC := gcc
CFLAGS := -Wall

all: test_range test_print test_value test_color test_load

test_range: pigment.o test_range.o
	$(CC) -o test_range pigment.o test_range.o
	$(CC) -o test_range pigment.o test_range.o

paintProgram: pigment.o paintProgram.o
	$(CC) $(CFLAGS) -o paintProgram pigment.o paintProgram.o

test_print: pigment.o test_print.o
	$(CC) -o test_print pigment.o test_print.o

test_value: pigment.o test_value.o
	$(CC) -o test_value pigment.o test_value.o

test_color: pigment.o test_color.o
	$(CC) -o test_color pigment.o test_color.o

test_load: pigment.o test_load.o
	$(CC) -o test_load pigment.o test_load.o

pigment.o: pigment.c pigment.h
	$(CC) $(CFLAGS) -c pigment.c

test_load.o: test_load.c pigment.h
	$(CC) $(CFLAGS) -c test_load.c

test_print.o: test_print.c pigment.h
	$(CC) $(CFLAGS) -c test_print.c

test_value.o: test_value.c pigment.h
	$(CC) $(CFLAGS) -c test_value.c

test_color.o: test_color.c pigment.h
	$(CC) $(CFLAGS) -c test_color.c

clean:
	rm -f *.o test_range paintProgram test_print test_value test_color test_load

package:
	cd ../ && tar -czvf cmpt201_AMZ_ME_lab10,project_milestone2.tar.gz src
