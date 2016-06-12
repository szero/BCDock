TARGET=/usr/local/bin/BCDock

CC=gcc
CFLAGS=-c -Wall -std=gnu99 -O2
EXECFLAGS=-lncurses

SOURCES=$(wildcard *.c)
OBJECTS= $(SOURCES:%.c=%.o)

all: $(SOURCES) $(TARGET)

$(OBJECTS): %.o : %.c
	@echo "Creating objects ..."
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(EXECFLAGS) -o $@
	rm -f $(OBJECTS)
	@echo "Instalation complete."

remove:
	rm -f $(TARGET)
	@echo "Uninstalled succesfully."
