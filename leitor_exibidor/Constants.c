/**
* @file   Constants.c
* @author Andrei Buslik
* @brief  Arquivo com os códigos das funções declaradas no arquivo Constants.h.
**/

# include "Constants.h"
# include <stdint.h>
# include <math.h>

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

	return;
}

void aload_0(Frame *frame){
	u4 operando;
<<<<<<< HEAD
	
	operando = frame->*(variaveis_locais);
	
=======

	operando = frame->variaveis_locais[0];

>>>>>>> e6018343f3dc0e768c77813ca417918c276257aa
	empilha_operando(&(frame->pilha_operandos), operando);

	return;
}
<<<<<<< HEAD

=======
>>>>>>> e6018343f3dc0e768c77813ca417918c276257aa
