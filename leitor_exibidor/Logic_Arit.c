
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

	memcpy(&resultado, &d_resultado, sizeof(u8));

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

void lsub(Frame *frame){
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

	memcpy(&resultado, &d_resultado, sizeof(u8));

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

void dmul(Frame *frame){
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

	memcpy(&resultado, &d_resultado, sizeof(u8));

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

	if (operando2 != 0)
		temp = operando1 / operando2;
	else
		temp = 0;

	memcpy(&resultado, &temp, sizeof(u4));

	empilha_operando(&(frame->pilha_operandos), resultado);

	return;
}

void l_div(Frame *frame){
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

void fdiv(Frame *frame){
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

	memcpy(&resultado, &d_resultado, sizeof(u8));

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

	resultado = fmod(temp1, temp2);

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

	d_resultado = fmod(operando1, operando2);

	memcpy(&resultado, &d_resultado, sizeof(u8));

	resultado_Superior = 0xFFFF0000 & resultado;
	resultado_Inferior = 0x0000FFFF & resultado;

	empilha_operando(&(frame->pilha_operandos), resultado_Inferior);
	empilha_operando(&(frame->pilha_operandos), resultado_Superior);

	return;
}

void ineg(Frame *frame){
	int32_t operando, temp;
	u4 resultado;

	operando = desempilha_operando(&(frame->pilha_operandos));

	temp = ~operando;

	memcpy(&resultado, &temp, sizeof(u4));

	empilha_operando(&(frame->pilha_operandos), resultado);

	return;
}

void lneg(Frame *frame){
	int64_t operando_Superior, operando_Inferior, temp_Superior, temp_Inferior, temp;
	u4 resultado_Superior, resultado_Inferior;

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

void fneg (Frame* frame) {
	float op_f, result_f;
	u4 result;
    u4 aux = desempilha_operando(&(frame->pilha_operandos));

    memcpy(&op_f, &aux, sizeof(u4));

	result_f = op_f * (-1);

	memcpy(&result, &result_f, sizeof(u4));

    empilha_operando(&(frame->pilha_operandos), result);
}

void dneg (Frame* frame) {
	double op_f, result_f;
	u8 result;
    u8 aux = desempilha_operando_64(&(frame->pilha_operandos));

    memcpy(&op_f, &aux, sizeof(u8));

	result_f = op_f * (-1);

	memcpy(&result, &result_f, sizeof(u8));

    empilha_operando(&(frame->pilha_operandos), result);
}

void ishl (Frame* frame) {
	int32_t value;
	u4 shift;
	u4 result;

	value = desempilha_operando(&(frame->pilha_operandos));
    shift = desempilha_operando(&(frame->pilha_operandos)) & 0x1F;
    value = (value << shift);

	memcpy(&result, &value, sizeof(u4));
    empilha_operando(&(frame->pilha_operandos), result);
}

void lshl (Frame* frame) {
	int64_t value;
	u4 shift;
	u8 result;

	value = desempilha_operando(&(frame->pilha_operandos));
    shift = desempilha_operando(&(frame->pilha_operandos)) & 0x1F;
    value = (value << shift);

	memcpy(&result, &value, sizeof(u8));
    empilha_operando_64(&(frame->pilha_operandos), result);
}

void ishr (Frame* frame) {
	int32_t value;
	u4 shift;
	u4 result;

	value = desempilha_operando(&(frame->pilha_operandos));
    shift = desempilha_operando(&(frame->pilha_operandos)) & 0x1F;
    value = (value >> shift);

	memcpy(&result, &value, sizeof(u4));
    empilha_operando(&(frame->pilha_operandos), result);
}

void lshr (Frame* frame) {
	int32_t value;
	u4 shift;
	u8 result;

	value = desempilha_operando(&(frame->pilha_operandos));
    shift = desempilha_operando(&(frame->pilha_operandos)) & 0x1F;
    value = (value >> shift);

	memcpy(&result, &value, sizeof(u8));
    empilha_operando_64(&(frame->pilha_operandos), result);
}

void iushr (Frame* frame) {
	u4 value;
	u4 shift;

	value = desempilha_operando(&(frame->pilha_operandos));
    shift = desempilha_operando(&(frame->pilha_operandos)) & 0x1F;
    value = (value >> shift);

    empilha_operando(&(frame->pilha_operandos), value);
}

void lushr (Frame* frame) {
	u4 value;
	u4 shift;

	value = desempilha_operando(&(frame->pilha_operandos));
    shift = desempilha_operando(&(frame->pilha_operandos)) & 0x1F;
    value = (value >> shift);

    empilha_operando_64(&(frame->pilha_operandos), value);
}

void iand (Frame* frame) {
	u4 value1;
	u4 value2;
	u4 result;

	value2 = desempilha_operando(&(frame->pilha_operandos));
    value1 = desempilha_operando(&(frame->pilha_operandos));
    result = (value1 & value2);

    empilha_operando(&(frame->pilha_operandos), result);
}

void land (Frame* frame) {
	u8 value1;
	u8 value2;
	u8 result;

	value2 = desempilha_operando_64(&(frame->pilha_operandos));
    value1 = desempilha_operando_64(&(frame->pilha_operandos));
    result = (value1 & value2);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void ior (Frame* frame) {
	u4 value1;
	u4 value2;
	u4 result;

	value2 = desempilha_operando(&(frame->pilha_operandos));
    value1 = desempilha_operando(&(frame->pilha_operandos));
    result = (value1 | value2);

    empilha_operando(&(frame->pilha_operandos), result);
}

void lor (Frame* frame) {
	u8 value1;
	u8 value2;
	u8 result;

	value2 = desempilha_operando_64(&(frame->pilha_operandos));
    value1 = desempilha_operando_64(&(frame->pilha_operandos));
    result = (value1 | value2);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void ixor (Frame* frame) {
	u4 value1;
	u4 value2;
	u4 result;

	value2 = desempilha_operando(&(frame->pilha_operandos));
    value1 = desempilha_operando(&(frame->pilha_operandos));
    result = (value1 ^ value2);

    empilha_operando(&(frame->pilha_operandos), result);
}

void lxor (Frame* frame) {
	u8 value1;
	u8 value2;
	u8 result;

	value2 = desempilha_operando_64(&(frame->pilha_operandos));
    value1 = desempilha_operando_64(&(frame->pilha_operandos));
    result = (value1 ^ value2);

    empilha_operando_64(&(frame->pilha_operandos), result);
}

void iinc (Frame* frame, u1 index, u1 inc) {
	frame->variaveis_locais[index] += inc;
}
