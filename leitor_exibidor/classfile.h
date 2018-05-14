/**
 * @file classfile.h
 * @authors Felipe Augusto Rodrigues BrandAo (12/0044919)
 *
 * @todo Definition of the class file structure.
 */

#ifndef _CLASSFILE_H
#define _CLASSFILE_H

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
typedef uint64_t u8;

/**
 * @brief ClassFile definition.
 *
 * Structure of the class file.
 * The type definition of the structure is ClassFile.
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
 * The type definition of the structure is ConstPool.
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
 * The type definition of the structure is field_info.
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
 * The type definition of the structure is attribute_info.
 */
typedef struct attribute_info {
    u2 attributeName_index;
    u4 attributeLength;
    u1 *info;
    // void *specific_info;
} attribute_info;

/**
 * @brief method_info strucuture.
 *
 * Contains the acess flags, name index, descriptor index,
 * attributtes count and a pointer type attribute_info.
 * The type definition of the structure is method_info.
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
    exception_table_entry   *exception_table;
    u2                      attributes_count;
    attribute_info          *attributes;
} Code_attribute;

/**
 * @brief exception_table entry structure.
 *
 * Describes exception handlers in the code array.
 * The type definition of the structure is exception_table_entry.
 */
typedef struct exception_table_entry {
    u2 start_pc;
    u2 end_pc;
    u2 handler_pc;
    u2 catch_type;
} exception_table_entry;

/**
 * @brief Exception Attribute type.
 *
 * Contains the number of exceptions and a pointer type U2 for the exception table index.
 * The type definition of the Inner Class structure is ExceptionAttribute.
 */
typedef struct _exception_attribute {
    u2 numberOfExceptions;
    u2 *exception_indexTable;
}ExceptionAttribute;

/**
 * @brief Inner Class definition.
 *
 * Contains the index for inner and outer class, inner name index and inner class acess flags.
 * The type definition of the Inner Class structure is InnerClass.
 */
typedef struct _inner_class {
    u2 innerClassInfo_index;
    u2 outerClassInfo_index;
    u2 innerName_index;
    u2 innerClassAccess_flags;
}InnerClass;

/**
 * @brief Inner Classes Attribute definition.
 *
 * Contains the number of classes and a pointer type InnerClass.
 * The type definition of the Inner Class structure is InnerClassesAttribute.
 */
typedef struct _inner_classes_attribute {
    u2 numberOfClasses;
    InnerClass *classes;
}InnerClassesAttribute;

/**
 * @brief Liner Number Table Entry definition.
 *
 * Contains the start PC and the line number.
 * The type definition of the structure is LineNumberTableEntry.
 */
typedef struct _line_number_table_entry {
    u2 start_pc;
    u2 lineNumber;
}LineNumberTableEntry;

/**
 * @brief Line Number Table Attribute definition.
 *
 * Contains the line number table lenght and a pointer type LineNumberTableEntry.
 * The type definition of the structure is LineNumberTableAttribute.
 */
typedef struct _line_number_table_attribute {
    u2 lineNumberTableLength;
    LineNumberTableEntry *lineNumberTable;
}LineNumberTableAttribute;

/**
 * @brief Local Variable Table Entry definition.
 *
 * Contains the start PC, lenght, name and descriptor index, and the index.
 * The type definition of the structure is LocalVariableTableEntry.
 */
typedef struct _local_variable_table_entry {
    u2 start_pc;
    u2 length;
    u2 name_index;
    u2 descriptor_index;
    u2 index;
}LocalVariableTableEntry;

/**
 * @brief  Local Variable Table Attribute definition.
 *
 * Contains the local variable table lenght and a pointer type  LocalVariableTableEntry.
 * The type definition of the structure is LocalVariableTableAttribute.
 */
typedef struct _local_variable_table_attribute {
    u2 localVariableTableLength;
    LocalVariableTableEntry *localVariableTable;
}LocalVariableTableAttribute;

/**
 * @brief Source File Attribute definition.
 *
 * Contains the source file index.
 * The type definition of the structure is SourceFileAttribute.
 */
typedef struct _source_file_attribute {
    u2 sourceFile_index;
}SourceFileAttribute;

typedef struct _verification_type_info{
	u1 tag;

	union{

		struct {

			//uint8_t tag; // possuira valor 0;

		} top_variable_info;

		struct {

			//uint8_t tag; // possuira valor 1;

		} integer_variable_info;

		struct {

			//uint8_t tag; // possuira valor 2;

		} float_variable_info;

		/**	 ATENCAo - Tanto para Long como Double (64bits ambas).
		This structure gives the contents of two locations
		in the operand stack or in the local variable array.
		If the location is a local variable, then:
		It must not be the local variable with the highest index.
		The next higher numbered local variable contains the verification type top.
		If the location is an operand stack entry, then:
		The current location must not be the topmost location of the operand stack.
		The next location closer to the top of the operand stack contains the verification type top.
		*/

		struct {

			//uint8_t tag; // possuira valor 4;

		} long_variable_info;

		struct{

			//uint8_t tag; // possuira valor 3;

		} double_variable_info;

		struct {

			//uint8_t tag; // possuira valor 5;

		} null_variable_info;

		struct {

			//uint8_t tag; // possuira valor 6;

		} uninitializedThis_variable_info;

		/**The Object_variable_info type indicates that the location
		contains an instance of the class represented by the CONSTANT_Class_info*/

		struct {

			//uint8_t tag; // possuira valor 7;
			u2 cpool_index; // index da classe na constant_pool

		} object_variable_info;

		struct {

			//uint8_t tag; // possuira valor 8
			u2 offset; /** The offset item indicates the offset, in the code array
						of the Code attribute that contains this StackMapTable
						attribute, of the new instruction (§new) that created the
						object being stored in the location.*/

		} uninitialized_variable_info;

	} type_info;

}VerificationTypeInfo;

