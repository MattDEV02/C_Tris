#ifndef __POSITIONS_H_
#define __POSITIONS_H_

#include "../stdutils/main.h"
#include <stdbool.h>


bool isPositionsOccupied(short* positionOccupied, short movesCounter, short position);

bool isValidPosition(short position);


#endif