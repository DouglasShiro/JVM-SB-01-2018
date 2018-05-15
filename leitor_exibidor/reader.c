#include "reader.h"

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

// class_file* read_class_file(FILE* fp_class) {
// 	//Criar a estrutura que vai armazenar as informacoes do .class
// 	Class_file*	class_file = (Class_file *) malloc(sizeof(Class_file));

// 	if (class_file == NULL) {
// 		fputs ("ERROR: Memoria insuficiente para alocar arquivo...", stderr);
// 		exit (2);
// 	}
// 	// ler Magic

// 	// ler versoes relatadas

// 	// ler pool de constantes

// 	// ler as flas de acesso

// 	// ler o this (classe)

// 	// ler a classe mae (super)

// 	// ler as interfaces

// 	// ler os campos

// 	// ler os metodos

// 	// ler os Atributos

// 	// verificar EOF

// 	return class_file;
// }
