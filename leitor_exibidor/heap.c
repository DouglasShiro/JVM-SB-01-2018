/**
* @file heap.h
* @author Douglas
* @brief Implementação da estrutura da heap e dos métodos para acesso da heap
*/

#include "heap.h"

/* void initArrayList(ArrayList **array_list) {} */

/* void addArrayList(ArrayList **array_list, aType *data) {} */

/* void freeArrayList(ArrayList **array_list) {} */

/* void initObjectList(ObjectList **object_list) {} */

/* void addObjectList(ObjectList **object_list, Object *data) {} */

/* void freeObjectList(ObjectList **object_list) {} */

/* void initClassList(ClassList **class_list) {} */

ClassList* addClassList(ClassList **class_list, ClassFile *data) {
	ClassList* class_list_new;
	class_list_new = (ClassList*)malloc(sizeof(ClassList));

	class_list_new->data = data;

	if (*class_list == NULL)
		class_list_new->next = NULL;
	else
		class_list_new->next = *class_list;

	return class_list_new;
}

void freeClassList(ClassList *class_list) {
	ClassList *first = class_list;

	while(first != NULL) {
		ClassList* next = first->next;
		free(first->data);
		first = next;
	}
}

/* void initFieldList(StaticFieldList *field_list) {} */

void addFieldList(StaticFieldList **field_list, staticField *data) {

}

void freeFieldList(StaticFieldList *field_list) {

}

/* u1 loadedClass(ClassList **class_list, char *className) {} */

ClassFile *getClass(ClassList **class_list, int index) {

}

ClassFile *getClassByName(ClassList **class_list, char *className) {

}

Heap* initHeap() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));

	heap->array_list = NULL;
	heap->object_list = NULL;
	heap->field_list = NULL;
	heap->class_list = NULL;
	hepa->pilha_frames = NULL;

	return heap;
}

void freeHeap(Heap *heap) {
	freeClassList(heap->class_list);
	freeFieldsList(heap->field_list);
	free(heap);
}
