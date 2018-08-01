/**
* @file   Store.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Store.h.
**/

#include "Store.h"

void istore(Frame* frame, u1 index) {
	u4 value;

	value = desempilha_operando(&(frame->pilha_operandos));
	frame->variaveis_locais[index] = value;
}

void lstore(Frame* frame, u1 index) {
	u8 value;

	value = desempilha_operando_64(&(frame->pilha_operandos));

	frame->variaveis_locais[index] = (value) >> 32;
	frame ->variaveis_locais[index+1] = (value) & 0x00000000FFFFFFFF;
}

void fstore(Frame* frame, u1 index) {
	u4 value;

	value = desempilha_operando(&(frame->pilha_operandos));
	frame->variaveis_locais[index] = value;
}

void dstore(Frame* frame, u1 index) {
	u8 value;

	value = desempilha_operando_64(&(frame->pilha_operandos));

	frame->variaveis_locais[index] = (value) >> 32;
	frame ->variaveis_locais[index+1] = (value) & 0x00000000FFFFFFFF;
}

void astore(Frame* frame, u1 index) {
	u4 value;

	value = desempilha_operando(&(frame->pilha_operandos));
	frame->variaveis_locais[index] = value;
}

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

void lstore_0(Frame * frame) {
	u8 value;

	value = desempilha_operando_64(&(frame->pilha_operandos));
    frame->variaveis_locais[0] = (value) >> 32;
    frame ->variaveis_locais[1] = (value) & 0x00000000FFFFFFFF;
}

void lstore_1(Frame * frame) {
	u8 value;

	value = desempilha_operando_64(&(frame->pilha_operandos));
    frame->variaveis_locais[1] = (value) >> 32;
    frame ->variaveis_locais[2] = (value) & 0x00000000FFFFFFFF;
}

void lstore_2(Frame * frame) {
	u8 value;

	value = desempilha_operando_64(&(frame->pilha_operandos));
    frame->variaveis_locais[2] = (value) >> 32;
    frame ->variaveis_locais[3] = (value) & 0x00000000FFFFFFFF;
}

void lstore_3(Frame * frame) {
	u8 value;

	value = desempilha_operando_64(&(frame->pilha_operandos));
    frame->variaveis_locais[3] = (value) >> 32;
    frame ->variaveis_locais[4] = (value) & 0x00000000FFFFFFFF;
}

void fstore_0(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[0] = value;
}

void fstore_1(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[1] = value;
}

void fstore_2(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[1] = value;
}

void fstore_3(Frame * frame) {
	u4 value = desempilha_operando(&(frame->pilha_operandos));
    frame->variaveis_locais[3] = value;
}

void dstore_0(Frame * frame) {

}

void dstore_1(Frame * frame) {

}

void dstore_2(Frame * frame) {

}

void dstore_3(Frame * frame) {

}

void astore_0(Frame * frame) {

}

void astore_1(Frame * frame) {

}

void astore_2(Frame * frame) {

}

void astore_3(Frame * frame) {

}

void iastore(Frame * frame) {

}

void lastore(Frame * frame) {

}

void fastore(Frame * frame) {

}

void dastore(Frame * frame) {

}

void aastore(Frame * frame) {

}

void bastore(Frame * frame) {

}

void castore(Frame * frame) {

}

void sastore(Frame * frame) {

}
