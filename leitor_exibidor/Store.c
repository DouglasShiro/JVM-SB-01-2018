/**
* @file   Store.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Store.h.
**/

#include "Store.h"

void istore_0(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[0] = value;
}

void istore_1(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[1] = value;
}

void istore_2(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[1] = value;
}

void istore_3(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[3] = value;
}
