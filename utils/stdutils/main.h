#ifndef __STDUTILS_H_
#define __STDUTILS_H_

#include <stdio.h>
#include <stdlib.h>

#define N 3


typedef char** Field;

Field fieldCalloc();

void fieldDealloc(Field field);


#endif