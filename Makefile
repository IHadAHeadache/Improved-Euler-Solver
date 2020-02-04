CCFLAGS = -ansi -Wall -Wshadow -O2
LFLAGS = -lm
 
.PHONY = all clean
 
all: euler

euler: euler.c tinyexpr.c
	$(CC) $(CCFLAGS) -o $@ $^ $(LFLAGS)
	./$@
clean:
	rm -f *.o *.exe euler
