/**
* @file   Logic_Arit.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Logic_Arit.h.
**/

#include "Logic_Arit.h"

void iadd(Frame *frame){
	int32_t operando1, operando2, temp;
	u4 resultado;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	temp = operando1 + operando2;
	
	memcpy(&resultado, &temp, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void ladd(Frame *frame){
	int64_t operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, operando1, operando2, temp;
	u4 resultado_Superior, resultado_Inferior, temp_Superior, temp_Inferior;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando2 = (operando2_Superior << 32) | operando2_Inferior; 
	operando1 = (operando1_Superior << 32) | operando1_Inferior;
	
	temp = operando1 + operando2;
	
	temp_Inferior = 0x0000 & temp;
	temp_Superior = 0xFFFF0000 & temp;
	
	memcpy(&resultado_Inferior, &temp_Inferior, sizeof(u4));
	memcpy(&resultado_Superior, &temp_Superior, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void fadd(Frame *frame){
	u4 operando1, operando2, resultado;
	float temp1, temp2;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	memcpy(&temp1, &operando1, sizeof(u4));
	memcpy(&temp2, &operando2, sizeof(u4));
	
	resultado = temp1 + temp2;
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void dadd(Frame *frame){
	u4 resultado_Superior, resultado_Inferior;
	u8 operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, temp1, temp2,resultado;
	double operando1, operando2, d_resultado;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	temp1 = (operando1_Superior << 32) | operando1_Inferior;
	temp2 = (operando2_Superior << 32) | operando2_Inferior;
	
	memcpy(&operando1, &temp1, sizeof(u8));
	memcpy(&operando2, &temp2, sizeof(u8));
	
	d_resultado = operando1 + operando2;
	
	memcpy(&resultado, &d_reultado, sizeof(u8));
	
	resultado_Superior = 0xFFFF0000 & resultado;
	resultado_Inferior = 0x0000FFFF & resultado;
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void isub(Frame *frame){
	int32_t operando1, operando2, temp;
	u4 resultado;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	temp = operando1 - operando2;
	
	memcpy(&resultado, &temp, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void ladd(Frame *frame){
	int64_t operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, operando1, operando2, temp;
	u4 resultado_Superior, resultado_Inferior, temp_Superior, temp_Inferior;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando2 = (operando2_Superior << 32) | operando2_Inferior; 
	operando1 = (operando1_Superior << 32) | operando1_Inferior;
	
	temp = operando1 + operando2;
	
	temp_Inferior = 0x0000FFFF & temp;
	temp_Superior = 0xFFFF0000 & temp;
	
	memcpy(&resultado_Inferior, &temp_Inferior, sizeof(u4));
	memcpy(&resultado_Superior, &temp_Superior, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void lsub(Frame *frame){
	int64_t operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, operando1, operando2, temp;
	u4 resultado_Superior, resultado_Inferior, temp_Superior, temp_Inferior;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando2 = (operando2_Superior << 32) | operando2_Inferior; 
	operando1 = (operando1_Superior << 32) | operando1_Inferior;
	
	temp = operando1 - operando2;
	
	temp_Inferior = 0x0000FFFF & temp;
	temp_Superior = 0xFFFF0000 & temp;
	
	memcpy(&resultado_Inferior, &temp_Inferior, sizeof(u4));
	memcpy(&resultado_Superior, &temp_Superior, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void fsub(Frame *frame){
	u4 operando1, operando2, resultado;
	float temp1, temp2;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	memcpy(&temp1, &operando1, sizeof(u4));
	memcpy(&temp2, &operando2, sizeof(u4));
	
	resultado = temp1 - temp2;
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void dsub(Frame *frame){
	u4 resultado_Superior, resultado_Inferior;
	u8 operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, temp1, temp2,resultado;
	double operando1, operando2, d_resultado;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	temp1 = (operando1_Superior << 32) | operando1_Inferior;
	temp2 = (operando2_Superior << 32) | operando2_Inferior;
	
	memcpy(&operando1, &temp1, sizeof(u8));
	memcpy(&operando2, &temp2, sizeof(u8));
	
	d_resultado = operando1 - operando2;
	
	memcpy(&resultado, &d_reultado, sizeof(u8));
	
	resultado_Superior = 0xFFFF0000 & resultado;
	resultado_Inferior = 0x0000FFFF & resultado;
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void imul(Frame *frame){
	int32_t operando1, operando2, temp;
	u4 resultado;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	temp = operando1 * operando2;
	
	memcpy(&resultado, &temp, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void lmul(Frame *frame){
	int64_t operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, operando1, operando2, temp;
	u4 resultado_Superior, resultado_Inferior, temp_Superior, temp_Inferior;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando2 = (operando2_Superior << 32) | operando2_Inferior; 
	operando1 = (operando1_Superior << 32) | operando1_Inferior;
	
	temp = operando1 * operando2;
	
	temp_Inferior = 0x0000FFFF & temp;
	temp_Superior = 0xFFFF0000 & temp;
	
	memcpy(&resultado_Inferior, &temp_Inferior, sizeof(u4));
	memcpy(&resultado_Superior, &temp_Superior, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void fmul(Frame *frame){
	u4 operando1, operando2, resultado;
	float temp1, temp2;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	memcpy(&temp1, &operando1, sizeof(u4));
	memcpy(&temp2, &operando2, sizeof(u4));
	
	resultado = temp1 * temp2;
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void dsub(Frame *frame){
	u4 resultado_Superior, resultado_Inferior;
	u8 operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, temp1, temp2,resultado;
	double operando1, operando2, d_resultado;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	temp1 = (operando1_Superior << 32) | operando1_Inferior;
	temp2 = (operando2_Superior << 32) | operando2_Inferior;
	
	memcpy(&operando1, &temp1, sizeof(u8));
	memcpy(&operando2, &temp2, sizeof(u8));
	
	d_resultado = operando1 * operando2;
	
	memcpy(&resultado, &d_reultado, sizeof(u8));
	
	resultado_Superior = 0xFFFF0000 & resultado;
	resultado_Inferior = 0x0000FFFF & resultado;
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void idiv(Frame *frame){
	int32_t operando1, operando2, temp;
	u4 resultado;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	temp = operando1 / operando2;
	
	memcpy(&resultado, &temp, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void ldiv(Frame *frame){
	int64_t operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, operando1, operando2, temp;
	u4 resultado_Superior, resultado_Inferior, temp_Superior, temp_Inferior;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando2 = (operando2_Superior << 32) | operando2_Inferior; 
	operando1 = (operando1_Superior << 32) | operando1_Inferior;
	
	temp = operando1 / operando2;
	
	temp_Inferior = 0x0000FFFF & temp;
	temp_Superior = 0xFFFF0000 & temp;
	
	memcpy(&resultado_Inferior, &temp_Inferior, sizeof(u4));
	memcpy(&resultado_Superior, &temp_Superior, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void fmul(Frame *frame){
	u4 operando1, operando2, resultado;
	float temp1, temp2;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	memcpy(&temp1, &operando1, sizeof(u4));
	memcpy(&temp2, &operando2, sizeof(u4));
	
	resultado = temp1 / temp2;
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void ddiv(Frame *frame){
	u4 resultado_Superior, resultado_Inferior;
	u8 operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, temp1, temp2,resultado;
	double operando1, operando2, d_resultado;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	temp1 = (operando1_Superior << 32) | operando1_Inferior;
	temp2 = (operando2_Superior << 32) | operando2_Inferior;
	
	memcpy(&operando1, &temp1, sizeof(u8));
	memcpy(&operando2, &temp2, sizeof(u8));
	
	d_resultado = operando1 / operando2;
	
	memcpy(&resultado, &d_reultado, sizeof(u8));
	
	resultado_Superior = 0xFFFF0000 & resultado;
	resultado_Inferior = 0x0000FFFF & resultado;
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void irem(Frame *frame){
	int32_t operando1, operando2, temp;
	u4 resultado;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	temp = operando1 % operando2;
	
	memcpy(&resultado, &temp, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void lrem(Frame *frame){
	int64_t operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, operando1, operando2, temp;
	u4 resultado_Superior, resultado_Inferior, temp_Superior, temp_Inferior;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando2 = (operando2_Superior << 32) | operando2_Inferior; 
	operando1 = (operando1_Superior << 32) | operando1_Inferior;
	
	temp = operando1 % operando2;
	
	temp_Inferior = 0x0000FFFF & temp;
	temp_Superior = 0xFFFF0000 & temp;
	
	memcpy(&resultado_Inferior, &temp_Inferior, sizeof(u4));
	memcpy(&resultado_Superior, &temp_Superior, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void frem(Frame *frame){
	u4 operando1, operando2, resultado;
	float temp1, temp2;
	
	operando2 = desempilha_operando(&(frame->pilha_operandos));
	operando1 = desempilha_operando(&(frame->pilha_operandos));
	
	memcpy(&temp1, &operando1, sizeof(u4));
	memcpy(&temp2, &operando2, sizeof(u4));
	
	resultado = temp1 % temp2;
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void drem(Frame *frame){
	u4 resultado_Superior, resultado_Inferior;
	u8 operando1_Superior, operando1_Inferior, operando2_Superior, operando2_Inferior, temp1, temp2,resultado;
	double operando1, operando2, d_resultado;
	
	operando2_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando2_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	operando1_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando1_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	temp1 = (operando1_Superior << 32) | operando1_Inferior;
	temp2 = (operando2_Superior << 32) | operando2_Inferior;
	
	memcpy(&operando1, &temp1, sizeof(u8));
	memcpy(&operando2, &temp2, sizeof(u8));
	
	d_resultado = operando1 % operando2;
	
	memcpy(&resultado, &d_reultado, sizeof(u8));
	
	resultado_Superior = 0xFFFF0000 & resultado;
	resultado_Inferior = 0x0000FFFF & resultado;
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}

void ineg(Frame *frame){
	int32_t operando, temp;
	u4 reultado;
	
	operando = desempilha_operando(&(frame->pilha_operandos));
	
	temp = ~operando;
	
	memcpy = (&resultado, &temp, sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado);
	
	return;
}

void lneg(Frame *frame){
	int64_t operando_Superior, operando_Inferior, temp_Superior, temp_Inferior;
	u4 reultado_Superior, resultado_Inferior;
	
	operando_Superior = desempilha_operando(&(frame->pilha_operandos));
	operando_Inferior = desempilha_operando(&(frame->pilha_operandos));
	
	temp = (operando_Superior << 32) | operando_Inferior;
	
	temp = ~temp;
	
	temp_Inferior = 0x0000FFFF & temp;
	temp_Superior = 0xFFFF0000 & temp;
	
	memcpy(&resultado_Inferior, &(temp_Inferior), sizeof(u4));
	memcpy(&resultado_Superior, &(temp_Superior), sizeof(u4));
	
	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);
	
	return;
}