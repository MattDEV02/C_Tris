#include "main.h"


Field fieldCalloc() {
	Field field = calloc(N, sizeof(char*));
	if(field != NULL) {
		unsigned short row = 0;
		for(; row < N; row++) 
			field[row] = calloc(N, sizeof(char));
	} else {
		printf("\nErrore: Memoria heap per il campo non allocata.\n");
		exit(EXIT_FAILURE);
	}
	return field;
}

void fieldDealloc(Field field) {
	unsigned short row = 0;
	for(; row < N; row++)
		free(field[row]);
	free(field);
}
