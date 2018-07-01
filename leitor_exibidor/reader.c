#include "reader.h"

/**
 *  @fn u1 u1Read(FILE *file)
 *  @brief Reads a u1 from a file.
 *  @param file Pointer to the file it will be read from.
 *  @return Read u1.
 */
u1 u1Read(FILE *file) {
    u1 toReturn = getc(file);
    
    return toReturn;
}

/**
 *  @fn u2 u2Read(FILE *file)
 *  @brief Reads a u2 from a file.
 *  @param file Pointer to the file it will be read from.
 *  @return Read u2.
 */
u2 u2Read(FILE *file) {
    u2 toReturn = getc(file) << 8 | getc(file);
    
    return toReturn;
}

/**
 *  @fn u4 u4Read(FILE *file)
 *  @brief Reads a u4 from a file.
 *  @param file Pointer to the file it will be read from.
 *  @return Read u4.
 */
u4 u4Read(FILE *file) {
    u4 toReturn = getc(file) << 24 | getc(file) << 16 | getc(file) << 8 | getc(file);
    
    return toReturn;
}

void constantPoolRead(FILE *file, ClassFile *classFile) {
    classFile->constant_pool_count = u2Read(file);
    
    if (classFile->constant_pool_count > 0)
        classFile->constant_pool = (cp_info *) malloc((classFile->constant_pool_count - 1) * sizeof(cp_info));
    else
        classFile->constant_pool = NULL;
    
    u2 i;
    for (i = 1; i < classFile->constant_pool_count; i++) {
        classFile->constant_pool[i].tag = u1Read(file);
        
        switch (classFile->constant_pool[i].tag) {
            case CONSTANT_Class:
                classFile->constant_pool[i].class_info.name_index = u2Read(file);
                break;
            case CONSTANT_Fieldref:
                classFile->constant_pool[i].fieldref_info.class_index = u2Read(file);
                classFile->constant_pool[i].fieldref_info.name_and_type_index = u2Read(file);
                break;
            case CONSTANT_NameAndType:
                classFile->constant_pool[i].nameAndType_info.name_index = u2Read(file);
                classFile->constant_pool[i].nameAndType_info.descriptor_index = u2Read(file);
                break;
            case CONSTANT_Utf8:
                classFile->constant_pool[i].utf8_info.length = u2Read(file);
                classFile->constant_pool[i].utf8_info.bytes = (u1 *) malloc(classFile->constant_pool[i].utf8_info.length * sizeof(u1));
                
                u2 j;
                for (j = 0; j < classFile->constant_pool[i].utf8_info.length; j++)
                    classFile->constant_pool[i].utf8_info.bytes[j] = u1Read(file);
                
                classFile->constant_pool[i].utf8_info.bytes[classFile->constant_pool[i].utf8_info.length] = '\0';
                break;
            case CONSTANT_Methodref:
                classFile->constant_pool[i].methodref_info.class_index = u2Read(file);
                classFile->constant_pool[i].methodref_info.name_and_type_index = u2Read(file);
                break;
            case CONSTANT_InterfaceMethodref:
                classFile->constant_pool[i].interfaceMethodref_info.class_index = u2Read(file);
                classFile->constant_pool[i].interfaceMethodref_info.name_and_type_index = u2Read(file);
                break;
            case CONSTANT_String:
                classFile->constant_pool[i].string_info.string_index = u2Read(file);
                break;
            case CONSTANT_Integer:
                classFile->constant_pool[i].integer_info.bytes = u4Read(file);
                break;
            case CONSTANT_Float:
                classFile->constant_pool[i].float_info.bytes = u4Read(file);
                break;
            case CONSTANT_Long:
                classFile->constant_pool[i].long_info.high_bytes = u4Read(file);
                classFile->constant_pool[i].long_info.low_bytes = u4Read(file);
                i++;
                break;
            case CONSTANT_Double:
                classFile->constant_pool[i].double_info.high_bytes = u4Read(file);
                classFile->constant_pool[i].double_info.low_bytes = u4Read(file);
                i++;
                break;
            default:;
        }
    }
}

