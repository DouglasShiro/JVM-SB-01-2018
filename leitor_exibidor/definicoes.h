//Arquivo de definicoes do .class
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// tipos de dados
typedef uint8_t		U1;
typedef uint16_t	U2;
typedef uint32_t	U4;
typedef uint64_t	U8;

typedef int8_t		I1;
typedef int16_t		I2;
typedef int32_t		I4;
typedef int64_t		I8;

typedef union Info_ConstantPool {
   /**
   *	@brief UTF8 que sera usado na union
   */
   struct {
		   //U1 tag;
		   // valor 1//
		   // numero de bytes no array
	   U2 length;
		   // contem os bytes da string
	   U1 * bytes;
   } Utf8_info;
   /**
	*	@brief Representa uma Classe ou Interface
	*/
   struct {
	   /*CONSTANT_Class_info */
	   //U1 tag;
	   // valor 7//
	   // Indica o nome da classe e interface
	   U2 name_index;
   } Class_info;
   /**
	*	@brief Representando field_info
	*/
   struct {
	   /* CONSTANT_Fieldref_info*/
	   //U1 tag;
	   // valor 9//
	   // indica o nome completo
	   U2 class_index;
	   // indica o nome e tipo e descritor do field
	   U2 name_and_type_index;
   } Fieldref_info;
   /**
   *	@brief Representando um field ou metodos sem indicar classe ou interface
   */
   struct {
	   /* CONSTANT_NameAndType_info*/
	   //U1 tag;
		   // valor 12//
	   // indica o nome completo
	   U2 name_index;
	   // descritor do field
	   U2 descriptor_index;
   } Method_name_and_type_info;
   /**
	*	@brief Representa metodo
	*/
   struct {
	   /*CONSTANT_Methodref_info */
	   //U1 tag;
		   // valor 10//
	   // valido para a tabela constantpool
	   // representa o nome completo da classe que contem a declaracao desse
	   // metodo
	   U2 class_index;
	   //Nome e descritor do metodo
	   U2 name_and_type_index;
   } Methodref_info;

   /**
   *	@brief InterfaceMethod definido
   */
   struct {
	   /*CONSTANT_InterfaceMethodref_info */
	   //U1 tag;
	   // valor 11//
	   // valido para a tabela constantpool
	   // representa o nome completo da
	   //interface que contem a declaracao deste metodo
	   U2 class_index;
	   //Nome e descritor do metodo
	   U2 name_and_type_index;
   } Interface_methodref_info;
   /**
   *	@brief Definindo string
   */
   struct {
	   /*CONSTANT_String_info*/
	   //U1 tag;
	   // valor 8//
	   // string com qual a STRING sera iniciada
	   U2 string_index;
   } String_info;
   /**
	 *	@brief Representa uma constante inteira de 4 bytes
	 */
   struct {
	   /*CONSTANT_Integer_info*/
	   //U1 tag;
	   // valor 3//
	   // valor da constante int, em big-endian
	   U4 bytes;
   } Integer_info;
   /**
	 *	@brief Representa um float
	 */
   struct {
	   /*CONSTANT_Float_info*/
	   //U1 tag;
	   // valor 4//
	   // valor da constante int, em big-endian
	   // formato IEEE 754
	   U4 bytes;
   } Float_info;
   /**
	 *	@brief Representa long -> 4 bytes de msb e 4 bytes de lsb
	 */
   struct {
	   /*CONSTANT_Long_info*/
	   //U1 tag;
		   // valor 5//
	   U4 high_bytes;
	   U4 low_bytes;
	   // O valor long armazenado e pela expressao:
	   // ((long) high_bytes << 32) + low_bytes
   } Long_info;
   /**
	 *	@brief Representa um double -> 4 bytes de msb e 4 bytes de lsb
	 */
   struct {
	   /*CONSTANT_Double_info*/
	   //U1 tag;
	   // valor 6//
	   U4 high_bytes;
	   U4 low_bytes;
	   // O valor long armazenado e pela expressao:
	   // ((long) high_bytes << 32) + low_bytes
   } Double_info;
} Info_constant_pool;
   /**
	 *	@brief Finalmente definindo estrutura cp_info completa
	 */
typedef struct cp_info {
   U1 tag;
   Info_constant_pool cp_info;
} Cp_info;

/**
*	@brief FExeption_table == Cada entrada descreve um manipulador das excecoes que podem ocorrer na JVM contido no array
*/
typedef struct exception_table {
   // manipulador esta ativo para indice[start_pc,end_pc]
   U2 start_pc;
   U2 end_pc;

   U2 handler_pc; /**<  indica o byte code inicial do manipulador
*/

   // Clausula Catch -> clausula catvh
   // Se nao nulo
   //Se nulo -> clausula finally
   U2 catch_type; /**<	clausula catch Se nao nulo, se nulo -> clausula finally*/
} Exception_table;

/*
*	@brief Atributo de tamanho variavel utilizado na tabela de atributes da estrutura ClassFile
*/
typedef struct inner_Classes {
   // Sera zero se a intereface C nao for membro
   // Indice valido para a tabela constant pool
   U2 inner_class_info_index;
   // ou sera indice valido da constant_pool
   U2 outer_class_info_index;
   //// Zero se C eh anonimo ou indice da tabela
   U2 inner_class_name_index;
   //Mascara de bits espeficando permissoes de acesso e propriedade
   U2 inner_class_access_flags;
} Inner_classes;

