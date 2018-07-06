/**
* @file   Control.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções de controle de fluxo de programa.
**/

# ifndef CONTROL_H
# define CONTROL_H

# include "Conjunto_de_Instrucoes.h"
# include "pilhaFrames.h"
# include "Method_area.h"
# include "classfile.h"

void return_(Frame* frame);

# endif
