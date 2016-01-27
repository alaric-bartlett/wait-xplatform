CC = g++
CFLAGS = -Wall -g -std=c++11
DEPS = kbhit.h
OBJ = main.o kbhit.o

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

app: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
