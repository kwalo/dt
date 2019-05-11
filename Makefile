CC ?= cc
CFLAGS ?= -Wall -pedantic
DESTDIR ?= /
PREFIX ?= usr/local
MANPREFIX ?= $(PREFIX)/share/man

.PHONY: all clean install uninstall

all: dt

dt: dt.c
	$(CC) -o $@ $(CFLAGS) $<

clean:
	-rm -f dt

install: all
	mkdir -p "$(DESTDIR)$(PREFIX)/bin"
	cp -f dt "$(DESTDIR)$(PREFIX)/bin"
	chmod 755 "$(DESTDIR)$(PREFIX)/bin/dt"
	mkdir -p "$(DESTDIR)$(MANPREFIX)/man1"
	cp -f dt.1 "$(DESTDIR)$(MANPREFIX)/man1"
	chmod 644  "$(DESTDIR)$(MANPREFIX)/man1/dt.1"

uninstall:
	rm -f "$(DESTDIR)$(PREFIX)/bin/dt"
	rm -f "$(DESTDIR)$(MANPREFIX)/man1/dt.1"
