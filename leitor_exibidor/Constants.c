/**
* @file   Constants.c
* @author Andrei Buslik
* @brief  Arquivo com os códigos das funções declaradas no arquivo Constants.h.
**/

# include "Constants.h"


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

void fconst_0(Frame *frame){
	u4 operando;
	float cpy = 0.0;

	memcpy(&operando, &cpy, sizeof(u4));

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void fconst_1(Frame *frame){
	u4 operando_Inferior;
	u4 operando_Superior;
	float cpyI = 1.0, cpyS = 0.0;

	memcpy(&operando_Inferior, &cpyI, sizeof(u4));
	memcpy(&operando_Superior, &cpyS, sizeof(u4));

	empilha_operando(&(frame->pilha_operandos), operando_Inferior);
	empilha_operando(&(frame->pilha_operandos), operando_Superior);

	return;
}

void fconst_2(Frame *frame){
	u4 operando_Inferior;
	u4 operando_Superior;
	float cpyI = 2.0, cpyS = 0.0;

	memcpy(&operando_Inferior, &cpyI, sizeof(u4));
	memcpy(&operando_Superior, &cpyS, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), operando_Inferior);
	empilha_operando(&(frame->pilha_operandos), operando_Superior);

	return;
}

void dconst_0(Frame *frame){
	u4 operando;
	double cpy = 0.0;

	memcpy(&operando, &cpy, sizeof(u4));

	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}

void dconst_1(Frame *frame){
	u4 operando_Inferior;
	u4 operando_Superior;
	double cpyI = 1.0, cpyS = 0.0;

	memcpy(&operando_Inferior, &cpyI, sizeof(u4));
	memcpy(&operando_Superior, &cpyS, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), operando_Inferior);
	empilha_operando(&(frame->pilha_operandos), operando_Superior);

	return;
}

void decodebipush(Frame *frame){
	u1 indice = 0;
	u4 cast_op;
	
	indice = frame->codigo->code.code[++frame->pc];
	cast_op = (u4)indice;
	
	empilha_operando(&(frame->pilha_operandos), cast_op);
	
	return;
}

void decodesipush(Frame *frame){
	u1 indice_1 = 0, indice_2 = 0;
	u2 cast_op;
	u4 pont_cast_op;
	
	indice_1 = frame->codigo->code.code[++frame->pc];
	indice_2 = frame->codigo->code.code[++frame->pc];
	
	cast_op = (u2) (indice_1 << 8 | indice_2);
	
	pont_cast_op = &cast_op;
	
	empilha_operando(&(frame->pilha_operandos), &pont_cast_op);
	
	return;
}

void decodeldc(Frame *frame){
	
	
	return;
}