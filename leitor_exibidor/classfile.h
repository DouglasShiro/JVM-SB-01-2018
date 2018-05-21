/**
 *  @file classfile.h
 *  @author Felipe Augusto Rodrigues Brandao (12/0044919)
 *  @brief Definition of the class file structure.
 */

#ifndef CLASSFILE_H
#define CLASSFILE_H

#include <stdint.h>

/**
 *  Definition of data types
 */
typedef uint8_t  u1;
typedef uint16_t u2;
typedef uint32_t u4;


/**
 *  @enum ACC_FLAGS
 *  @brief Enum with a type name assignment with the access flag's name.
 *  Contains the flag names matching with its value.
 */
enum {
    ACC_PUBLIC       = 0x0001,
    ACC_FINAL        = 0x0010,
    ACC_SUPER        = 0x0020,
    ACC_INTERFACE    = 0x0200,
    ACC_ABSTRACT     = 0x0400,
    ACC_PRIVATE      = 0x0002,
    ACC_PROTECTED    = 0x0004,
    ACC_STATIC       = 0x0008,
    ACC_VOLATILE     = 0x0040,
    ACC_TRANSIENT    = 0x0080,
    ACC_SYNCHRONIZED = 0x0020,
    ACC_NATIVE       = 0x0100,
    ACC_STRICT       = 0x0800,
} ACC_FLAGS;

/**
 *  @enum CONSTANT_Tags
 *  @brief Enum with a type name assignment with the bytecode number that represents that name.
 *  Contains the constant types matching with its tag value.
 */
enum {
    CONSTANT_Class              = 7,
    CONSTANT_Fieldref           = 9,
    CONSTANT_Methodref          = 10,
    CONSTANT_InterfaceMethodref = 11,
    CONSTANT_String             = 8,
    CONSTANT_Integer            = 3,
    CONSTANT_Float              = 4,
    CONSTANT_Long               = 5,
    CONSTANT_Double             = 6,
    CONSTANT_NameAndType        = 12,
    CONSTANT_Utf8               = 1,
} CONSTANT_Tags;

/**
 * @brief Structure of the constant pool, separated by type.
 * The type definition of the structure is cp_info.
 */
typedef struct cp_info {
    u1 tag;
    union {
        struct CONSTANT_Class_info {
            u2 name_index;
        } class_info;
        struct CONSTANT_Fieldref_info {
            u2 class_index;
            u2 name_and_type_index;
        } fieldref_info;
        struct CONSTANT_NameAndType_info {
            u2 name_index;
            u2 descriptor_index;
        } nameAndType_info;
        struct CONSTANT_Utf8_info {
            u2 length;
            u1 *bytes;
        } utf8_info;
        struct CONSTANT_Methodref_info {
            u2 class_index;
            u2 name_and_type_index;
        } methodref_info;
        struct CONSTANT_InterfaceMethodref_info {
            u2 class_index;
            u2 name_and_type_index;
        } interfaceMethodref_info;
        struct CONSTANT_String_info {
            u2 string_index;
        } string_info;
        struct CONSTANT_Integer_info {
            u4 bytes;
        } integer_info;
        struct CONSTANT_Float_info {
            u4 bytes;
        } float_info;
        struct CONSTANT_Long_info {
            u4 high_bytes;
            u4 low_bytes;
        } long_info;
        struct CONSTANT_Double_info {
            u4 high_bytes;
            u4 low_bytes;
        } double_info;
    };
} cp_info;

/**
 * @brief attribute_info structure.
 *
 * Contains the name index, lenght, info // and specific info.
 */
typedef struct attribute_info {
    u2 attributeName_index;
    u4 attributeLength;
    union {
        struct ConstantValue_attribute {
            u2 constantvalue_index;
        } constantValue;
        struct Code_attribute {
            u2              max_stack;
            u2              max_locals;
            u4              code_length;
            u1             *code;
            u2              exception_table_length;
            struct {
                u2 start_pc;
                u2 end_pc;
                u2 handler_pc;
                u2 catch_type;
            }              *exception_table;
            u2              attributes_count;
            struct attribute_info *attributes;
        } code;
        struct Exceptions_attribute {
            u2 number_of_exceptions;
            u2 *exception_index_table;
        } exceptions;
    };
} attribute_info;

/**
 * @brief field_info structure.
 *
 * Contains the acess flags, name index, descriptor index,
 * attributtes count and a pointer type attribute_info.
 */
typedef struct field_info {
    u2              access_flags;
    u2              name_index;
    u2              descriptor_index;
    u2              attributes_count;
    attribute_info *attributes;
} field_info;


/**
 * @brief method_info strucuture.
 *
 * Contains the acess flags, name index, descriptor index,
 * attributtes count and a pointer type attribute_info.
 */
typedef struct method_info {
    u2              access_flags;
    u2              name_index;
    u2              descriptor_index;
    u2              attributes_count;
    attribute_info *attributes;
} method_info;

/**
 * @brief ClassFile definition.
 *
 * Structure of the class file.
 */
typedef struct ClassFile {
    u4              magic;
    u2              minor_version;
    u2              major_version;
    u2              constant_pool_count;
    cp_info        *constant_pool;
    u2              access_flags;
    u2              this_class;
    u2              super_class;
    u2              interfaces_count;
    u2             *interfaces;
    u2              fields_count;
    field_info     *fields;
    u2              methods_count;
    method_info    *methods;
    u2              attributes_count;
    attribute_info *attributes;
} ClassFile;

#endif
