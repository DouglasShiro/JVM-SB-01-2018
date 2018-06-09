# @file Makefile.mak
# @author Gustavo Costa Crispim de Sousa (14/0142568)

CC=gcc
DEPS = classfile.h exibidor.h reader.h
OBJ = exibidor.c reader.c leitorExibidor.c

%.c: $(DEPS)
	$(CC) -g -Wall -std=c99 -O0 $@ $<

output: $(OBJ)
	$(CC) $(OBJ) -g -Wall -std=c99 -O0

clean:
	rm *.exe