/**
* @file   Constants.h
* @author Andrei Buslik
* @brief  Arquivo com as estruturas das instruções do tipo constantes.
**/

# ifndef CONSTANTS.H
# define CONSTANTS.H

# include Conjunto_de_instrucoes.h
# include pilhaFrames.h
# include Method_area.h
# include classfile.h

void nop();

void aconst_null(Frame *);

void iconst_m1(Frame *);

void iconst_0(Frame *);

void iconst_1(Frame *);

void iconst_2(Frame *);

void iconst_3(Frame *);

void iconst_4(Frame *);

void iconst_5(Frame *);


# endif
