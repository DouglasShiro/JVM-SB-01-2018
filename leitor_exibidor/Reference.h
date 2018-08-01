/**
* @file   Reference.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções de referências.
**/

# ifndef REFERENCE_H
# define REFERENCE_H

# include "Conjunto_de_Instrucoes.h"

void getstatic(Frame *, Pilha_frames* pilha_frames, u1 indexbyte1, u1 indexbyte2);

void putstatic(Frame *);
void getfield(Frame *);
void putfield(Frame *);

void invokevirtual(Frame* frame, Pilha_frames* pilha_frames, u1 indexbyte1, u1 indexbyte2);
void invokespecial(Frame* frame, Pilha_frames* pilha_frames, u1 indexbyte1, u1 indexbyte2);

void invokestatic(Frame *);
void invokeinterface(Frame *);
void invokedynamic(Frame *);
void new_(Frame *);
void newarray(Frame *, u1);
void anewarray(Frame *);
void arraylength(Frame *);
void athrow(Frame *);
void checkcast(Frame *);
void instanceof(Frame *);
void monitorenter(Frame *);
void monitorexit(Frame *);

# endif
