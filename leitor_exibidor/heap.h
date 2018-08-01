/**
* @file heap.h
* @author Douglas
* @brief Definicao da estrutura da heap e dos métodos para acessá-los
*/

#include "classfile.h"

#ifndef HEAP_H
#define HEAP_H

typedef struct array_type {
	u1 tag;
	u4 tamanho;
	u4 tamanho1;
	union {
		u1 *booleanType;
        u1 *byteType;
        u2 *charType;
        u2 *shortType;
        u4 *refType;
        u4 *intType;
        u4 *floatType;
        u8 *longType;
        u8 *doubleType;
    } info;
} aType;

typedef struct array_list {
	aType *data;
	struct array_list *next;
} ArrayList;

typedef struct object_type {
	ClassFile *classFile;
	u2 fieldTypeLength;
	u8 *fieldType;
} Object;

typedef struct {
	char *ClassName;
	u2 fieldCount;
	u8 *value;
} staticField;

typedef struct object_list {
	Object *data;
	struct object_list *next;
} ObjectList;

typedef struct field_list {
	staticField *data;
	struct field_list *next;
} StaticFieldList;

typedef struct class_list {
	ClassFile *data;
	struct class_list *next;
} ClassList;

typedef struct heap {
	struct array_list *arrayList;
	struct object_list *objectList;
	struct field_list *fieldList;
	struct class_list *classList;
	struct pilha_frames *pilhaFrames;
} Heap;

/**
 *  @fn void initArrayList(ArrayList **array_list)
 *  @brief Inicializa lista de arrays carregados na heap.
 *  @param array_list Estrutura array_list que conterá a lista.
 */
void initArrayList(ArrayList **array_list);

 /**
  *  @fn void addArrayList(ArrayList **array_list, aType *data)
  *  @brief Insere um elemento na lista de arrays.
  *  @param array_list Estrutura array_list que conterá a lista.
  *  @param data Elemento a ser inserido.
  */
ArrayList* addArrayList(ArrayList **array_list, aType *data);

 /**
  *  @fn void freeArrayList(ArrayList **array_list)
  *  @brief Desaloca a lista de arrays.
  *  @param array_list Lista de arrays a ser desalocada.
  */
void freeArrayList(ArrayList **array_list);

 /**
  *  @fn void initObjectList(ObjectList **object_list)
  *  @brief Inicializa lista de objetos carregados na heap.
  *  @param object_list Estrutura object_list que conterá a lista.
  */
void initObjectList(ObjectList **object_list);

 /**
  *  @fn void addObjectList(ObjectList **object_list, Object *data)
  *  @brief Insere um elemento na lista de objetos.
  *  @param object_list Estrutura object_list que conterá a lista.
  *  @param data Elemento a ser inserido.
  */
void addObjectList(ObjectList **object_list, Object *data);

 /**
  *  @fn void freeObjectList(ObjectList **object_list)
  *  @brief Desaloca a lista de objetos.
  *  @param object_list Lista de objetos a ser desalocada.
  */
void freeObjectList(ObjectList **object_list);

 /**
  *  @fn void initClassList(ClassList **class_list)
  *  @brief Inicializa lista de classes carregados na heap.
  *  @param class_list Estrutura class_list que conterá a lista.
  */
void initClassList(ClassList **class_list);

 /**
  *  @fn ClassList addClassList(ClassList **class_list, ClassFile *data)
  *  @brief Insere um elemento na lista de classes.
  *  @param class_list Estrutura class_list que conterá a lista.
  *  @param data Elemento a ser inserido.
  *	 @return Lista atualizada com elemento inserido.
  */
ClassList* addClassList(ClassList **class_list, ClassFile *data);

 /**
  *  @fn void freeClassList(ClassList **class_list)
  *  @brief Desaloca a lista de classes.
  *  @param class_list Lista de classes a ser desalocada.
  */
void freeClassList(ClassList *class_list);

 /**
  *  @fn void initFieldList(FieldList **field_list)
  *  @brief Inicializa lista de fields carregados na heap.
  *  @param field_list Estrutura field_list que conterá a lista.
  */
void initFieldList(StaticFieldList *field_list);

 /**
  *  @fn void addFieldList(StaticFieldList **field_list, staticField *data)
  *  @brief Insere um elemento na lista de fields.
  *  @param field_list Estrutura field_list que conterá a lista.
  *  @param data Elemento a ser inserido.
  */
void addFieldList(StaticFieldList **field_list, staticField *data);

// staticFieldList *getfield(char *name, staticFieldList **field_list)

 /**
  *  @fn void freeFieldList(StaticFieldList **field_list)
  *  @brief Desaloca a lista de fields.
  *  @param field_list Lista de fields a ser desalocada.
  */
void freeFieldList(StaticFieldList *field_list);

 /**
  *  @fn u1 loadedClass(ClassList **class_list, char *className)
  *  @brief Verifica se uma classe estpa carregada em uma lista de classes.
  *  @param class_list Estrutura class_list que conterá a lista.
  *  @param className Nome da classe a ser buscada na lista de classes.
  *  @return u1 lido, 1 se carregada ou 0 caso contrário.
  */
u1 loadedClass(ClassList **class_list, char *className);

 /**
  *  @fn ClassFile getClass(ClassList **class_list, int index)
  *  @brief Recupera classe buscando por índice na lista de classes.
  *  @param class_list Estrutura class_list que conterá a lista.
  *  @param index Índice da classe a ser buscada na lista de classes.
  *  @return Classe com o índice buscado.
  */
ClassFile *getClass(ClassList **class_list, int index);

 /**
  *  @fn ClassFile getClassByName(ClassList **class_list, char *className)
  *  @brief Recupera classe buscando por nome na lista de classes.
  *  @param class_list Estrutura class_list que conterá a lista.
  *  @param className Nome da classe a ser buscada na lista de classes.
  *  @return Classe com o nome buscado.
  */
ClassFile *getClassByName(ClassList **class_list, char *className);

 /**
  *  @fn void initHeap()
  *  @brief Inicializa heap do programa.
  *  @return Estrutura Heap alocada.
  */
Heap* initHeap();

 /**
  *  @fn void freeHeap(Heap **heap)
  *  @brief Desaloca a heap.
  *  @param heap Heap a ser desalocada.
  */
void freeHeap(Heap *heap);

#endif // HEAP_H
