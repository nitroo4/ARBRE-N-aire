CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRCDIR = src
SOURCES = $(SRCDIR)/main.c $(SRCDIR)/noeud.c $(SRCDIR)/file.c $(SRCDIR)/parcours.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = arbre_parcours

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: clean