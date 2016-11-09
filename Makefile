CC = gcc
CFLAGS = #-g -Wall
#TARGET = mytest_test


mytest_test : mytest_test.o mytest.o 
	$(CC) $(CFLAGS) -Wl,--wrap=write -Wl,--wrap=read mytest_test.o mytest.o -lcmocka -L /usr/lib -o mytest_test

mytest.o : mytest.c mytest.h
	$(CC) $(CFLAGS) -c mytest.c

mytest_test.o : mytest_test.c mytest.h
	$(CC) $(CFLAGS) -c mytest_test.c



clean :
	rm -f mytest_test *.o 
