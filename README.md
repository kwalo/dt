# Description

**dt** is a simple UNIX tool that launches programs detached from terminal.
Programs are immune to SIGHUP. All standard input and output is redirected to /dev/null.
Detached programs do not appear as jobs in shell. This is mostly useful to open new
windows without blocking terminal.

# Installation

    make
    make install

