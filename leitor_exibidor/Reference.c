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
    // class_file = RecuperaClassePorNome(class_name, &listadeclasses);
    // if(!class_file) {
    //     if(!strcmp(class_name, "java/lang/System")) {
    //         if (type[0] == 'J' || type[0] == 'D')
    //         {
    //             op_8 = 0;
    //             empilha_operando_64(&(frame->pilha_operandos), &op_8);
    //         }
    //         else
    //         {
    //             op_4 = 0;
    //             empilha_operando(&(frame->pilha_operandos), &op_4);
    //         }
    //         free(type);
    //         free(name);
    //         return;
    //     }
    //     else {
    //         exit(-1);
    //     }
    // }
	// field = getfield(class_name, &frame->class_file);
    // if(!field) {
    //     if (type[0] == 'J' || type[0] == 'D')
    //     {
    //         op_8 = 0;
    //         empilha_operando_64(&(frame->pilha_operandos), &op_8);
    //     }
    //     else
    //     {
    //         op_4 = 0;
    //         empilha_operando(&(frame->pilha_operandos), &op_4);
    //     }
    //     free(type);
    //     free(name);
	// }
    free(type);
    free(name);

	return;
}

void invokespecial(Frame* frame, Pilha_frames* pilha_frames, u1 indexbyte1, u1 indexbyte2) {
	// int i = 0;
	// char *class_name = NULL;
	// char *method_name = NULL;
	// char *name;
	// char *desc_name;
	// char *desc_method;
	// u1 *bytes = NULL;
	// u2 index = 0;
	// u2 index_class = 0;
	// u2 index_desc = 0;
	// u2 index_method = 0;
	// u2 length = 0;
    // u4 numparam = 0, *args = NULL;
	// ClassFile *class_file = NULL;
	//
    // index = (u2) indexbyte1 << 8 | (u2) indexbyte2;
	//
    // index_class = frame->constant_pool[index - 1].info.methodref_info.class_index - 1;
    // index_class = frame->constant_pool[index_class].info.class_info.name_index - 1;
	//
    // class_name = getConstantUTF8CP(frame->constant_pool, index_class);
    // class_file = RecuperaClassePorNome(&listadeclasses, class_name);
	//
    // if (class_file == NULL) {
    //     char *file_name;
    //     class_file = (ClassFile *)malloc(sizeof(ClassFile));
    //     file_name = (char *)malloc(sizeof(char) * (strlen(class_name) + 10));
    //     strcpy(file_name, class_name);
    //     strcat(file_name, ".class");
    //     class_file = classFileRead(file_name);
    //     listadeclasses = InsereListaDeClasses(&listadeclasses, class_file);
    //     frame->heap->listaDeClasses = listadeclasses;
    // }
    // index_desc = frame->constant_pool[index - 1].info.Methodref_info.name_and_type_index - 1;
    // index_method = frame->constant_pool[index_desc].info.NameAndType.name_index - 1;
    // index_desc = frame->constant_pool[index_desc].info.NameAndType.descriptor_index - 1;
    // method_name = getConstantUTF8CP(index_method, frame->constant_pool);
    // desc_method = getConstantUTF8CP(index_desc, frame->constant_pool);
    // bytes = frame->constant_pool[index_desc].info.Utf8.bytes;
    // length = frame->constant_pool[index_desc].info.Utf8.length;
	//
    // for (i = 0; i < length && bytes[i] != ')'; i++)
    // {
	// 	if(bytes[i] == 'L')
	// 	{
	// 		while(bytes[i] != ';')
	// 		{
	// 			i++;
	// 		}
	// 		numparam++;
	// 	} else if((bytes[i] == 'B')||(bytes[i] == 'C')||(bytes[i] == 'F')|| (bytes[i] == 'I')||(bytes[i] == 'S')||(bytes[i] == 'Z') )
	// 	{
	// 		numparam++;
	// 	} else if((bytes[i] == 'D')||(bytes[i] == 'J'))
	// 	{
	// 		numparam+=2;
	// 	}
	// }
	//
	// args = (u4 *)malloc(sizeof(u4) * (numparam + 1));
	//
	// for (i = numparam; i >= 0; i--)
    // {
    //     args[i] = desempilha_operando(&(frame->pilha_operandos));
    // }
	//
    // for(i = 0; i < class_file->methods_count; i++) {
    //     index = class_file->methods[i].name_index - 1;
    //     name = getConstantUTF8CP(index, class_file->constant_pool);
    //     u2 index1 = class_file->methods[i].descriptor_index - 1;
    //     desc_name = getConstantUTF8CP(index1, class_file->constant_pool);
    //     if(!strcmp(method_name, name) && !strcmp(desc_method, desc_name))
    //         break;
    // }
	//
    // if (class_file->methods[i].access_flags & ACC_NATIVE)
    // {
    //     u4 zerou4 = 0;
    //     u8 zerou8 = 0;
    //     bytes = class_file->constant_pool[class_file->methods[i].descriptor_index - 1].info.Utf8.bytes;
    //     length = class_file->constant_pool[class_file->methods[i].descriptor_index - 1].info.Utf8.length;
    //     if(bytes[length - 1] == 'D' || bytes[length - 1] == 'J') {
    //         empilha_operando_64(&frame->pilha_operandos, &zerou8);
    //     } else if(bytes[length-1] != 'V') {
    //         empilha_operando(&frame->pilha_operandos, &zerou4);
    //     }
    // }
    // else
    // {
    //     prepara_metodo(&class_file->methods[i], class_file,&pilhadeframes, &heap);
    //     Frame *frame1 = desempilha_frame(&pilhadeframes);
    //     for (int j = numparam; j >= 0; j--)
    //     {
    //         frame1->VetorVariaveisLocais[j] = args[j];
    //     }
    //     pilhadeframes = empilha_frame(pilhadeframes, frame1);
    //     executa_metodo(&class_file->methods[i], class_file, pilhadeframes);
    // }
    // free(args);
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

	index = (u2) indexbyte1 << 8 | (u2) indexbyte2;

	index_class = frame->constant_pool[index - 1].methodref_info.class_index - 1;
	index_class = frame->constant_pool[index_class].class_info.name_index - 1;
	index_desc = frame->constant_pool[index - 1].methodref_info.name_and_type_index - 1;
	index_desc = frame->constant_pool[index_desc].nameAndType_info.descriptor_index - 1;
	index_method = frame->constant_pool[index_desc].nameAndType_info.name_index - 1;

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
				char *cpointer = getConstantUTF8CP(frame->class_file->constant_pool, (u2) op_4 - 1);
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
	} else {
		u4 numparam = 0;
		printf("aqui erou de novo\n");
		// class_file = RecuperaClassePorNome(class_name, &listadeclasses);
		// if (class_file == NULL)
		// {
		// 	char *nomearquivo;
		// 	class_file = (ClassFile *)malloc(sizeof(ClassFile));
		// 	nomearquivo = (char *)malloc(sizeof(char) * (strlen(class_name) + 7));
		// 	strcpy(nomearquivo, class_name);
		// 	strcat(nomearquivo, ".class");
		// 	carrega_classe(nomearquivo, class_file);
		// 	listadeclasses = InsereListaDeClasses(&listadeclasses, class_file);
		// 	frame->heap->listaDeClasses = listadeclasses;
		// }

		u1 *bytes = frame->constant_pool[index_desc].utf8_info.bytes;
		u2 length = frame->constant_pool[index_desc].utf8_info.length;

		for (i = 0; i < length && bytes[i] != ')'; i++) {
			if(bytes[i] == 'L') {
				while(bytes[i] != ';') {
					i++;
				}
				numparam++;
			}
			else if((bytes[i] == 'B')||(bytes[i] == 'C')||(bytes[i] == 'F')|| (bytes[i] == 'I')||(bytes[i] == 'S')||(bytes[i] == 'Z') ) {
				numparam++;
			}
			else if((bytes[i] == 'D')||(bytes[i] == 'J')) {
				numparam+=2;
			}
		}

		args = (u4 *)malloc(sizeof(u4) * (numparam + 1));

		for (i = numparam; i >= 0; i--) {
			args[i] = desempilha_operando(&(frame->pilha_operandos));
		}

		method_name = getConstantUTF8CP(frame->constant_pool, index_method);

		for(i = 0; i < class_file->methods_count; i++) {
			index = class_file->methods[i].name_index - 1;
			name = getConstantUTF8CP(class_file->constant_pool, index);
			u2 index1 = class_file->methods[i].descriptor_index - 1;
			name_desc = getConstantUTF8CP(class_file->constant_pool, index1);
			if(!strcmp(method_name, name) && !strcmp(method_desc, name_desc))
				break;
		}

		if (i != class_file->methods_count) {
			if (class_file->methods[i].access_flags & ACC_NATIVE) {
				u8 zero64 = 0;
				u4 zero32 = 0;

				bytes = class_file->constant_pool[class_file->methods[i].descriptor_index - 1].utf8_info.bytes;
				length = class_file->constant_pool[class_file->methods[i].descriptor_index - 1].utf8_info.length;
				if(bytes[length - 1] == 'D' || bytes[length - 1] == 'J') {
					empilha_operando_64(&frame->pilha_operandos, zero64);
				} else if(bytes[length-1] != 'V') {
					empilha_operando_64(&frame->pilha_operandos, zero32);
				}
			} else {
				printf("aqui erou\n");
				// prepara_metodo(&class_file->methods[i], class_file,&pilhadeframes, &heap);
				// Frame *frame1 = desempilha_frame(&pilhadeframes);
				// for (int j = numparam; j >= 0; j--)
				// {
				// 	frame1->VetorVariaveisLocais[j] = args[j];
				// }
				// pilhadeframes = empilha_frame(pilhadeframes, frame1);
				// executa_metodo(&class_file->methods[i], class_file, pilhadeframes);
			}
		} else {
			printf("metodo nao encontrado");
		}
	}
	free(method_name);
	free(method_desc);
	free(name);
	free(name_desc);
	free(args);
	return;
}
