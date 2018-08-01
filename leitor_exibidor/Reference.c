/**
* @file   Reference.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Reference.h.
**/

#include "Reference.h"

void getstatic(Frame* frame, Pilha_frames* pilha_frames, u1 indexbyte1, u1 indexbyte2) {
    char *type = NULL;
	char *name = NULL;
	char *class_name = NULL;
	u2 index = 0;
	u2 index_type = 0;
	u2 index_name = 0;
	u2 index_class = 0;
    u4 op_4 = 0;
	// u8 op_8 = 0;

	// ClassFile *class_file = NULL;
	// staticField *field = NULL;
    index = (u2) indexbyte2 << 8 | (u2) indexbyte1;
    index_class = frame->constant_pool[index - 1].fieldref_info.class_index - 1;
    index_class = frame->constant_pool[index_class].class_info.name_index - 1;
    index_type = frame->constant_pool[index - 1].fieldref_info.name_and_type_index - 1;
	index_type = frame->constant_pool[index_type].nameAndType_info.descriptor_index - 1;
    index_name = frame->constant_pool[index_type].nameAndType_info.name_index - 1;

	class_name = getConstantUTF8CP(frame->constant_pool, index_class);
    type = getConstantUTF8CP(frame->constant_pool, index_type);
    name = getConstantUTF8CP(frame->constant_pool, index_name);

    if (!strcmp(class_name, "java/lang/System")) {
	    op_4 = 0;
	    empilha_operando(&(frame->pilha_operandos), op_4);
	}

    free(type);
    free(name);

	return;
}

void putstatic(Frame * frame) {

}

void getfield(Frame * frame) {

}

void putfield(Frame * frame) {

}


void invokespecial(Frame* frame, Pilha_frames* pilha_frames, u1 indexbyte1, u1 indexbyte2) {

    return;
}

void invokevirtual(Frame* frame, Pilha_frames* pilha_frames, u1 indexbyte1, u1 indexbyte2) {
	int i = 0;
	float op_f = 0;
	char *class_name = NULL;
	char *method_name = NULL;
	char *method_desc = NULL;
	char *name = NULL;
	char *name_desc = NULL;
	u2 index = 0;
	u2 index_class = 0;
	u2 index_desc = 0;
	u2 index_method = 0;
	u8 op_8 = 0;
	u4 op_4 = 0;
	u4 *args = NULL;
	ClassFile *class_file = NULL;

	index = (u2) indexbyte2 << 8 | (u2) indexbyte1;

	index_class = frame->constant_pool[index -1].methodref_info.class_index;
	index_class = frame->constant_pool[index_class].class_info.name_index - 1;
	index_desc = frame->constant_pool[index - 1].methodref_info.name_and_type_index -1;
	index_method = frame->constant_pool[index_desc].nameAndType_info.name_index;
	index_desc = frame->constant_pool[index_desc].nameAndType_info.descriptor_index;

	class_name = getConstantUTF8CP(frame->constant_pool, index_class);
	method_name = getConstantUTF8CP(frame->constant_pool, index_method);
	method_desc = getConstantUTF8CP(frame->constant_pool, index_desc);

	if (!strcmp(class_name, "java/io/PrintStream") && (!strcmp(method_name, "print") || !strcmp(method_name, "println"))) {
		//print long
		if (strstr(method_desc, "J") != NULL) {
			op_8 = desempilha_operando_64(&(frame->pilha_operandos));
			int64_t value = op_8;
			printf("%ld", value);

		}//print double
		else if (strstr(method_desc, "D") != NULL) {
			op_8 = desempilha_operando_64(&(frame->pilha_operandos));
			double value;
			memcpy(&value,&op_8,sizeof(u8));
			printf("%f", value);

		}//print boolean
		else if (strstr(method_desc, "Z") != NULL) {
			if (desempilha_operando(&(frame->pilha_operandos)))
				printf("TRUE");
			else
				printf("FALSE");

		}
		else if (strstr(method_desc, "C") != NULL) {
			//print array
			if (strstr(method_desc, "[C") != NULL) {
				aType *arr = (void*)(long)desempilha_operando(&(frame->pilha_operandos));
				for (i = 0; i < arr->tamanho1; i++){
					printf("%c", arr->info.charType[i]);
				}
			}//print char
			else {
				printf("%c", desempilha_operando(&(frame->pilha_operandos)));
			}
		}//print inteiro
		else if (strstr(method_desc, "I") != NULL) {
			printf("%d", (int32_t)desempilha_operando(&(frame->pilha_operandos)));

		}//print float
		else if (strstr(method_desc, "F") != NULL) {
			op_4 = desempilha_operando(&(frame->pilha_operandos));
			memcpy(&op_f, &op_4, sizeof(u4));
			printf("%f", op_f);

		}//print string
		else if (strstr(method_desc, "Ljava/lang/String") != NULL) {
			op_4 = desempilha_operando(&(frame->pilha_operandos));
			if (op_4 != 0) {
				char *cpointer = getConstantUTF8CP(frame->class_file->constant_pool, (u2) op_4);
				printf("%s", cpointer);
			} else {
				printf("%s", (char *)op_4);
			}

		}//print object
		else if (strstr(method_desc, "Ljava/lang/Object") != NULL) {
			op_4 = desempilha_operando(&(frame->pilha_operandos));
			void *ppointer = (void*)(long)op_4;
			printf("%p",ppointer);
		} if (strstr(method_name, "println") != NULL) {
			printf("\n");
		}

	}
	free(method_name);
	free(method_desc);
	free(name);
	free(name_desc);
	free(args);
	return;
}

void invokestatic(Frame * frame) {

}

void invokeinterface(Frame * frame) {

}

void invokedynamic(Frame * frame) {

}

void new_(Frame * frame) {

}

void newarray(Frame * frame, u1 type) {

}

void anewarray(Frame * frame) {

}

void arraylength(Frame * frame) {

}

void athrow(Frame * frame) {

}

void checkcast(Frame * frame) {

}

void instanceof(Frame * frame) {

}

void monitorenter(Frame * frame) {

}

void monitorexit(Frame * frame) {

}
