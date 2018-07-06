/**
* @file   Constants.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Control.h.
**/

# include "Control.h"

void return_(Frame* frame) {
	frame->pc = frame->codigo->code.code_length;
}
