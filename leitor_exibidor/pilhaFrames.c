/**
 *  @file pilhaFrames.c
 *  @author Adarley Luiz Grando Filho (11/0007344)
 *  @brief Codigo dos metodos declarados em pilhaFrames.h.
 */

#include "pilhaFrames.h"

void init_pilha_operandos(pilha_operandos **pilha) {
    *pilha = NULL;
}

void desaloca_pilha_operandos(pilha_operandos **pilha) {
    pilha_operandos *op;

    while (*pilha != NULL) {
        op = *pilha;
        *pilha = op->prox;
        free(op);
    }
}

void empilha_operando(pilha_operandos **pilha, u4 op) {
    pilha_operandos *operando;

    operando = (pilha_operandos*)malloc(sizeof(pilha_operandos));
    
    operando->op = op;
    operando->prox = *pilha;

    *pilha = operando;
}

u4 desempilha_operando(pilha_operandos **pilha) {
    u4 op;
    pilha_operandos *elemento;

    elemento = *pilha;

    op = elemento->op;
    *pilha = elemento->prox;

    free(elemento);

    return op;
}
