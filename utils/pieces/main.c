#include "main.h"


const char getPiece(unsigned short player) {
	return player == 0 ? 'X' : 'O';
}

void pieceInsert(Field field, const char piece, short position) {
    switch(position) {  
		case 1: {
            field[0][0] = piece;
            break;
        }
		case 2: {
            field[0][1] = piece;
            break;
        }
		case 3: {
            field[0][2] = piece;
            break;
        }
		case 4: {
            field[1][0] = piece;
            break;
        }
		case 5: {
            field[1][1] = piece;
		    break;
        }
		case 6: {
            field[1][2] = piece;
		    break;
        }
		case 7: {
            field[2][0] = piece;
		    break;
        }
		case 8: {
            field[2][1] = piece;
		    break;
        }
		case 9: {
            field[2][2] = piece;
		    break;
        }
		default: {
			printf("\nPosition %i non valida!\n", position);
			exit(EXIT_FAILURE);	
			break;
		}
	}
}
