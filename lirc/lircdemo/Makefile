CFLAGS = -Wall -Wextra -g
LDFLAGS = -llirc_client

SOURCES = lircdemo.c
OBJS = $(SOURCES:.c=.o)
EXEC = lircdemo

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(EXEC) $(OBJS)
