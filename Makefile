

CC=gcc
PY_INTER=python3.6
CLIB=finance.so
SRC_D=src/
CFLAGS= -Wall -Wextra -pedantic --std=c99 -Werror
PY_DEV_PATH=/usr/include/python3.6m/

all: finance.so

annuity.o:
	gcc -shared -fPIC $(CFLAGS) -c src/annuity.c -I $(PY_DEV_PATH) -lm

wrapper.o: src/wrapper.h
	gcc -shared -fPIC $(CFLAGS) -c src/wrapper.c -I $(PY_DEV_PATH)

finance.so: annuity.o wrapper.o 
	gcc -shared -fPIC $(CFLAGS) -o $(CLIB) -I $(PY_DEV_PATH) *.o

test:
	$(PY_INTER) test.py

clean:
	rm -f *.so *.o