typedef struct _stack_map_frame {
	u1 frame_type;
	union{
        /**
         * @brief Same frame.
         *
         * If the frame type is same_frame, it means the frame has exactly
         * the same locals as the previous stack map frame and
         * that the number of stack items is zero. From 0-63.
         */
		struct{
		} same_frame;
        /**
         * @brief same_locals_1_stack_item_frame.
         *
         * If the frame_type is same_locals_1_stack_item_frame,
         * it means the frame has exactly the same
         * locals as the previous stack map frame and that the number
         * of stack items is 1*. From 64-127.
         */
		struct{
			VerificationTypeInfo *stack;

		} same_locals_1_stack_item_frame;
        /**
         * @brief same_locals_1_stack_item_frame_extended.
         *
         * The frame type same_locals_1_stack_item_frame_extended indicates
         * that the frame has exactly the same locals as the previous
         * stack map frame and that the number of stack items is 1.
         * The offset_delta value for the frame is given explicitly.
         * frame_type == 247.
         */
		struct{
			u2 offset_delta;
    	    VerificationTypeInfo *stack;
		} same_locals_1_stack_item_frame_extended;

		struct{

			/**f the frame_type is chop_frame, it means that the operand stack
			is empty and the current locals are the same as the locals in the
			previous frame, except that the k last locals are absent.
			The value of k is given by the formula 251 - frame_type.*/

			//uint8_t frame_type; //= 248 a 250
			u2 offset_delta;
		} chop_frame;

		struct{

			/**If the frame type is same_frame_extended,
			it means the frame has exactly the same locals as
			the previous stack map frame and that the number of stack items is zero.*/

			//uint8_t frame_type; // == 251
			u2 offset_delta;

		} same_frame_extended;

		struct{

			/**If the frame_type is append_frame, it means that the
			operand stack is empty and the current locals are the same
			as the locals in the previous frame, except that k
			additional locals are defined. The value of k is given by
			the formula frame_type - 251*/


			//uint8_t frame_type;// == 252 a 254
			u2 offset_delta;
			VerificationTypeInfo *locals;

		} append_frame;

		struct{
			/**The frame type full_frame is represented by the tag value 255.*/
			//frame_type == 255
        	u2 offset_delta;
        	u2 number_of_locals;
        	VerificationTypeInfo *locals; // Vetor alocar com number_of_locals
        	u2 number_of_stack_items;
        	VerificationTypeInfo *stack; // Vetor alocar com number_of_stack_items
		} full_frame;

    } map_frame_type;
}StackMapFrame;

/**
 * @brief StackMapTable Attribute definition.
 *
 * Contains the StackMapTable attribute.
 * The type definition of the structure is StackMapTable.
 */
typedef struct _stackmaptable_attribute {
    u2 number_of_entries;
    StackMapFrame *entries;
}StackMapTable;

typedef struct _enclosing_method {
    u2 class_index;
    u2 method_index;
}EnclosingMethod;

typedef struct _signature_attribute {
    u2 signature_index;
}Signature_attribute;

typedef struct _sourceDebugExtension_attribute {
    u1 *debug_extension;
}SourceDebugExtension_attribute;

struct _annotation;
struct _element_value;

typedef struct _element_value{
    u1 tag;
    union {
        u2 const_value_index;

        struct{
            u2 type_name_index;
            u2 const_name_index;
        } enum_const_value;

        u2 class_info_index;

        struct _annotation *annotation_value;

        struct{
            u2 num_values;
            struct element_value* values;
        } array_value;
    } value;
}Element_value;


typedef struct _element_value_pairs{
    u2 element_name_index;
    Element_value *value;
}Element_value_pairs;

typedef struct _annotation {
    u2 type_index;
    u2 num_element_value_pairs;
    Element_value_pairs* value_pairs;
}Annotation;

typedef struct _parameter_annotations {
    u2 num_annotations;
    Annotation *annotations;
}Parameter_annotations;

typedef struct _runtimeVisibleAnnotations_attribute {
    Parameter_annotations *parameters_annotations;
}RuntimeVisibleAnnotations_attribute;

typedef struct _runtimeInvisibleAnnotations_attribute {
    Parameter_annotations *parameters_annotations;
}RuntimeInvisibleAnnotations_attribute;

typedef struct _runtimeVisibleParameterAnnotations_attribute {
    u1 num_parameters;
    Parameter_annotations *parameters_annotations;
}RuntimeVisibleParameterAnnotations_attribute;

typedef struct _runtimeInvisibleParameterAnnotations_attribute {
    u1 num_parameters;
    Parameter_annotations *parameters_annotations;
}RuntimeInvisibleParameterAnnotations_attribute;

typedef struct _annotationDefault_attribute {
    Element_value *default_value;
}AnnotationDefault_attribute;

typedef struct _bootstrap_methods{
    u2 bootstrap_method_ref;
    u2 num_bootstrap_arguments;
    u2 *bootstrap_arguments;
}Bootstrap_methods;

typedef struct _BootstrapMethods_attribute {
    u2 num_bootstrap_methods;
    Bootstrap_methods * bootstrap_methods;
}BootstrapMethods_attribute;

#endif
