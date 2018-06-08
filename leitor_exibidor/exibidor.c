/**
 *  @file exibidor.c
 *  @author Adarley Luiz Grando Filho (11/0007344)
 *  @brief Definition of the class file structure.
 */

#include "exibidor.h"

void u1Exib(u1 param){
    printf("u1: ");
    printf("%01x / %d. ",param, param);
}
void u2Exib(u2 param){
    printf("u2: ");
    printf("%02x / %d. ",param, param);
}
void u4Exib(u4 param){
    printf("u4: ");
    printf("%04x. ",param);
}
void constantPoolExib(cp_info * param, u2 size){
    
}
void attributesExib(attribute_info * param, u2 size, cp_info * cp){
    for (u2 i = 0; i < size; i++) {
        printf("\nAttribute %d. ", i);
        printf("Name index cp[%d], ", param[i].attribute_name_index); printf("value: %s. ", cp[param[i].attribute_name_index].utf8_info.bytes);
        printf("Length: %d. ", param[i].attribute_length);
        for (u1 j = 0; j < param[i].attribute_length; j++) {
            printf("info[%d]: ", j);
            
            char *attributeName = (char *) malloc((cp[param[i].attribute_name_index].utf8_info.length + 1) * sizeof(char));
            for (u2 k = 0; k < cp[param[i].attribute_name_index].utf8_info.length; k++) {
                attributeName[k] = cp[param[i].attribute_name_index].utf8_info.bytes[k];
            }
            attributeName[cp[param[i].attribute_name_index].utf8_info.length] = '\0';
            
            if (!strcmp(attributeName, "ConstantValue")) {
                printf("ConstantValue %d. ", param[i].constantValue.constantvalue_index);
            }
            else if (!strcmp(attributeName, "Code")) {
                printf("Code. ");
                //attributesExib(param[i].code.attributes, param[i].code.attributes_count, cp);
            }
            else if (!strcmp(attributeName, "Exceptions")) {
                printf("Exception. ");
            }
            else if (!strcmp(attributeName, "LineNumberTable")) {
                printf("LineNumberTable. ");
            }
            else printf("%s. ", attributeName);
        }
    }
}
void fieldsExib(field_info * param, u2 size){
    
}
void methodsExib(method_info * param, u2 size, cp_info * cp){
    for (u2 i = 0; i < size; i++) {
        printf("\nMethod %d. ", i);
        printf("Access flag: "); u2Exib(param[i].access_flags);
        printf("Name index cp[%d], ", param[i].name_index); printf("value: %s. ", cp[param[i].name_index].utf8_info.bytes);
        printf("Descriptor index cp[%d]. ", param[i].descriptor_index);
        printf("Attributes count: %d. ", param[i].attributes_count);
        attributesExib(param[i].attributes, param[i].attributes_count, cp);
    }
}
void classFileExib(ClassFile * classFile){
    printf("magic: ");
    u4Exib(classFile->magic);
    printf("\nminor version: ");
    u2Exib(classFile->minor_version);
    printf("\nmajor version: ");
    u2Exib(classFile->major_version);
    printf("\nconstant pool count: ");
    u2Exib(classFile->constant_pool_count);
    if (classFile->constant_pool_count > 0) {
        //imprimir contant pool
        constantPoolExib(classFile->constant_pool, classFile->constant_pool_count);
    }
    printf("\naccess flags: ");
    u2Exib(classFile->access_flags);
    printf("\nthis class cp_info index: ");
    u2Exib(classFile->this_class);
    printf("\nsuper class cp_info index: ");
    u2Exib(classFile->super_class);
    printf("\ninterfaces count: ");
    u2Exib(classFile->interfaces_count);
    //imprimir interfaces
    for (int i = 0; i < classFile->interfaces_count; i++) {
        printf("Interface %d: ", i);
        u2Exib(classFile->interfaces[i]);
    }
    printf("\nfields count: ");
    u2Exib(classFile->fields_count);
    if (classFile->fields_count > 0) {
        //imprimir fields
        fieldsExib(classFile->fields, classFile->fields_count);
    }
    printf("\nmethods count: ");
    u2Exib(classFile->methods_count);
    if (classFile->methods_count > 0) {
        //imprimir methods
        methodsExib(classFile->methods, classFile->methods_count, classFile->constant_pool);
    }
    printf("\nattributes count: ");
    u2Exib(classFile->attributes_count);
    if (classFile->attributes_count > 0) {
        //imprimir attributes
        attributesExib(classFile->attributes, classFile->attributes_count, classFile->constant_pool);
    }
    
    
}
