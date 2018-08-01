/**
* @file   Load.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções de leitura.
**/

# ifndef LOAD_H
# define LOAD_H

# include "Conjunto_de_Instrucoes.h"

void iload(Frame *, u1);
void lload(Frame *, u1);
void fload(Frame *, u1);
void dload(Frame *, u1);
void aload(Frame *, u1);
void iload_0(Frame *);
void iload_1(Frame *);
void iload_2(Frame *);
void iload_3(Frame *);
void lload_0(Frame *);
void lload_1(Frame *);
void lload_2(Frame *);
void lload_3(Frame *);

void fload_0(Frame *);
void fload_1(Frame *);
void fload_2(Frame *);
void fload_3(Frame *);
void dload_0(Frame *);
void dload_1(Frame *);
void dload_2(Frame *);
void dload_3(Frame *);

void aload_0(Frame *);
void aload_1(Frame *);
void aload_2(Frame *);
void aload_3(Frame *);

void iaload(Frame *);
void laload(Frame *);
void faload(Frame *);
void daload(Frame *);
void aaload(Frame *);
void baload(Frame *);
void caload(Frame *);
void saload(Frame *);

# endif
