/**
* @file   Constants.c
* @author Andrei Buslik Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Comparisions.h.
**/

#include "Comparision.h"

void lcmp(Frame * frame) {
	int64_t value1;
	int64_t value2;
	u4 result = 0;

	value2 = desempilha_operando_64(&(frame->pilha_operandos));
	value1 = desempilha_operando_64(&(frame->pilha_operandos));

	if(value1 == value2){
		empilha_operando(&(frame->pilha_operandos), result);
	}else if(value1 > value2){
		result = 1;
		empilha_operando(&(frame->pilha_operandos), result);
	}else{
		result = -1;
		empilha_operando(&(frame->pilha_operandos), result);
	}
}

void fcmp(Frame * frame) {
	float value1;
	float value2;
	u4 op_1;
	u4 op_2;
	u4 result = 0;

	op_2 = desempilha_operando(&(frame->pilha_operandos));
	op_1 = desempilha_operando(&(frame->pilha_operandos));

	memcpy(&value1, &op_1, sizeof(u4));
	memcpy(&value2, &op_2, sizeof(u4));

	if(value1 == value2){
		empilha_operando(&(frame->pilha_operandos), result);
	}else if(value1 > value2){
		result = 1;
		empilha_operando(&(frame->pilha_operandos), result);
	}else{
		result = -1;
		empilha_operando(&(frame->pilha_operandos), result);
	}
}

void fcmpg(Frame * frame) {
	float value1;
	float value2;
	u4 op_1;
	u4 op_2;
	u4 result = 0;

	op_2 = desempilha_operando(&(frame->pilha_operandos));
	op_1 = desempilha_operando(&(frame->pilha_operandos));

	memcpy(&value1, &op_1, sizeof(u4));
	memcpy(&value2, &op_2, sizeof(u4));

	if(value1 == value2){
		empilha_operando(&(frame->pilha_operandos), result);
	}else if(value1 > value2){
		result = 1;
		empilha_operando(&(frame->pilha_operandos), result);
	}else if(value1 < value2){
		result = -1;
		empilha_operando(&(frame->pilha_operandos), result);
	}else{
		result = -1;
		empilha_operando(&(frame->pilha_operandos), result);
	}
}

void dcmpl(Frame * frame) {
	double value1;
	double value2;
	u8 op_1;
	u8 op_2;
	u4 result = 0;

	op_2 = desempilha_operando_64(&(frame->pilha_operandos));
	op_1 = desempilha_operando_64(&(frame->pilha_operandos));

	memcpy(&value1, &op_1, sizeof(u8));
	memcpy(&value2, &op_2, sizeof(u8));

	if(value1 == value2){
		empilha_operando(&(frame->pilha_operandos), result);
	}else if(value1 > value2){
		result = 1;
		empilha_operando(&(frame->pilha_operandos), result);
	}else{
		result = -1;
		empilha_operando(&(frame->pilha_operandos), result);
	}
}

void dcmpg(Frame * frame) {
	double value1;
	double value2;
	u8 op_1;
	u8 op_2;
	u4 result = 0;

	op_2 = desempilha_operando_64(&(frame->pilha_operandos));
	op_1 = desempilha_operando_64(&(frame->pilha_operandos));

	memcpy(&value1, &op_1, sizeof(u8));
	memcpy(&value2, &op_2, sizeof(u8));

	if(value1 == value2){
		empilha_operando(&(frame->pilha_operandos), result);
	}else if(value1 > value2){
		result = 1;
		empilha_operando(&(frame->pilha_operandos), result);
	}else if(value1 < value2){
		result = -1;
		empilha_operando(&(frame->pilha_operandos), result);
	}else{
		result = -1;
		empilha_operando(&(frame->pilha_operandos), result);
	}
}


void if_eq(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value = desempilha_operando(&(frame->pilha_operandos));
	if (value == 0) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_ne(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value = desempilha_operando(&(frame->pilha_operandos));
	if (value != 0) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_lt(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value = desempilha_operando(&(frame->pilha_operandos));
	if (value < 0) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_ge(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value = desempilha_operando(&(frame->pilha_operandos));
	if (value >= 0) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_gt(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value = desempilha_operando(&(frame->pilha_operandos));
	if (value > 0) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_le(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value = desempilha_operando(&(frame->pilha_operandos));
	if (value <= 0) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_icmpeq(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
	int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
	if (value1 == value2) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_icmpne(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
	int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
	if (value1 != value2) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_icmplt(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
	int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
	if (value1 < value2) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_icmpge(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
	int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
	if (value1 >= value2) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		printf("%d\n", offset);
		frame->pc += (offset - 3);
	}
}
void if_icmpgt(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
	int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
	if (value1 > value2) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}

void if_icmple(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
    int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
    if(value1 <= value2){
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
    }
}

void if_acmpeq(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
	int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
	if (value1 == value2) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
void if_acmpne(Frame *frame, u1 branchbyte1, u1 branchbyte2) {
	int32_t value2 = desempilha_operando(&(frame->pilha_operandos));
	int32_t value1 = desempilha_operando(&(frame->pilha_operandos));
	if (value1 != value2) {
		int16_t offset = (((u2) branchbyte1) << 8) + branchbyte2;
		frame->pc += (offset - 3);
	}
}
