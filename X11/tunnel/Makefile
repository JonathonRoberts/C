CC=gcc
CFLAGS += -I /usr/X11R6/include/ -c -Wall
LDFLAGS += -L /usr/X11R6/lib/ -lX11 -lm
SOURCES = tunnel.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE= a.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) *.o



