/**
 *  @file reader.h
 *  @author Felipe Augusto Rodrigues Brandao (12/0044919)
 */

#ifndef READER_H
#define READER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classfile.h"

u1 u1Read(FILE *);
u2 u2Read(FILE *);
u4 u4Read(FILE *);
void constantPoolRead(FILE *, ClassFile *);
attribute_info *attributesRead(FILE *, cp_info *, u2);
void fieldsRead(FILE *, ClassFile *);
void methodsRead(FILE *, ClassFile *);
ClassFile *classFileRead(char *);

#endif
