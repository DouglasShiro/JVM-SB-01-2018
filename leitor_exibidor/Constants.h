/**
* @file   Constants.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções que utilizam constantes.
**/

# ifndef CONSTANTS_H
# define CONSTANTS_H

# include "Conjunto_de_Instrucoes.h"
# include "pilhaFrames.h"
# include "Method_area.h"
# include "classfile.h"

void nop();

void aconst_null(Frame *);

void iconst_m1(Frame *);

void iconst_0(Frame *);

void iconst_1(Frame *);

void iconst_2(Frame *);

void iconst_3(Frame *);

void iconst_4(Frame *);

void iconst_5(Frame *);

void lconst_0(Frame *);

void lconst_1(Frame *);

void fconst_0(Frame *);

void fconst_1(Frame *);

void fconst_2(Frame *);

void dconst_0(Frame *);

void dconst_1(Frame *);


void aload_0(Frame *);


# endif
