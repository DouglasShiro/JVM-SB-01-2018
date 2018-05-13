#include <stdio.h>
#include <stdlib.h>
#include "leitor.h"
#include "exibidor.h"

int main(int argc, char* argv[]) {
	FILE * fp_class;
	long lSize;
    size_t result;

	if (argc == 2) {
		char* class_filename = argv[1];

	    fp_class = fopen ( class_filename , "rb" );
	    if (fp_class == NULL) {
			fputs ("ERROR: falha na abertura do arquivo",stderr);
			exit (1);
		}

		printf("Carga do arquivo ");
		printf("%s", class_filename);
		printf("\n");

		Class_file* fp_class_info = read_class_file(fp_class);


	    /* the whole file is now loaded in the memory buffer. */
	} else {
		printf("\nNumero de argumentos invalido para leitorExibidor");
		exit(EXIT_FAILURE);
	}

    // terminate
    fclose (fp_class);
    free (buffer);
    return 0;
}
