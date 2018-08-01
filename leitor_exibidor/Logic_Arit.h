/**
* @file   Logic_Arit.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções logico-aritméticas.
**/

# ifndef LOGIC_ARIT_H
# define LOGIC_ARIT_H

#include "Conjunto_de_Instrucoes.h"
#include "pilhaFrames.h"
#include "Method_area.h"
#include "classfile.h"
#include <math.h>
#include <stdint.h>
#include <string.h>

void iadd(Frame *);

void ladd(Frame *);

void fadd(Frame *);

void dadd(Frame *);

void isub(Frame *);

void lsub(Frame *);

void fsub(Frame *);

void dsub(Frame *);

void imul(Frame *);

void lmul(Frame *);

void fmul(Frame *);

void dmul(Frame *);

void idiv(Frame *);

void l_div(Frame *);

void fdiv(Frame *);

void ddiv(Frame *);

void irem(Frame *);

void lrem(Frame *);

void frem(Frame *);

void drem(Frame *);

void ineg(Frame *);

void lneg(Frame *);

void fneg(Frame *);

void dneg(Frame *);

void ishl(Frame *);

void lshl(Frame *);

void ishr(Frame *);

void lshr(Frame *);

void iushr(Frame *);

void lushr(Frame *);

void iand(Frame *);

void land(Frame *);

void ior(Frame *);

void lor(Frame *);

void ixor(Frame *);

void lxor(Frame *);

void iinc(Frame *, u1, u1);

# endif
