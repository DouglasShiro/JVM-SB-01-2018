/**
* @file heap.h
* @author Douglas
* @brief Implementação da estrutura da heap e dos métodos para acesso da heap
*/

#include "heap.h"

/* void initArrayList(ArrayList **array_list) {} */

// ArrayList* addArrayList(ArrayList **array_list, aType *data) {
// 	ArrayList* array_list_new;
// 	array_list_new = (ArrayList*)malloc(sizeof(ArrayList));
//
// 	array_list_new->data = data;
//
// 	if (*array_list == NULL)
// 		array_list_new->next = NULL;
// 	else
// 		array_list_new->next = *array_list;
//
// 	return class_list_new;
// }

/* void freeArrayList(ArrayList **array_list) {

} */

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
	StaticFieldList *field_list_new;
	field_list_new = (StaticFieldList*)malloc(sizeof(StaticFieldList));

	field_list_new->data = data;

	if(*field_list == NULL)
		field_list_new->next = NULL;
	else
		field_list_new->next = *field_list;

	*field_list = field_list_new;
}

void freeFieldList(StaticFieldList *field_list) {
	StaticFieldList* first = field_list;
	while(first != NULL) {
		StaticFieldList* next = first->next;
		free(first->data);
		first = next;
	}
}

/* u1 loadedClass(ClassList **class_list, char *className32) {} */

ClassFile *getClass(ClassList **class_list, int index) {

}

ClassFile *getClassByName(ClassList **class_list, char *className) {

}

Heap* initHeap() {
	Heap* heap = (Heap*)malloc(sizeof(Heap));

	heap->arrayList = NULL;
	heap->objectList = NULL;
	heap->fieldList = NULL;
	heap->classList = NULL;

	return heap;
}

void freeHeap(Heap *heap) {
	freeClassList(heap->classList);
	freeFieldList(heap->fieldList);
	free(heap);
}
