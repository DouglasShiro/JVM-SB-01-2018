/**
*@file Method_area.case
*@author Gustavo Costa 14/0142568
*@author Andrei
*@brief Implementação da área de métodos da JVM.
*/

#include "Method_area.h"

int inicializa(ClassFile *classe, Pilha_frames *pilha) {
  int result = 0;
  for(int i = 0; i<classe->methods_count; i++) {
    char *nome;
    int local_nome = classe->constant_pool[i].utf8_info; //Ver esse indicacao de nome!!!
    nome = getConstantUTF8CP(local_nome, classe);
    if (!strcmp("<clinit>", nome) || !strcmp("<init>", nome)) { //verifica se e comeco do metodo
      method_info *init = &classe->methods[i];

    }
  }
}

method_info* acessoMethod(ClassFile *classe, char *metodo) {

  for (int i = 0; i < classe->methods_count; i++) {
    int local_nome = classe->constant_pool[i].utf8_info; //Ver esse indicacao de nome!!!
    u1 *nome;
    nome  = (u1*) getConstantUTF8CP(local_nome, classe);
    if(!strcmp(metodo, (char *) nome)){
      return &classe->methods[i];
    }
  }
  return NULL;
}

void ready(method_info *method, ClassFile *classe, Pilha_frames **pilha){
  for(int i = 0; i<method->attributes_count; i++) {
    if (method->attributes[i].tag == ATTRIBUTE_Code) {
      if (method->attributes_count > 0) {
        Frame *frame = init_frame(*method, classe->*constant_pool); //Ver isso!!!
        *pilha = empilha_frame(**pilha, *frame);
        return;
      }
      else{
        method->attributes_count++;
        method->attributes = (attribute *) malloc(sizeof(attribute_info));
        method->attributes[0].Code_attribute.code_length = 0;
        Frame *frame = init_frame(*method, classe->*constant_pool);
        *pilha = empilha_frame(**pilha, *frame);
        return;
      }
    }
  }
  printf("Erro ao verificar Attribute code.\n");
  return;
}
