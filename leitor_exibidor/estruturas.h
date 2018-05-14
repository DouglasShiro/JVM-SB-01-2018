

typedef uint16_t u2; //unsigned 2 bytes
typedef uint32_t u4; //unsigned 4 bytes

typedef union Cp_info {
  struct CONSTANT_Class_info {
    u1 tag;
    u2 name_index;
  };
  struct CONSTANT_Fieldref_info {
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
  };
  struct CONSTANT_Methodref_info {
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
  };
  struct CONSTANT_InterfaceMethodref_info {
    u1 tag;
    u2 class_index;
    u2 name_and_type_index;
  };
  struct CONSTANT_String_info {
    u1 tag;
    u2 string_index;
  };
  struct CONSTANT_Integer_info {
    u1 tag;
    u4 bytes;
  };
  struct CONSTANT_Float_info {
    u1 tag;
    u4 bytes;
  };
  struct CONSTANT_Long_info {
    u1 tag;
    u4 high_bytes;
    u4 low_bytes;
  };
  struct CONSTANT_Double_info {
    u1 tag;
    u4 high_bytes;
    u4 low_bytes;
  };
  struct CONSTANT_NameAndType_info {
    u1 tag;
    u2 name_index;
    u2 descriptor_index;
  };
  struct CONSTANT_Utf8_info {
    u1 tag;
    u2 length;
    u1 bytes[length];
  };
  struct CONSTANT_MethodHandle_info {
    u1 tag;
    u1 reference_kind;
    u2 reference_index;
  };
  struct CONSTANT_MethodType_info {
    u1 tag;
    u2 descriptor_index;
  };
  struct CONSTANT_InvokeDynamic_info {
    u1 tag;
    u2 bootstrap_method_attr_index;
    u2 name_and_type_index;
  };
} cp_info;

typedef struct Attribute_info {
  u2 attribute_name_index;
  u4 attribute_length;
  u1 info[attribute_length];
} attribute_info;

typedef struct Field_info {
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info attributes[attributes_count];
} field_info;

typedef struct Method_info {
  u2 access_flags;
  u2 name_index;
  u2 descriptor_index;
  u2 attributes_count;
  attribute_info attributes[attributes_count];
} method_info;

typedef struct Class_file {
	u4 magic; //0xCAFEBABE
	u2 minor_version;
	u2 major_version;
	u2 constant_pool_count;
	cp_info *constant_pool;
	u2 access_flags;
	u2 this_class;
	u2 super_class;
	u2 interfaces_count;
	u2 *interfaces;
	u2 fields_count;
	field_info *fields;
	u2 methods_count;
	method_info *methods;
	u2 attributes_count;
	attribute_info *attributes;
} ClassFile;
