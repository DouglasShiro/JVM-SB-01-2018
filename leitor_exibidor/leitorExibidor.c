#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "exibidor.h"
#include "classfile.h"
#include "Method_area.h"
#include "pilhaFrames.h"

void executar(ClassFile *);
method_info* acharMetodo(char *, ClassFile *);

int main(int argc, char* argv[]) {

    ClassFile *fp_class_info;

    fp_class_info = classFileRead("double_aritmetica.class");

    classFileExib(fp_class_info);


    executar(fp_class_info);


    return 0;
}

void executar(ClassFile* classFile) {
	method_info *method_main;

	method_main = acharMetodo("main", classFile);
	if (method_main != NULL){

		printf("ACHOU MAIN\n");
		Pilha_frames *pilha;

		if (inicializa(classFile, pilha)==1){
			printf("ACHOU INIT\n");
			init_pilha_frames(&pilha);
			ready(method_main, classFile, &pilha);
			executarMetodo(method_main, classFile, pilha);
		}

		else{
			printf("ERRO: NAO ACHOU INIT.\n");
		}
	}
	else {
		printf("ERRO: NAO ACHOU MAIN.\n");
	}

}

method_info* acharMetodo(char *nome, ClassFile *classFile) {
    for(int i = 0; i < classFile->methods_count; i++) {
        char *nomeTeste;
        int index_nome = classFile->methods[i].name_index;
        nomeTeste = getConstantUTF8CP(classFile->constant_pool, index_nome);
        printf("Nome: %s, index: %d\n", nomeTeste, index_nome);
        if(nomeTeste != NULL && !strcmp(nomeTeste, nome)) {
            return &classFile->methods[i];
        }
    }
    return NULL;
}
