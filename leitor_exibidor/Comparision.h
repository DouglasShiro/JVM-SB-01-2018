/**
* @file   Comparision.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções de comparação.
**/

#ifndef COMPARISION_H
#define COMPARISION_H

#include "Conjunto_de_Instrucoes.h"
# include "pilhaFrames.h"
# include "Method_area.h"
# include "classfile.h"

void lcmp(Frame *);
void fcmp(Frame *);
void fcmpg(Frame *);
void dcmpl(Frame *);
void dcmpg(Frame *);
void if_eq(Frame *, u1, u1);
void if_ne(Frame *, u1, u1);
void if_lt(Frame *, u1, u1);
void if_ge(Frame *, u1, u1);
void if_gt(Frame *, u1, u1);
void if_le(Frame *, u1, u1);
void if_icmpeq(Frame *, u1, u1);
void if_icmpne(Frame *, u1, u1);
void if_icmplt(Frame *, u1, u1);
void if_icmpge(Frame *, u1, u1);
void if_icmpgt(Frame *, u1, u1);
void if_icmple(Frame *, u1, u1);
void if_acmpeq(Frame *, u1, u1);
void if_acmpne(Frame *, u1, u1);

# endif
