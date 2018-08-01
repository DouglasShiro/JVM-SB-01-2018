/**
* @file   Load.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Load.h.
**/

#include "Load.h"

void iload(Frame* frame, u1 index) {
	empilha_operando(
		&(frame->pilha_operandos),
		(frame->variaveis_locais[index])
	);
}

void lload(Frame* frame, u1 index) {
	u8 result;

	result = (
		((u8)frame->variaveis_locais[index]) << 32) |
		(frame->variaveis_locais[index]
	);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void fload(Frame* frame, u1 index) {
	empilha_operando(
		&(frame->pilha_operandos),
		(frame->variaveis_locais[index])
	);
}

void dload(Frame* frame, u1 index) {
	u8 result;

	result = (
		((u8)frame->variaveis_locais[index]) << 32) |
		(frame->variaveis_locais[index]
	);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void aload(Frame* frame, u1 index) {
	empilha_operando(
		&(frame->pilha_operandos),
		(frame->variaveis_locais[index])
	);
}

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

void fload_0(Frame * frame) {

}

void fload_1(Frame * frame) {

}

void fload_2(Frame * frame) {

}

void fload_3(Frame * frame) {

}

void dload_0(Frame * frame) {

}

void dload_1(Frame * frame) {

}

void dload_2(Frame * frame) {

}

void dload_3(Frame * frame) {

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

void lload_0(Frame *frame){
	u8 result;

	result = (
		((u8)frame->variaveis_locais[0]) << 32) |
		(frame->variaveis_locais[0 + 1]
	);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void lload_1(Frame *frame){
	u8 result;

	result = (
		((u8)frame->variaveis_locais[1]) << 32) |
		(frame->variaveis_locais[1 + 1]
	);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void lload_2(Frame *frame){
	u8 result;

	result = (
		((u8)frame->variaveis_locais[2]) << 32) |
		(frame->variaveis_locais[2 + 1]
	);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void lload_3(Frame *frame){
	u8 result;

	result = (
		((u8)frame->variaveis_locais[3]) << 32) |
		(frame->variaveis_locais[3 + 1]
	);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void iaload(Frame * frame) {

}

void laload(Frame * frame) {

}

void faload(Frame * frame) {

}

void daload(Frame * frame) {

}

void aaload(Frame * frame) {

}

void baload(Frame * frame) {

}

void caload(Frame * frame) {

}

void saload(Frame * frame) {

}
