/**
 *  @file exibidor.c
 *  @author Adarley Luiz Grando Filho (11/0007344)
 *  @brief Definition of the class file structure.
 */

#include "exibidor.h"

/**
 *  @fn void u1Read(u1 param)
 *  @brief Imprime valor u1.
 *  @param param Variavel a ser impressa.
 */
void u1Exib(u1 param) {
    printf("u1: ");
    printf("%01x / %d. ",param, param);
}

/**
 *  @fn void u2Read(u2 param)
 *  @brief Imprime valor u2.
 *  @param param Variavel a ser impressa.
 */
void u2Exib(u2 param) {
    printf("u2: ");
    printf("%02x / %d. ",param, param);
}

/**
 *  @fn void u4Read(u4 param)
 *  @brief Imprime valor u4.
 *  @param param Variavel a ser impressa.
 */
void u4Exib(u4 param) {
    printf("u4: ");
    printf("%04x. ",param);
}

/**
 *  @fn void constantPoolExib(cp_info * param, u2 size)
 *  @brief Imprime os valores do Constant Pool.
 *  @param param Constant Pool a ser impresso.
 *  @param size Tamanho do array do Constant Pool a ser impresso.
 */
void constantPoolExib(cp_info * param, u2 size){
    for (u2 i = 1; i < size; i++) {
        printf("\nCP item %d. ", i);
        switch (param[i].tag) {
            case CONSTANT_Class:
                printf("CONSTANT_Class. Name index: cp[%d]. ", param[i].class_info.name_index);
                break;
            case CONSTANT_Fieldref:
                printf("CONSTANT_Fieldref. ");
                printf("Class name: cp[%d]. ", param[i].fieldref_info.class_index);
                printf("Name and type: cp[%d]. ", param[i].fieldref_info.name_and_type_index);
                break;
            case CONSTANT_NameAndType:
                printf("CONSTANT_NameAndType. ");
                printf("Name index: cp[%d]. ", param[i].nameAndType_info.name_index);
                printf("Descriptor index: cp[%d]. ", param[i].nameAndType_info.descriptor_index);
                break;
            case CONSTANT_Utf8:
                printf("CONSTANT_Utf8. Length: %d. ", param[i].utf8_info.length);
                printf("Value: ");
                for (u2 j = 0; j < param[i].utf8_info.length; j++)
                    printf("%c", param[i].utf8_info.bytes[j]);
                printf(". ");
                break;
            case CONSTANT_Methodref:
                printf("CONSTANT_Methodref. ");
                printf("Class name: cp[%d]. ", param[i].methodref_info.class_index);
                printf("Name and type: cp[%d]. ", param[i].methodref_info.name_and_type_index);
                break;
            case CONSTANT_InterfaceMethodref:
                printf("CONSTANT_InterfaceMethodref. ");
                printf("Class name: cp[%d]. ", param[i].interfaceMethodref_info.class_index);
                printf("Name and type: cp[%d]. ", param[i].interfaceMethodref_info.name_and_type_index);
                break;
            case CONSTANT_String:
                printf("CONSTANT_String. Index: cp[%d]. ", param[i].string_info.string_index);
                break;
            case CONSTANT_Integer:
                printf("CONSTANT_Integer. Value: ");
                u4Exib(param[i].integer_info.bytes);
                break;
            case CONSTANT_Float:
                printf("CONSTANT_Float. Value: ");
                u4Exib(param[i].float_info.bytes);
                break;
            case CONSTANT_Long:
                printf("CONSTANT_Long. ");
                printf("High bytes: ");u4Exib(param[i].long_info.high_bytes);
                printf("Low bytes: ");u4Exib(param[i].long_info.low_bytes);
                i++;
                break;
            case CONSTANT_Double:
                printf("CONSTANT_Double. ");
                printf("High bytes: ");u4Exib(param[i].double_info.high_bytes);
                printf("Low bytes: ");u4Exib(param[i].double_info.low_bytes);
                i++;
                break;
            default:;
        }
    }
}

/**
 *  @fn void attributesExib(attribute_info * param, u2 size, cp_info * cp)
 *  @brief Imprime os valores de Atributos.
 *  @param param Tabela de Atributos a ser impressa.
 *  @param size Tamanho do array da Tabela de Atributos a ser impressa.
 *  @param cp Tabela Constant Pool usada somente para consulta.
 */
void attributesExib(attribute_info * param, u2 size, cp_info * cp){
    for (u2 i = 0; i < size; i++) {
        printf("\nAttribute %d. ", i);
        printf("\nName index cp[%d], ", param[i].attribute_name_index);
		printf("\nvalue: %s. ", cp[param[i].attribute_name_index].utf8_info.bytes);
        printf("\nLength: %d. ", param[i].attribute_length);
        for (u1 j = 0; j < param[i].attribute_length; j++) {
            printf("\ninfo[%d]: ", j);
            char *attributeName = (char *) malloc((cp[param[i].attribute_name_index].utf8_info.length + 1) * sizeof(char));
            for (u2 k = 0; k < cp[param[i].attribute_name_index].utf8_info.length; k++) {
                attributeName[k] = cp[param[i].attribute_name_index].utf8_info.bytes[k];
            }
            attributeName[cp[param[i].attribute_name_index].utf8_info.length] = '\0';

            if (!strcmp(attributeName, "ConstantValue")) {
                printf("\nConstantValue %d. ", param[i].constantValue.constantvalue_index);
            }
            else printf("%s. ", attributeName);
            free(attributeName);
        }
    }
}

/**
 *  @fn void fieldsExib(field_info * param, u2 size, cp_info * cp)
 *  @brief Imprime os valores de Fields.
 *  @param param Tabela de Fields a ser impressa.
 *  @param size Tamanho do array da Tabela de Fields a ser impressa.
 *  @param cp Tabela Constant Pool usada somente para consulta.
 */
void fieldsExib(field_info * param, u2 size, cp_info * cp){
    for (u2 i = 0; i < size; i++) {
        printf("\nField %d. ", i);
        //imprimir param[i].access_flags = u2Read(file);
        printf("Name index: cp[%d], ", param[i].name_index); printf("value: %s. ", cp[param[i].name_index].utf8_info.bytes);
        printf("Descriptor index: cp[%d]. ", param[i].descriptor_index);
        printf("Attributes count: %d. ", param[i].attributes_count);
        //imprimir param[i].attributes
    }
}

/**
 *  @fn void methodsExib(method_info * param, u2 size, cp_info * cp)
 *  @brief Imprime os valores de Métodos.
 *  @param param Tabela de Métodos a ser impressa.
 *  @param size Tamanho do array da Tabela de Métodos a ser impressa.
 *  @param cp Tabela Constant Pool usada somente para consulta.
 */
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

/**
 *  @fn void classFileExib(ClassFile * classFile)
 *  @brief Imprime os valores de um ClassFile.
 *  @param classFile Estrutura de dados do ClassFile a ser impresso.
 */
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
        fieldsExib(classFile->fields, classFile->fields_count, classFile->constant_pool);
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

char* getConstantUTF8CP(cp_info * cp, u2 index) {
    char* str = NULL;
    if (cp[index].tag == CONSTANT_Utf8) {
        str = (char *) malloc((cp[index].utf8_info.length + 1) * sizeof(char));
        for (u2 j = 0; j < cp[index].utf8_info.length; j++)
            str[j] = cp[index].utf8_info.bytes[j];
        str[cp[index].utf8_info.length] = '\0';
    }
    return str;
}
