/**
*@file Method_area.h
*@author Gustavo Costa 14/0142568
*@author Andrei
*@brief Biblioteca com funcoes implementadas para área de métodos
*/

#include "classfile.h"
#include "pilhaFrames.h"
#include "string.h"
#include "exibidor.h"
#include "Conjunto_de_Instrucoes.h"

#ifndef METHOD_AREA_H
#define METHOD_AREA_H

/**
*@fn int inicializa(ClassFile *classe, Pilha_frames *pilha)
*@brief Execucao dos metodos que iniciam a classe
*@param Classe carregada
*@param Pilha carregada
*/
int inicializa(ClassFile *classe, Pilha_frames *pilha);

/**
*@fn method_info* acessoMethod(ClassFile *classe, char *metodo)
*@brief Funcao que avalia os metodos e retorna o metodo main da classe
*@param Classe carregada
*@param Nome do metodo desejado
*/

method_info* acessoMethod(char *metodo, ClassFile *classe);

/**
*@fn void ready(method_info *metodo, ClassFile *classe, Pilha_frames *pilha)
*@brief Funcao de estado antes da execucao do metodo
*@param Metodo a ser executado posteriormente
*@param Classe carregada "classe"
*@param Pilha_frames que contem e armazena o frame
*/

void ready(method_info *method, ClassFile *classe, Pilha_frames **pilha);

/**
*@fn int executarMetodo(method_info *metodo, ClassFile *classe, Pilha_frames *pilha)
*@brief Funcao de execucao do metodo
*@param metodo carregado
*@ param classe carregada
*@ indicacao da pilha de frames
*/

int executarMetodo(method_info *metodo, ClassFile *classe, Pilha_frames *pilha);

/**
*@fn executarInstrucoes (method_info *metodo, frame *frame)
*@brief funcao que executa os comandos bytecode
*@param Metodo carregado
*@param Frame carregado
*/
int executarInstrucoes (method_info *metodo, Frame *frame, Pilha_frames *pilha);

void inicializa_Conj_Instrucoes();

// constants
// void decodebipush(Frame* frame);
// void decodesipush(Frame* frame);
// void decodeldc(Frame* frame);
// void decodeldc_w(Frame* frame);
// void decodeldc2_w(Frame* frame);
// Loads
void decodeiload(Frame* frame);
void decodelload(Frame* frame);
void decodefload(Frame* frame);
void decodedload(Frame* frame);
void decodeaload(Frame* frame);
// stores
void decodeistore(Frame* frame);
void decodelstore(Frame* frame);
void decodefstore(Frame* frame);
void decodedstore(Frame* frame);
void decodeastore(Frame* frame);
// logic arit
void decodeiinc(Frame* frame);
// comparisions
void decodeifeq(Frame* frame);
void decodeifne(Frame* frame);
void decodeiflt(Frame* frame);
void decodeifge(Frame* frame);
void decodeifgt(Frame* frame);
void decodeifle(Frame* frame);
void decodeif_icmpeq(Frame* frame);
void decodeif_icmpne(Frame* frame);
void decodeif_icmplt(Frame* frame);
void decodeif_icmpge(Frame* frame);
void decodeif_icmpgt(Frame* frame);
void decodeif_icmple(Frame* frame);
void decodeif_acmpeq(Frame* frame);
void decodeif_acmpne(Frame* frame);

//conotrol
// void decodegoto(Frame* frame);
// void decodejsr(Frame* frame);
// void decodejsr_w(Frame* frame);
// references
void decodegetstatic(Frame* frame);
// void decodegetfield(Frame* frame);
// void decodeputfield(Frame* frame);
void decodeinvokevirtual(Frame* frame);
void decodeinvokeSpecial(Frame* frame);
// void decodeinvokestatic(Frame* frame);
// void decodeinvokeinterface(Frame* frame);
// void decodenew_(Frame* frame);
void decodenewarray(Frame* frame);
// void decodecheckcast(Frame* frame);
// void decodeinstanceof(Frame* frame);
// extended
// void decodewide(Frame* frame);
// void decodemultianewarray(Frame* frame);
// void decodeifnull(Frame* frame);
// void decodeifnonull(Frame* frame);
// void decodegoto_w(Frame* frame);
// void decodejsr_w(Frame* frame);

#endif
