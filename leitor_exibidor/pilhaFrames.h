/**
 *  @file pilhaFrames.h
 *  @author Adarley Luiz Grando Filho (11/0007344)
 *  @brief Definicao da estrutura da pilha de frames e dos metodos para acessa-los.
 */

#ifndef PILHAFRAMES_H
#define PILHAFRAMES_H

#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include "classfile.h"

typedef struct pilha_operandos {
    u4 op;
    struct pilha_operandos *prox;
} Pilha_operandos;

typedef struct frame {
	u4                      tamanho_variaveis_locais;
	u4                      *variaveis_locais;
	Pilha_operandos        	*pilha_operandos;
	u4                      pc;
	attribute_info			*codigo;
} Frame;

typedef struct pilha_frames {
    Frame *frame;
    struct pilha_frames *prox;
} Pilha_frames;

/**
 *  @fn void init_frame(method_info*, cp_info*)
 *  @brief Inicializa o frame.
 *  @param method_info* Ponteiro para method_info com informacoes sobre vetor de variaveis locais.
 *  @param cp_info* Ponteiro para o constant pool
 *  @return Frame inicializado
 */
 Frame* init_frame(method_info*, cp_info*);

/**
 *  @fn void init_pilha_operandos(Pilha_operandos **pilha)
 *  @brief Inicializa pilha de operandos setando a pilha para NULL.
 *  @param Pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 */
 void init_pilha_operandos(Pilha_operandos**);

 /**
 *  @fn void desaloca_pilha_operandos(Pilha_operandos **pilha)
 *  @brief Desaloca pilha de operandos e seta cabecao da pilha para NULL.
 *  @param Pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 */
 void desaloca_pilha_operandos(Pilha_operandos**);

  /**
 *  @fn void empilha_operando(Pilha_operandos **pilha, u4 op)
 *  @brief Empilha operando na pilha com base em modelo last-in-first-out.
 *  @param Pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 *  @param u4 Operando a ser empilhado.
 */
 void empilha_operando(Pilha_operandos**, u4);

   /**
 *  @fn u4 desempilha_operando(Pilha_operandos **pilha)
 *  @brief Desempilha operando da pilha com base em modelo last-in-first-out.
 *  @param Pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 *  @return Operando desempilhado com base em modelo last-in-first-out.
 */
 u4 desempilha_operando(Pilha_operandos**);

 /**
 *  @fn void init_pilha_frames(Pilha_frames **pilha)
 *  @brief Inicializa pilha de frames setando a pilha para NULL.
 *  @param Pilha_frames Ponteiro para ponteiro de pilha de frames.
 */
 void init_pilha_frames(Pilha_frames**);

 /**
 *  @fn void desaloca_pilha_frames(Pilha_frames **pilha)
 *  @brief Desaloca pilha de frames e seta cabecao da pilha para NULL.
 *  @param Pilha_frames Ponteiro para ponteiro de pilha de frames.
 */
 void desaloca_pilha_frames(Pilha_frames**);

  /**
 *  @fn void empilha_frame(Pilha_frames**, frame*)
 *  @brief Empilha frame na pilha com base em modelo last-in-first-out.
 *  @param Pilha_frames Ponteiro para ponteiro de pilha de frames.
 *  @param op Frame a ser empilhado.
 */
 void empilha_frame(Pilha_frames**, Frame*);

   /**
 *  @fn u4 desempilha_frame(Pilha_frames**)
 *  @brief Desempilha frame da pilha com base em modelo last-in-first-out. Nao libera memoria do frame.
 *  @param Pilha_frames Ponteiro para ponteiro de pilha de frames.
 *  @return Frame desempilhado com base em modelo last-in-first-out.
 */
 Frame* desempilha_frame(Pilha_frames**);

   /**
 *  @fn u4 desaloca_frame(Frame*)
 *  @brief Libera espaco de memoria do frame e o destroi.
 *  @param Frame* Ponteiro para frame a ser desalocado.
 */
 void desaloca_frame(Frame*);

#endif
