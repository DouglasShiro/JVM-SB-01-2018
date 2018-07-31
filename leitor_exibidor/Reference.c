/**
* @file   Reference.c
* @author Douglas Yokoyama
* @brief  Arquivo com os códigos das funções declaradas no arquivo Reference.h.
**/

#include "Reference.h"

void invokespecial(Frame* frame, Pilha_frames* pilha_frames, u1 index_0, u1 index_1) {
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
    // u4 numparam = 0, *argumentos = NULL;
	// ClassFile *class_file = NULL;
	//
    // index = (u2) index_0 << 8 | (u2) index_1;
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
	// argumentos = (u4 *)malloc(sizeof(u4) * (numparam + 1));
	//
	// for (i = numparam; i >= 0; i--)
    // {
    //     argumentos[i] = desempilha_operando(&(frame->pilhaDeOperandos));
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
    //         empilha_operando_64(&frame->pilhaDeOperandos, &zerou8);
    //     } else if(bytes[length-1] != 'V') {
    //         empilha_operando(&frame->pilhaDeOperandos, &zerou4);
    //     }
    // }
    // else
    // {
    //     prepara_metodo(&class_file->methods[i], class_file,&pilhadeframes, &heap);
    //     Frame *frame1 = desempilha_frame(&pilhadeframes);
    //     for (int j = numparam; j >= 0; j--)
    //     {
    //         frame1->VetorVariaveisLocais[j] = argumentos[j];
    //     }
    //     pilhadeframes = empilha_frame(pilhadeframes, frame1);
    //     executa_metodo(&class_file->methods[i], class_file, pilhadeframes);
    // }
    // free(argumentos);
    return;
}