/*
*	@brief Estrutura da tabela de variaveis locais
*/
typedef struct localVariableTable{
   /*a variavel local possui o mesmo valor no intervalo
   [start_pc, start_pc+length] de offsets de code
   esses offsets correspondem a indices validos*/
   U2 start_pc;
   U2 length;
   // indice valido para a tabela k_pool
   //Nome valido de variavel local armazenado como um nome simple
   U2 name_index;/**< tipo da variavel local no programa fonte */
   U2 descriptor_index;/**< indice no array de variaveis locais do fram corrente*/
   U2 index;
} Local_variable_table;


/*
*	@brief Struct LineNumberTable que tem start_pc e line_number
*/
typedef struct LineNumberTable{
   // indice para o array code correspondendo ao codigo que inicia
   // uma nova linha
   U2 start_pc;
   //numero dessa linha no arquivo fonte
   U2 line_number;
} Line_number_table;

/*
*	@brief Estruturas que define atributos gerais.
*/
typedef struct general_attribute{
   U2 attribute_name_index;
   U4 attribute_length;
   /*
	*	@brief Union com valores possiveis dos atributos gerais.
	*/

   union {
	   /*
		*	@brief valor constante de atributo.
		*/
	   struct{
		   U2 constant_value_index;
	   } Constant_value_attribute;

	   /*
		*	@brief Code_attribute contem informacoes sobre codigo.
		*/
	   struct{
		   U2 max_stack;
		   U2 max_locals;
		   U4 code_length;
		   U1 * code;
		   U2 exception_table_length;
		   Exception_table * exception_Table;
		   U2 attributes_count;
		   struct general_attribute *attributes;
	   } Code_attribute;

	   /*
		*	@brief Define execessoes.
		*/
	   struct {
		   U2 number_of_exceptions;
		   U2 * exception_index_table;
	   } Exceptions_attribute;

	   /*
		*	@brief Define inner classes.
		*/
	   struct {
		   U2 number_of_classes;
		   Inner_classes *classes;
	   } Inner_classes_attribute;

	   /*
		*	@brief Define line number table.
		*/
	   struct {
			   U2 line_number_table_length;
			   Line_number_table * table_line_number;
	   } Line_number_table_attribute;

		/*
		*	@brief Define tabela de variaveis locais.
		*/
	   struct {
		   U2 local_variable_table_length;
		   Local_variable_table * table_localVariable;
	   } Local_variable_table_attributes;

	   // source file
	   struct {
			   U2 sourcefile_index;
	   } Source_file_attribute;
	   /*
		*	@brief Atributos pre definidos.
		*/
	   struct {
		   U1              *data;
	   } Value_default;

   } Predef_attributes;
} General_attribute_info;

/*
*	@brief Cada metodo, inclusive o metodo de iniciacao de instancia, classe ou interface, e descrito por uma estrutura method_info.
*/
typedef struct method_info {
   U2 access_flags; /**< Permissoes do metodo*/

   U2 name_index; /**< Indica o nome*/
   // descricao ....
   U2 descriptor_index;

   U2 attributes_count; 	/**< Contador de atributos*/
   //array de info de atributos
   General_attribute_info * attributes; /**< Array de info de atributos*/
} Method_info;

/*
* @brief Cada field eh descrito por field_info.
*/
typedef struct field_info {

   U2 access_flags; /**< Flags de permissao*/

   U2 name_index;	/**< Nome do field*/
   // descritor do field
   U2 descriptor_index; /**< Descritor do field*/
   // numeros de atributos
   U2 attributes_count; /**< Numeros de atributos do campo*/
   // array de attributes
   //U2 attributes_count numero de atributos do campo
   General_attribute_info * attributes; /**< Array de attributes */
} Field_info;

/*
* @brief Finalmente, define-se o arquivo de classe que define todas as estruturas que precisam.
*/

typedef struct Class_file_info {
   U4 magic; /**< Magic - "0xCAFEBABE"*/
   U2 minor_version;	/**< Versao menor suportada*/
   U2 major_version;	/**< Maior versao suportada*/
   U2 constant_pool_count; /**< Quantidade de constant pool que tera*/
   Cp_info *constant_pool; /**< Vetor de cp_info*/
   U2 access_flags; /**< Referente as flags*/
   U2 this_class; /**< Referente a class*/
   U2 super_class; /**< Referente a super class*/
   U2 interfaces_count; /**< Quantidade de interfaces que tera*/
   U2 *interfaces;	/**< Vetor de interfaces*/
   U2 fields_count; /**< Quantidade de campos que tera*/
   Field_info *fields; /**< Vetor de fields */
   U2 methods_count; /**< Quantidade de metodos que tera*/
   Method_info *methods; /**< Vetor de methods */
   U2 attributes_count;  /**< Quantidade de atributos que tera*/
   General_attribute_info *attributes; /**< Vetor de atributos */
} Class_file;
