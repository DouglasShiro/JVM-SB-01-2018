/**
 *  @file pilhaFrames.c
 *  @author Adarley Luiz Grando Filho (11/0007344)
 *  @brief Codigo dos metodos declarados em pilhaFrames.h.
 */

#include "pilhaFrames.h"

void init_pilha_operandos(Pilha_operandos **pilha) {
    *pilha = NULL;
}

void desaloca_pilha_operandos(Pilha_operandos **pilha) {
    Pilha_operandos *op;

    while (*pilha != NULL) {
        op = *pilha;
        *pilha = op->prox;
        free(op);
    }
}

void empilha_operando(Pilha_operandos **pilha, u4 op) {
    Pilha_operandos *operando;

    operando = (Pilha_operandos*)malloc(sizeof(Pilha_operandos));
    
    operando->op = op;
    operando->prox = *pilha;

    *pilha = operando;
}

u4 desempilha_operando(Pilha_operandos **pilha) {
    u4 op;
    Pilha_operandos *elemento;

    elemento = *pilha;

    op = elemento->op;
    *pilha = elemento->prox;

    free(elemento);

    return op;
}

void init_pilha_frames(Pilha_frames** pilha) {
    *pilha = NULL;
}

void desaloca_pilha_frames(Pilha_frames** pilha) {
    Pilha_frames *elemento;

    while(*pilha != NULL) {
        elemento = *pilha;
        *pilha = elemento->prox;
        free(elemento);
    }
}

void empilha_frame(Pilha_frames** pilha, Frame* frame) {
    Pilha_frames *novoElemento;

    novoElemento = (Pilha_frames*)malloc(sizeof(Pilha_frames));

    novoElemento->frame = frame;
    novoElemento->prox = *pilha;

    *pilha = novoElemento;
}

Frame* desempilha_frame(Pilha_frames** pilha) {
    Frame *frame;
    Pilha_frames *elemento;

    elemento = *pilha;
    frame = elemento->frame;
    *pilha = elemento->prox;

    return frame;
}

void desaloca_frame(Frame* frame) {
    desaloca_pilha_operandos(&frame->pilha_operandos);
    if (frame->tamanho_variaveis_locais > 0) {
        free(frame->variaveis_locais);
    }
    free(frame);
}