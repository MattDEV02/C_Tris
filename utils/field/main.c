#include "main.h"


void initField(Field field) {
    unsigned short
        i = 0,
        j = 0,
        k = 0;
    for(i = 0; i < N; i++) {
        for(j = 0; j < N; j++) {
            field[i][j] = (k + 1) + '0';
            k++;
        }
    }
}

void printField(Field field) { 
	unsigned short
		i = 0,
		j = 0;
	printf("\n \n");
	for(i = 0; i < N; i++) {
       for(j = 0; j < N; j++) {
			if(j == 0)
				printf("\t \t \t");
			printf("| %c | ", field[i][j]);
	   }
       printf("\n \n");
    }
}

bool hasWin(Field field) {
    return (
		(
		// vittorie per riga
			(field[0][0] == field[0][1] && field[0][1] == field[0][2]) ||
			(field[1][0] == field[1][1] && field[1][1] == field[1][2]) ||
			(field[2][0] == field[2][1] && field[2][1] == field[2][2])
		) || (
		// vittorie per colonna
			(field[0][0] == field[1][0] && field[1][0] == field[2][0]) ||
			(field[0][1] == field[1][1] && field[1][1] == field[2][1]) ||
			(field[0][2] == field[1][2] && field[1][2] == field[2][2])
		) || (
		// vittorie per diagonale
			(field[0][0] == field[1][1] && field[1][1] == field[2][2]) ||
			(field[0][2] == field[1][1] && field[1][1] == field[2][0])
		)
	);
}

bool playerTurn(Field field, unsigned short player, unsigned short movesCounter) {
    static short positionsOccupied[N * N];
	short position = 0;
    const char piece = getPiece(player);
	do {
		printf("\nGiocatore numero %i (%c) scegli una posizione da 1 a 9: \n", player + 1, getPiece(player));
		printField(field);
        printf("\nPosizione: ");
		scanf("%hu", &(position));
		if(!isValidPosition(position))
			printf("\nLe posizioni vanno da 1 a 9 non %i, riprova.\n", position);
		else if(isPositionsOccupied(positionsOccupied, movesCounter, position)) // check se l'i-esima position è occupata
			printf("\nLa posizione %i e' occupata riprova inserendone una non occupata.\n", position);
	} while(!isValidPosition(position) || isPositionsOccupied(positionsOccupied, movesCounter, position));
	pieceInsert(field, piece, position);
	positionsOccupied[movesCounter] = position;
	printf("\nMossa numero %i effettuta da parte del giocatore numero %i.\n \n", movesCounter + 1, player + 1);
	return hasWin(field);
}
