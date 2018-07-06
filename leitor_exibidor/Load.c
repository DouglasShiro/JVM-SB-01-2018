/**
* @file   Load.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Load.h.
**/

#include "Load.h"

void aload_0(Frame *frame){
   u4 operando;

   operando = frame->variaveis_locais[0];
   empilha_operando(&(frame->pilha_operandos), operando);


   return;
}
