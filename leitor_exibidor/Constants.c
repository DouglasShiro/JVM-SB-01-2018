/**
* @file   Constants.c
* @author Andrei Buslik
* @brief  Arquivo com os códigos das funções declaradas no arquivo Constants.h.
**/

# include "Constants.h"
# include <stdint.h>

void nop (){
	return;
}

void aconst_null(Frame *frame){
    u4 operando = 0;
    empilha_operando(&(frame->pilha_operandos), operando);

    return;
};

void iconst_m1(Frame *frame){
	int32_t operando = -1;

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void iconst_0(Frame *frame){
	u4 operando = 0;

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void iconst_1(Frame *frame){
	u4 operando = 1;

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void iconst_2(Frame *frame){
	u4 operando = 2;

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void iconst_3(Frame *frame){
	u4 operando = 3;

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void iconst_4(Frame *frame){
	u4 operando = 4;

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void iconst_5(Frame *frame){
	u4 operando = 5;

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void lconst_0(Frame *frame){
	u4 operando = 0;

	empilha_operando(&(frame->pilha_operandos), operando);
	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void lconst_1(Frame *frame){
	u4 operando_Inferior = 1;
	u4 operando_Superior = 0;

	empilha_operando(&(frame->pilha_operandos), operando_Inferior);
	empilha_operando(&(frame->pilha_operandos), operando_Superior);

	return;
}

void aload_0(Frame *frame){
	u4 operando;
	operando = frame->variaveis_locais[0];

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}
