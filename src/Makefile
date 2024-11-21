CC := gcc
CFLAGS := -Wall


test_print: pigment.o test_print.o

test_value: pigment.o test_value.o

test_load: pigment.o test_load.o
	$(CC) -o test_load pigment.o test_load.o

pigment.o: pigment.c pigment.h
	$(CC) $(CFLAGS) -c pigment.c

test_load.o: test_load.c pigment.h
	$(CC) $(CFLAGS) -c test_load.c

clean:
<<<<<<< HEAD
	rm -f *.o test_load test_print
=======
	rm -f *.o test_load

package: 
	cd ../ && tar -czvf  cmpt201_AMZ_lab09,project_milestone1.tar.gz PROJECT
>>>>>>> 46ae49bf235ba59c17a44a8a0ac6b3da1892304e
