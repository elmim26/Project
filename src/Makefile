CC := gcc
CFLAGS := -Wall



test_load: pigment.o test_load.o
	$(CC) -o test_load pigment.o test_load.o

pigment.o: pigment.c pigment.h
	$(CC) $(CFLAGS) -c pigment.c

test_load.o: test_load.c pigment.h
	$(CC) $(CFLAGS) -c test_load.c

clean:
	rm -f *.o test_load

package: 
	cd ../ && tar -czvf  cmpt201_AMZ_lab09,project_milestone1.tar.gz PROJECT
