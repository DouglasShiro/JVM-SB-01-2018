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
	method_info *method_main, *method_init;

	method_main = acharMetodo("main", classFile);
	if (method_main != NULL)
	{
		method_init = acharMetodo("init", classFile);
		printf("ACHOU MAIN\n");
		if (method_init == NULL)
		{
			method_init = acharMetodo("clinit", classFile);
		}
		if (method_init != NULL)
		{
      Pilha_frames *pilha;
      init_pilha_frames(&pilha);
      inicializa(classFile, pilha);
			ready(method_init, classFile, &pilha);
      executarMetodo(method_init, classFile, pilha);
		}
		else
		{
			printf("ERRO! NAO ACHOU INIT.\n");
		}
	}
	else {
		printf("ERRO! NAO ACHOU MAIN.\n");
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
