/**
 * @file classfile.h
 * @authors Felipe Augusto Rodrigues BrandAo (12/0044919)
 *
 * @todo Definition of the class file structure.
 */

#ifndef CLASSFILE_H
#define CLASSFILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

/**
 * Definition of data types
 */
typedef uint8_t  u1;
typedef uint16_t u2;
typedef uint32_t u4;

/**
 * @brief ClassFile definition.
 *
 * Structure of the class file.
 */
typedef struct ClassFile {
    /**
     * @brief Identify the class file format.
     */
    u4 magic;
    /**
     * @brief Minor version number.
     */
    u2 minor_version;
     /**
     * @brief Major version number.
     */
    u2 major_version;
   /**
     * @brief Number of entries in the constant_pool table plus one.
     */
    u2 constant_pool_count;
    /**
     * @brief Table of structures representing various string constants, class and interface names, field names,
     * and other constants that are referred to within the ClassFile structure and its substructures
     */
    cp_info *constant_pool;
   /**
     * @brief Mask of flags used to denote access permissions to and properties of the class or interface.
     */
    u2 access_flags;
    /**
     * @brief Valid index into the constant_pool table which entry represents the class or interface defined by the class file.
     */
    u2 this_class;
    /**
     * @brief Represents the direct superclass of the class defined by the class file.
     */
    u2 super_class;
    /**
     * @brief Number of direct superinterfaces of the class or interface type.
     */
    u2 interfaces_count;
    /**
     * @brief Array of the interfaces that are a direct superinterface of the class or interface type.
     */
    u2 *interfaces;
    /**
     * @brief Number of field_info structures in the fields table.
     */
    u2 fields_count;
    /**
     * @brief Table of complete descriptions of the fields in the class or interface.
     */
    field_info *fields;
    /**
     * @brief Number of method_info structures in the methods table.
     */
    u2 methods_count;
    /**
     * @brief Table of complete descriptions of the methods in the class or interface.
     */
    method_info *methods;
    /**
     * @brief Number of attributes in the attributes table of the class.
     */
    u2 attributes_count;
    /**
     * @brief Table of the attributes in the class.
     */
    attribute_info *attributes;
} ClassFile;

/**
 * @brief Enum with a type name assignment with the access flag's name.
 * Contains the constants types matching with its flag.
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
 * @brief Enum with a type name assignment with the bytecode number that represents that name.
 * Contains the constants types matching with its tag.
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
    /**
     * @brief Tag item from the constant pool.
     *
     * Tag item is common for all types.
     */
    u1 tag;
    /**
     * @brief Union of structs that have the constant_pool components
     *
     * Each type has its own structure.
     */
    union {
        /**
         * @brief Class structure.
         *
         * Represents a class or an interface.
         */
        struct CONSTANT_Class_info {
            u2 name_index;
        };
        /**
         * @brief Fieldref structure.
         *
         * Represents the fields of the class or interface.
         */
        struct CONSTANT_Fieldref_info {
            u2 class_index;
            u2 name_and_type_index;
        };
        /**
         * @brief Name and Type structure.
         *
         * Represents a field or method.
         */
        struct CONSTANT_NameAndType_info{
            u2 name_index;
            u2 descriptor_index;
        };
        /**
         * @brief Utf8 structure.
         *
         * Represents constant string values.
         */
        struct CONSTANT_Utf8_info{
            u2 length;
            u1 *bytes;
        };
        /**
         * @brief Methodref structure.
         *
         * Represents the methods of the class.
         */
        struct CONSTANT_Methodref_info{
            u2 class_index;
            u2 name_and_type_index;
        };
        /**
         * @brief InterfaceMethodref structure.
         *
         * Represents the interface methods of the interface.
         */
        struct CONSTANT_InterfaceMethodref_info{
            u2 class_index;
            u2 name_and_type_index;
        };
        /**
         * @brief String structure.
         *
         * Represents constant objects of the type String.
         */
        struct CONSTANT_String_info{
            u2 string_index;
        };
        /**
         * @brief Integer structure.
         *
         * Represents 4-byte numeric int constants.
         */
        struct CONSTANT_Integer_info{
            u4 bytes;
        };
        /**
         * @brief Float structure.
         *
         * Represents 4-byte numeric float constants.
         */
        struct CONSTANT_Float_info{
            u4 bytes;
        };
        /**
         * @brief Long structure.
         *
         * Represents 8-byte numeric long constants.
         */
        struct CONSTANT_Long_info{
            u4 high_bytes;
            u4 low_bytes;
        };
         /**
         * @brief Double structure.
         *
         * Represents 8-byte numeric double constants.
         */
        struct CONSTANT_Double_info{
            u4 high_bytes;
            u4 low_bytes;
        };
    };
} cp_info;

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
 * @brief attribute_info structure.
 *
 * Contains the name index, lenght, info // and specific info.
 */
typedef struct attribute_info {
    u2 attributeName_index;
    u4 attributeLength;
    u1 *info;
} attribute_info;

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
 * @brief ConstantValue attribute structure.
 *
 * Represents the value of a constant expression.
 * The type definition of the structure is ConstantValue_attribute.
 */
typedef struct ConstantValue_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 constantvalue_index;
} ConstantValue_attribute;

/**
 * @brief Code attribute structure.
 *
 * Contains the Java Virtual Machine instructions and auxiliary information for a method,
 * including an instance initialization method or a class or interface initialization method.
 * The type definition of the structure is Code_attribute.
 */
typedef struct Code_attribute {
    u2                      attribute_name_index;
    u4                      attribute_length;
    u2                      max_stack;
    u2                      max_locals;
    u4                      code_length;
    u1                      *code;
    u2                      exception_table_length;
    /**
     * @brief exception_table entry structure.
     *
     * Describes exception handlers in the code array.
     */
    struct exception_table {
        u2 start_pc;
        u2 end_pc;
        u2 handler_pc;
        u2 catch_type;
    }                       *exception_table;
    u2                      attributes_count;
    attribute_info          *attributes;
} Code_attribute;

/**
 * @brief Exceptions_attribute structure.
 *
 * Indicates which checked exceptions a method may throw.
 */
typedef struct Exceptions_attribute {
    u4 attribute_name_index;
    u4 attribute_length;
    u2 number_of_exceptions;
    u2 *exception_index_table;
} Exceptions_attribute;

/**
 * @brief InnerClasses_attribute structure.
 *
 * Represents classes or interfaces that are not members of a package.
 */
typedef struct InnerClasses_attribute {
    u2 attribute_name_index;
    u4 attribute_length;
    u2 number_of_classes;
    struct classes {
        u2 inner_class_info_index;
        u2 outer_class_info_index;
        u2 inner_name_index;
        u2 inner_class_access_flags;
    } *classes;
} InnerClasses_attribute;

#endif
