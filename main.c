#include "utils/stdutils/main.h"
#include "utils/positions/main.h"  
#include "utils/pieces/main.h"   
#include "utils/field/main.h"


int main(void) {
    unsigned short 
        movesCounter = 0,
        player = 0,
        winner = 0;
    bool win = false;
    Field field = fieldCalloc();
    initField(field);
	while((player < 2) && (!win && movesCounter < 9)) {
		win = playerTurn(field, player, &(movesCounter));
        winner = player + 1;
		if(player == 0)
            player++;
        else 
            player = 0;
	}
    printField(field);
    fieldDealloc(field);
	if(movesCounter >= 9 && !win)   // condizione di pareggio
		printf("\n \nPareggio tra giocatore 1 e giocatore 2.\n \n");
	else if(win)   
		printf("\n \nHa vinto il giocatore numero %i in %i mosse.\n \n", winner, movesCounter);
	return EXIT_SUCCESS;   
}
