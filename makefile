TARGET=BCDock

CC=gcc
CFLAGS=-c -Wall -std=gnu99
EXECFLAGS=-lncurses

SOURCES=$(wildcard *.c)
OBJECTS= $(SOURCES:%.c=%.o)

all: $(SOURCES) $(TARGET)

$(OBJECTS): %.o : %.c
	@echo "Creating objects ..."
	$(CC) $(CFLAGS) $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(EXECFLAGS) -o $@
	@echo "Instalation complete."

remove:
	rm -f $(TARGET) $(OBJECTS)
	@echo "Uninstalled succesfully."
