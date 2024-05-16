CFLAGS = -Wall -Wextra -pthread -g
LDFLAGS = -lpigpiod_if2 -lrt

SOURCES = pigpiodemo.c
OBJS = $(SOURCES:.c=.o)
EXEC = pigpiodemo

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJS)