attribute_info *attributesRead(FILE *file, cp_info *constant_pool, u2 attributes_count) {
    attribute_info *attributes;
    
    if (attributes_count > 0)
        attributes = (attribute_info *) malloc(attributes_count * sizeof(attribute_info));
    else
        attributes = NULL;
    
    u2 i;
    for (i = 0; i < attributes_count; i++) {
        attributes[i].attribute_name_index = u2Read(file);
        attributes[i].attribute_length = u4Read(file);
        
        char *attributeName = (char *) malloc((constant_pool[attributes[i].attribute_name_index].utf8_info.length + 1) * sizeof(char));
        
        u2 j;
        for (j = 0; j < constant_pool[attributes[i].attribute_name_index].utf8_info.length; j++) {
            attributeName[j] = constant_pool[attributes[i].attribute_name_index].utf8_info.bytes[j];
        }
        
        attributeName[constant_pool[attributes[i].attribute_name_index].utf8_info.length] = '\0';
        
        if (!strcmp(attributeName, "ConstantValue"))
            attributes[i].constantValue.constantvalue_index = u2Read(file);
        else if (!strcmp(attributeName, "Code")) {
            attributes[i].code.max_stack = u2Read(file);
            attributes[i].code.max_locals = u2Read(file);
            attributes[i].code.code_length = u4Read(file);
            attributes[i].code.code = (u1 *) malloc(attributes[i].code.code_length * sizeof(u1));
            
            int j1;
            for (j1 = 0; j1 < attributes[i].code.code_length; j1++)
                attributes[i].code.code[j1] = u1Read(file);
            
            attributes[i].code.exception_table_length = u2Read(file);
            
            if (attributes[i].code.exception_table_length > 0)
                attributes[i].code.exception_table = (struct exception_table *) malloc(attributes[i].code.exception_table_length * sizeof(struct exception_table));
            else
                attributes[i].code.exception_table = NULL;
            
            int j2;
            for (j2 = 0; j2 < attributes[i].code.exception_table_length; j2++) {
                attributes[i].code.exception_table[j2].start_pc = u2Read(file);
                attributes[i].code.exception_table[j2].end_pc = u2Read(file);
                attributes[i].code.exception_table[j2].handler_pc = u2Read(file);
                attributes[i].code.exception_table[j2].catch_type = u2Read(file);
            }
            
            attributes[i].code.attributes_count = u2Read(file);
            attributes[i].code.attributes = attributesRead(file, constant_pool, attributes[i].code.attributes_count);
        } else if (!strcmp(attributeName, "Exceptions")) {
            attributes[i].exceptions.number_of_exceptions = u2Read(file);
            attributes[i].exceptions.exception_index_table = (u2 *) malloc(attributes[i].exceptions.number_of_exceptions * sizeof(u2));
            
            int j3;
            for (j3 = 0; j3 < attributes[i].exceptions.number_of_exceptions; j3++)
                attributes[i].exceptions.exception_index_table[j3] = u2Read(file);
        } else {
            fseek(file, attributes[i].attribute_length, SEEK_CUR);
        }
        
        free(attributeName);
    }
    
    return attributes;
}

void fieldsRead(FILE *file, ClassFile *classFile) {
    classFile->fields_count = u2Read(file);
    
    if (classFile->fields_count > 0)
        classFile->fields = (field_info *) malloc(classFile->fields_count * sizeof(field_info));
    else
        classFile->fields = NULL;
    
    u2 i;
    for (i = 0; i < classFile->fields_count; i++) {
        classFile->fields[i].access_flags = u2Read(file);
        classFile->fields[i].name_index = u2Read(file);
        classFile->fields[i].descriptor_index = u2Read(file);
        classFile->fields[i].attributes_count = u2Read(file);
        classFile->fields[i].attributes = attributesRead(file, classFile->constant_pool, classFile->fields[i].attributes_count);
        
    }
}

void methodsRead(FILE *file, ClassFile *classFile) {
    classFile->methods_count = u2Read(file);
    
    if (classFile->methods_count > 0)
        classFile->methods = (method_info *) malloc(classFile->methods_count * sizeof(method_info));
    else
        classFile->methods = NULL;
    
    u2 i;
    for (i = 0; i < classFile->methods_count; i++) {
        classFile->methods[i].access_flags = u2Read(file);
        classFile->methods[i].name_index = u2Read(file);
        classFile->methods[i].descriptor_index = u2Read(file);
        classFile->methods[i].attributes_count = u2Read(file);
        classFile->methods[i].attributes = attributesRead(file, classFile->constant_pool, classFile->methods[i].attributes_count);
        
    }
}

ClassFile *classFileRead(char *fileName) {
    FILE *file = fopen(fileName, "rb");
    ClassFile *classFile = (ClassFile *) malloc(sizeof(ClassFile));
    
    classFile->magic = u4Read(file);
    classFile->minor_version = u2Read(file);
    classFile->major_version = u2Read(file);
    constantPoolRead(file, classFile);
    classFile->access_flags = u2Read(file);
    classFile->this_class = u2Read(file);
    classFile->super_class = u2Read(file);
    classFile->interfaces_count = u2Read(file);
    classFile->interfaces = (u2 *) malloc(classFile->interfaces_count * sizeof(u2));
    
    int i;
    for (i = 0; i < classFile->interfaces_count; i++)
        classFile->interfaces[i] = u2Read(file);
    
    fieldsRead(file, classFile);
    methodsRead(file, classFile);
    classFile->attributes_count = u2Read(file);
    classFile->attributes = attributesRead(file, classFile->constant_pool, classFile->attributes_count);
    
    fclose(file);
    
    return classFile;
}
