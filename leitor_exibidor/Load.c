/**
* @file   Load.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Load.h.
**/

#include "Load.h"

void iload_0(Frame *frame){
   empilha_operando(
	   &(frame->pilha_operandos),
	   (frame->variaveis_locais[0])
   );
   return;
}

void iload_1(Frame *frame){
   empilha_operando(
	   &(frame->pilha_operandos),
	   (frame->variaveis_locais[1])
   );
   return;
}

void iload_2(Frame *frame){
	empilha_operando(
	   &(frame->pilha_operandos),
	   (frame->variaveis_locais[2])
   );
   return;
}

void iload_3(Frame *frame){
   empilha_operando(
	   &(frame->pilha_operandos),
	   (frame->variaveis_locais[3])
   );
   return;
}

void aload_0(Frame *frame){
   u4 operando;

   operando = frame->variaveis_locais[0];
   empilha_operando(&(frame->pilha_operandos), operando);

   return;
}

void aload_1(Frame *frame){
   u4 operando;

   operando = frame->variaveis_locais[1];
   empilha_operando(&(frame->pilha_operandos), operando);

   return;
}

void aload_2(Frame *frame){
   u4 operando;

   operando = frame->variaveis_locais[2];
   empilha_operando(&(frame->pilha_operandos), operando);

   return;
}

void aload_3(Frame *frame){
   u4 operando;

   operando = frame->variaveis_locais[3];
   empilha_operando(&(frame->pilha_operandos), operando);

   return;
}
