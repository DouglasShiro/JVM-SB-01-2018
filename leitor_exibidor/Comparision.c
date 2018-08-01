/**
* @file   Constants.c
* @author Andrei Buslik Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Comparisions.h.
**/

#include "Comparision.h"

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
