#include <stdio.h>
#include <stdlib.h>
#include "reader.h"
#include "exibidor.h"
#include "classfile.h"
#include "Method_area.h"
#include "pilhaFrames.h"

#define IMPRIMIR "imprimir"
#define EXECUTAR "executar"
void executar(ClassFile *);
method_info* acharMetodo(char *, ClassFile *);

int main(int argc, char* argv[]) {

	char* nome_arq;
    ClassFile *fp_class_info;

	if (argc < 2) {
		printf("Parametros insuficientes\n");
		return 0;
	}

	nome_arq = argv[1];

	fp_class_info = classFileRead(nome_arq);

	if (fp_class_info == NULL) {
		printf("Falha ao ler arquivo: %s\n", nome_arq);
		return 0;
	}

	if (!argv[2]) {
		printf("\n\n--------------------------------------------------------------------\n");
		printf("imprimir .class\n");
		classFileExib(fp_class_info);
		printf("\n\n--------------------------------------------------------------------\n");
		printf("executar .class\n");
		executar(fp_class_info);
		return 0;
	}

	if (!strcmp(argv[2], IMPRIMIR)) {
		classFileExib(fp_class_info);
	} else if (!strcmp(argv[2], EXECUTAR)) {
		executar(fp_class_info);
	} else {
		printf("Opcao invalida!\n");
	}
    return 0;
}

void executar(ClassFile* classFile) {
	method_info *method_main, *method_init;
	Pilha_frames *pilha;

	method_main = acharMetodo("main", classFile);
	if (method_main == NULL) {
		printf("ERRO! NAO ACHOU MAIN.\n");
		return;
	}
	inicializa_Conj_Instrucoes();

	// method_init = acharMetodo("<init>", classFile);
	// if (!try_init(method_init == NULL) {
	// 	printf("ERRO! NAO ACHOU INIT.\n");
	// 	return;
	// }

	init_pilha_frames(&pilha);
	ready(method_main, classFile, &pilha);
	executarMetodo(method_main, classFile, pilha);
}

method_info* acharMetodo(char *nome, ClassFile *classFile) {
    for(int i = 0; i < classFile->methods_count; i++) {
        char *nomeTeste;
        int index_nome = classFile->methods[i].name_index;
        nomeTeste = getConstantUTF8CP(classFile->constant_pool, index_nome);
        // printf("Nome: %s, index: %d\n", nomeTeste, index_nome);
        if(nomeTeste != NULL && !strcmp(nomeTeste, nome)) {
            return &classFile->methods[i];
        }
    }
    return NULL;
}
