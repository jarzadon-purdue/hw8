CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS)
EXEC = hw7
OBJS = shuffle.o

$(EXEC): $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC)

test: $(EXEC)
	./$(EXEC) 4 | sort > output4
	diff -w output4 expected/expected4
	./$(EXEC) 8 | sort > output8
	diff -w output8 expected/expected8
	./$(EXEC) 11 | sort > output11
	diff -w output11 expected/expected11

%.o : %.c
	$(GCC) -c $<

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output* log*