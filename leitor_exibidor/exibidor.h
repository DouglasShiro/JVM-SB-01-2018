/**
 *  @file exibidor.h
 *  @author Adarley Luiz Grando Filho (11/0007344)
 *  @brief Definition of the class file structure.
 */

#ifndef EXIBIDOR_H
#define EXIBIDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "classfile.h"

void u1Exib(u1);
void u2Exib(u2);
void u4Exib(u4);
void constantPoolExib(cp_info *, u2);
void attributesExib(attribute_info *, u2, cp_info *);
void fieldsExib(field_info *, u2);
void methodsExib(method_info *, u2, cp_info *);
void classFileExib(ClassFile *);

#endif
