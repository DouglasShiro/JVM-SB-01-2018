/**
* @file   Control.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções de controle de fluxo de programa.
**/

# ifndef CONTROL_H
# define CONTROL_H

# include "Conjunto_de_Instrucoes.h"
# include "pilhaFrames.h"
# include "Method_area.h"
# include "classfile.h"

void goto_(Frame *);
void jsr(Frame *);
void ret(Frame *);
void tableswtich(Frame *);
void lookupswitch(Frame *);
void ireturn(Frame *);
void lreturn(Frame *);
void freturn(Frame *);
void dreturn(Frame *);
void areturn(Frame *);

void return_(Frame *);

# endif
