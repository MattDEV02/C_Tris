#include "main.h"


bool isPositionsOccupied(short* positionOccupied, short movesCounter, short position) {
    bool occupied = false;
	if(movesCounter <= 0)
        occupied = false;
    else 
        occupied = positionOccupied[movesCounter - 1] == position || isPositionsOccupied(positionOccupied, movesCounter - 1, position);
	return occupied; 
}

bool isValidPosition(short position) {
    return position >= 1 && position <= 9;
}