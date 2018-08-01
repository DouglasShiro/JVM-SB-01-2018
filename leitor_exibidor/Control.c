/**
* @file   Constants.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Control.h.
**/

# include "Control.h"

void goto_(Frame * frame) {

}

void jsr(Frame * frame) {

}

void ret(Frame * frame) {

}

void tableswtich(Frame * frame) {

}

void lookupswitch(Frame * frame) {

}

void ireturn(Frame * frame) {

}

void lreturn(Frame * frame) {

}

void freturn(Frame * frame) {

}

void dreturn(Frame * frame) {

}

void areturn(Frame * frame) {

}


void return_(Frame* frame) {
	frame->pc = frame->codigo->code.code_length;
}
