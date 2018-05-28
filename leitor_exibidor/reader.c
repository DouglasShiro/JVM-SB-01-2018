#include "reader.h"

int main()
{
    return 0;
}

/**
 *	@fn u1 u1Read(FILE *file)
 *	@brief Reads a u1 from a file.
 *	@param file Pointer to the file it will be read from.
 *	@return Read u1.
 */
static u1 u1Read(FILE *file) {
	u1 toReturn = getc(file);

	return toReturn;
}

/**
 *	@fn u2 u2Read(FILE *file)
 *	@brief Reads a u2 from a file.
 *	@param file Pointer to the file it will be read from.
 *	@return Read u2.
 */
static u2 u2Read(FILE *file) {
	u2 toReturn = getc(file) << 8 | getc(file);
	
	return toReturn;
}

/**
 *	@fn u4 u4Read(FILE *file)
 *	@brief Reads a u4 from a file.
 *	@param file Pointer to the file it will be read from.
 *	@return Read u4.
 */
static u4 u4Read(FILE *file) {
	u4 toReturn = getc(file) << 24 | getc(file) << 16 | getc(file) << 8 | getc(file);

	return toReturn;
}

void constantPoolRead(FILE *file, ClassFile *classFile) {
    classFile->constant_pool_count = u2Read(file);

    if (classFile->constant_pool_count > 0)
        classFile->constant_pool = (cp_info *) malloc((classFile->constant_pool_count - 1) * sizeof(cp_info));
    else
        classFile->constant_pool = NULL;

    for (u2 i = 1; i < classFile->constant_pool_count; i++) {
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
                classFile->constant_pool[i].utf8_info.bytes = (u1 *) malloc(classFile->constant_pool[i].utf8_info.length *
                                                                                    sizeof(u1));

                for (u2 j = 0; j < classFile->constant_pool[i].utf8_info.length; j++)
                    classFile->constant_pool[i].utf8_info.bytes[j] = u1Read(file);

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

void exceptionTableRead(FILE *file, ClassFile *classFile) {

}

attribute_info *attributesRead(FILE *file, cp_info *constant_pool, u2 attributes_count) {
    attribute_info *attributes = (attribute_info *) malloc(attributes_count * sizeof(attribute_info));

    for (u2 i = 0; i < attributes_count; i++) {
        attributes[i].attributeName_index = u2Read(file);
        attributes[i].attributeLength = u4Read(file);

    }

    return attributes;
}

void fieldsRead(FILE *file, ClassFile *classFile) {
    classFile->fields_count = u2Read(file);

    if (classFile->fields_count > 0)
        classFile->fields = (field_info *) malloc(classFile->fields_count * sizeof(field_info));
    else
        classFile->fields = NULL;

    for (u2 i = 0; i < classFile->fields_count; i++) {
        classFile->fields[i].access_flags = u2Read(file);
        classFile->fields[i].name_index = u2Read(file);
        classFile->fields[i].descriptor_index = u2Read(file);
        classFile->fields[i].attributes_count = u2Read(file);
        classFile->fields[i].attributes = attributesRead(file, classFile->constant_pool, classFile->attributes_count);

    }
}

void methodsRead(FILE *file, ClassFile *classFile) {
    classFile->methods_count = u2Read(file);

    if (classFile->methods_count > 0)
        classFile->methods = (method_info *) malloc(classFile->methods_count * sizeof(method_info));
    else
        classFile->methods = NULL;

    for (u2 i = 0; i < classFile->methods_count; i++) {
        classFile->methods[i].access_flags = u2Read(file);
        classFile->methods[i].name_index = u2Read(file);
        classFile->methods[i].descriptor_index = u2Read(file);
        classFile->methods[i].attributes_count = u2Read(file);
        classFile->methods[i].attributes = attributesRead(file, classFile->constant_pool, classFile->attributes_count);

    }
}

void classFileRead(FILE *file, ClassFile *classFile) {

}
