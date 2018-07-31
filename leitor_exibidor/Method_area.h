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
// void getbipush(Frame* frame);
// void getsipush(Frame* frame);
// void getldc(Frame* frame);
// void getldc_w(Frame* frame);
// void getldc2_w(Frame* frame);
// logic arit
// void getiinc(Frame* frame);
//conotrol
// void getgoto(Frame* frame);
// void getjsr(Frame* frame);
// void getjsr_w(Frame* frame);
// references
// void getstatic(Frame* frame);
// void getfield(Frame* frame);
// void getputfield(Frame* frame);
// void getinvokevirtual(Frame* frame);
void getinvokeSpecial(Frame* frame);
// void getinvokestatic(Frame* frame);
// void getinvokeinterface(Frame* frame);
// void getnew_(Frame* frame);
// void getnewarray(Frame* frame);
// void getcheckcast(Frame* frame);
// void getinstanceof(Frame* frame);
// extended
// void getwide(Frame* frame);
// void getmultianewarray(Frame* frame);
// void getifnull(Frame* frame);
// void getifnonull(Frame* frame);
// void getgoto_w(Frame* frame);
// void getjsr_w(Frame* frame);

#endif
