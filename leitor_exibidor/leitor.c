//Funcao para ler apenas um byte (U1) do arquivo .class
U1 read_U1(FILE *file) {
	// variavel para conter o valor que sera retornado do arquivo "arq".
	U1 valor;
	int per;
	per = fread(&valor, sizeof(U1), 1, file);
	if(!per) {
		printf("Erro. Nao foi possivel ler. -> ClassFormatError\n");
		exit(EXIT_FAILURE);
	}

	return valor;
}
z
//Funcao para ler U2 -> Funcao para ler apenas um byte (U2) do arquivo .class
U2 read_U2(FILE *file) {
	// variavel para conter o valor que sera retornado do arquivo "arq".
	U2 valor;
	// variavel para guardar os bits de maior ordem e os de menores
	U1 lsb_U1, msb_U1;
	// lendo os bits de forma mais separada.
	msb_U1 = read_U1(file);
	lsb_U1 = read_U1(file);

	// concatenandos os msb e lsb...
	// de forma que [msblsb]
	valor = (msb_U1 << 8) | lsb_U1;
	return valor;
}

//Funcao para ler U5 -> Funcao para ler apenas um byte (U4) do arquivo .class
U4 read_U4(FILE *file) {
	// variavel para conter o valor que sera retornado do arquivo "arq".
	U4 valor;
	// variavel para guardar os bits de maior ordem, 2, 3  e os de menores
	U1 byte3, byte2, byte1, byte0;
	// lendo os bits de forma mais separada.
	byte3 = read_U1(file);
	byte2 = read_U1(file);
	byte1 = read_U1(file);
	byte0 = read_U1(file);

	// de forma que [msblsb]
	// concatenandos os msb e lsb...
	valor = ((byte3 << 8) | byte2);
	valor = ((valor << 8) | byte1);
	valor = ((valor << 8) | byte0);
	return valor;
}


class_file* read_class_file(FILE* fp_class) {
	//Criar a estrutura que vai armazenar as informacoes do .class
	Class_file*	class_file = (Class_file *) malloc(sizeof(Class_file));

	if (class_file == NULL) {
		fputs ("ERROR: Memoria insuficiente para alocar arquivo...", stderr);
		exit (2);
	}
	// ler Magic

	// ler versoes relatadas

	// ler pool de constantes

	// ler as flas de acesso

	// ler o this (classe)

	// ler a classe mae (super)

	// ler as interfaces

	// ler os campos

	// ler os metodos

	// ler os Atributos

	// verificar EOF

	return class_file;
}
