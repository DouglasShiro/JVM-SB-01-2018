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
} pilha_operandos;

/**
 *  @fn void init_pilha_operandos(pilha_operandos **pilha)
 *  @brief Inicializa pilha de operandos setando a pilha para NULL.
 *  @param pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 */
 void init_pilha_operandos(pilha_operandos**);

 /**
 *  @fn void desaloca_pilha_operandos(pilha_operandos **pilha)
 *  @brief Desaloca pilha de operandos e seta cabecao da pilha para NULL.
 *  @param pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 */
 void desaloca_pilha_operandos(pilha_operandos**);

  /**
 *  @fn void empilha_operando(pilha_operandos **pilha, u4 op)
 *  @brief Empilha operando na pilha com base em modelo last-in-first-out.
 *  @param pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 *  @param op Operando a ser empilhado.
 */
 void empilha_operando(pilha_operandos**, u4);

   /**
 *  @fn u4 desempilha_operando(pilha_operandos **pilha)
 *  @brief Desempilha operando da pilha com base em modelo last-in-first-out.
 *  @param pilha_operandos Ponteiro para ponteiro de pilha de operandos.
 *  @param op Operando a ser empilhado.
 *  @return Operando desempilhado com base em modelo last-in-first-out.
 */
 u4 desempilha_operando(pilha_operandos**);

#endif
