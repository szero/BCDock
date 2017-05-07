IFROOT=$(shell id -u)

BIN=BCDock
DESTDIR=/usr/local/bin

CC=gcc
CFLAGS=-c -Wall -std=gnu99 -O2
LDFLAGS=-lncurses

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:%.c=%.o)

all: $(OBJECTS) $(BIN)

$(OBJECTS): %.o : %.c
	@echo "Creating objects ..."
	$(CC) $(CFLAGS) $< -o $@

$(BIN): $(OBJECTS)
	@echo "Creating binary ..."
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

install:
ifeq ($(IFROOT),0)
	@echo "Installing into ${DESTDIR}"
	mkdir -p ${DESTDIR}
	install -m 755 -t ${DESTDIR} ${BIN}
else
	@echo "You have to be root in order to install the program!"
endif

uninstall:
ifeq ($(IFROOT),0)
	@echo "Removing executable from ${DESTDIR}"
	rm -f ${DESTDIR}/${BIN}
else
	@echo "You have to be root in order to uninstall the program!"
endif

clean:
	@echo "Cleaning objects and binary ..."
	rm -f ${OBJECTS} ${BIN}

.PHONY: all install uninstall clean
