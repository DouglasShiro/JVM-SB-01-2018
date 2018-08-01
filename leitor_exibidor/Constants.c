/**
* @file   Constants.c
* @author Andrei Buslik
* @brief  Arquivo com os códigos das funções declaradas no arquivo Constants.h.
**/

# include "Constants.h"
# include <string.h>


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
	u4 operando_Inferior = 0, operando_Superior = 0;

	empilha_operando(&(frame->pilha_operandos), operando_Inferior);
	empilha_operando(&(frame->pilha_operandos), operando_Superior);

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
	u1 indice_1, indice_2;
	u2 cast_op;
	u4 pont_cast_op;

	indice_1 = frame->codigo->code.code[++frame->pc];
	indice_2 = frame->codigo->code.code[++frame->pc];

	cast_op = (u2) (indice_1 << 8 | indice_2);

	pont_cast_op = &cast_op;

	empilha_operando(&(frame->pilha_operandos), pont_cast_op);

	return;
}

void decodeldc(Frame *frame){
	u1 indice;
	u1 Tag;
	u4 dado;
	cp_info *Const_Pool = frame->constant_pool;

	indice = frame->codigo->code.code[++frame->pc];
	Tag = Const_Pool[indice - 1].tag;

	switch(Tag){
		case CONSTANT_Integer:
			empilha_operando(&(frame->pilha_operandos), &Const_Pool[indice - 1].integer_info.bytes);
			break;

		case CONSTANT_Float:
			dado = Const_Pool[indice - 1].float_info.bytes;

			empilha_operando(&(frame->pilha_operandos), &dado);
			break;

		case CONSTANT_String:
			dado = Const_Pool[indice - 1].string_info.bytes;

			empilha_operando(&(frame->pilha_operandos), &dado);
			break;
	}

	return;
}

void decodeldc_w(Frame *frame){
	u1 indice_1, indice_2, indice_3;
	cp_info *Const_Pool;
	u1 Tag;
	u4 dado;

	indice_1 = frame->codigo->code.code[++frame->pc];
	indice_2 = frame->codigo->code.code[++frame->pc];

	indice_3 = (indice_1 << 8 | indice_2);

	Const_Pool = frame->constant_pool;
	Tag = Const_Pool[indice_3 - 1].tag;

	switch(Tag){
		case CONSTANT_Integer:
			empilha_operando(&(frame->pilha_operandos), &Const_Pool[indice_3 - 1].integer_info.bytes);

			break;

		case CONSTANT_Float:
			dado = Const_Pool[indice_3 - 1].float_info.bytes;

			empilha_operando(&(frame->pilha_operandos), &dado);
			break;

		case CONSTANT_String:
			dado = Const_Pool[indice_3 - 1].string_info.bytes;

			empilha_operando(&(frame->pilha_operandos), &dado);
			break;

	}

	return;
}

void decodeldc2_w(Frame *frame){
	u1 indice_1, indice_2, indice_3;
	cp_info *Const_Pool;
	u1 Tag;
	u8 dado;

	indice_1 = frame->codigo->code.code[++frame->pc];
	indice_2 = frame->codigo->code.code[++frame->pc];

	indice_3 = (indice_1 << 8 | indice_2);

	Const_Pool = frame->constant_pool;
	Tag = Const_Pool[indice_3 - 1].tag;

	switch(Tag){
		case CONSTANT_Long:
			dado = (u8)Const_Pool[indice_3 - 1].long_info.high_bytes;
			empilha_operando(&(frame->pilha_operandos), &dado);

			dado = (u8)Const_Pool[indece_3 - 1].long_info.low_bytes;
			empilha_operando(&(frame->pilha_operandos), &dado);

			break;

		case CONSTANT_Double:
			dado = (u8)Const_Pool[indice_3 - 1].double_info.high_bytes;
			empilha_operando(&(frame->pilha_operandos), &dado);

			dado = (u8)Const_Pool[indece_3 - 1].double_info.low_bytes;
			empilha_operando(&(frame->pilha_operandos), &dado);


			break;

	}

	return;
}
