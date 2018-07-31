/**
 *  @file pilhaFrames.c
 *  @author Adarley Luiz Grando Filho (11/0007344)
 *  @brief Codigo dos metodos declarados em pilhaFrames.h.
 */

#include "pilhaFrames.h"

Frame* init_frame(method_info* method, cp_info* constant_pool) {
    Frame *frame;

    frame = (Frame*)malloc(sizeof(Frame));

    frame->pc = 0;

    frame->tamanho_variaveis_locais = method->attributes->code.max_locals;
    frame->variaveis_locais = (u4*)malloc(frame->tamanho_variaveis_locais*sizeof(u4));
	frame->pilha_operandos = NULL;
	frame->constant_pool = constant_pool;

    for (int i = 0; i < method->attributes_count; i++) {
        if (method->attributes[i].tag == ATTRIBUTE_Code) {
            frame->codigo = &(method->attributes[i]);
            break;
        }
    }

    return frame;
}

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

void empilha_operando_64(Pilha_operandos **pilha, u8 op) {
	u4 op_4;
	u8 op_8;
	op_8 = op;

	op_4 = (u4)(op_8 & 0x00000000FFFFFFFF);
	empilha_operando(pilha, op_4);
	op_4 = (u4)(op_8 >> 32);
	empilha_operando(pilha ,op_4);

	return;
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

u8 desempilha_operando_64(Pilha_operandos **pilha) {
    u4 op_4;
    u8 op_8;

    op_4 = desempilha_operando(pilha);
	op_8 = op_4;
	op_8 = (op_8 << 32);
    op_4 = desempilha_operando(pilha);
    op_8 += (u8) (op_4 & 0x00000000FFFFFFFF);

    return op_8;
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
