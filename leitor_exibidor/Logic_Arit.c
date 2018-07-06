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

/*void fadd(Frame *){
	
	
	return;
}*/