IFROOT=$(shell id -u)

ifeq ($(IFROOT),0)
$(eval TARGET=/usr/local/bin/BCDock)
else
$(eval TARGET=BCDock)
endif

CC=gcc
CFLAGS=-c -Wall -std=gnu99 -O2
LDFLAGS=-lncurses

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:%.c=%.o)

all: $(OBJECTS)

$(OBJECTS): %.o : %.c
	@echo "Creating objects ..."
	$(CC) $(CFLAGS) $< -o $@

install: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Creating target ..."
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	rm -f $(OBJECTS)
	@echo "Installation complete."

clean:
	rm -f $(OBJECTS)
	@echo "Removed objects succesfully."

remove:
	rm -f $(TARGET)
	@echo "Uninstalled succesfully."

.PHONY: all install clean remove
