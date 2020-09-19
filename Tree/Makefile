IDIR =./include
CC=gcc
CFLAGS= -ggdb -I$(IDIR)

ODIR=obj
LDIR =./lib

LIBS=-lm

all: tree.bin

_DEPS = tree.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = tree.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tree.bin: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 