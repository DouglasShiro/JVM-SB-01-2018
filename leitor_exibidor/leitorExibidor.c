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

    printf("Indicar qual arquivo deseja ler e executar (*.class):\n");

    char *nome_arq = argv[1];

    fp_class_info = classFileRead(nome_arq);

    classFileExib(fp_class_info);


    executar(fp_class_info);


    return 0;
}

void executar(ClassFile* classFile) {
	method_info *method_main;

	method_main = acharMetodo("main", classFile);
<<<<<<< HEAD
<<<<<<< HEAD
	if (method_main != NULL){
<<<<<<< HEAD
		
		printf("ACHOU MAIN\n");
		Pilha_frames *pilha;
		
		if (inicializa(classFile, pilha)){
			printf("ACHOU INIT\n");
			init_pilha_frames(&pilha);
			ready(method_init, classFile, &pilha);
			executarMetodo(method_init, classFile, pilha);
		}
		
		else{

		printf("ACHOU MAIN\n");
		Pilha_frames *pilha;
=======

		printf("ACHOU MAIN\n");
		Pilha_frames *pilha;
>>>>>>> 94d715e3cdddbc1b6ac683eccba20f99aa0cf6e8
		method_info *method_init;
		method_init = acharMetodo("<init>", classFile);
		if (method_init == NULL)
=======
	if (method_main != NULL)
	{
		method_init = acharMetodo("init", classFile);
		printf("ACHOU MAIN\n");
		if (method_init != NULL)
>>>>>>> parent of 45a7f04... Andrei
=======
	if (method_main != NULL){

		printf("ACHOU MAIN\n");
		Pilha_frames *pilha;
		method_info *method_init;
		method_init = acharMetodo("<init>", classFile);
		if (method_init == NULL)
>>>>>>> 94d715e3cdddbc1b6ac683eccba20f99aa0cf6e8
		{
			method_init = acharMetodo("<clinit>", classFile);
		}
		if (method_init != NULL)
		{
			printf("ACHOU INIT\n");
			init_pilha_frames(&pilha);
			ready(method_init, classFile, &pilha);
			executarMetodo(method_init, classFile, pilha);
		}
		else
		{
<<<<<<< HEAD
<<<<<<< HEAD
			printf("ERRO: NAO ACHOU INIT.\n");
=======
			printf("ERRO! NAO ACHOU INIT.\n");
>>>>>>> parent of 45a7f04... Andrei
=======
			printf("ERRO: NAO ACHOU INIT.\n");
>>>>>>> 94d715e3cdddbc1b6ac683eccba20f99aa0cf6e8
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
