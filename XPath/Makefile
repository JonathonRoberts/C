CC=gcc
CFLAGS +=-c `xml2-config --cflags` -Wall
LIBS=`xml2-config --libs`
SOURCES = xpath-ex1.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=a.out
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LIBS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) *.o



