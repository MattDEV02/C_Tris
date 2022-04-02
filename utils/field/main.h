#ifndef __FIELD_H_
#define __FIELD_H_

#include <stdbool.h>
#include "../stdutils/main.h"
#include "../positions/main.h"
#include "../pieces/main.h"


void initField(Field field);

void printField(Field field);

bool hasWin(Field field);

bool playerTurn(Field field, unsigned short player, unsigned short movesCounter);


#endif
