#include "block.h"
#include "map.h"
#ifndef CLEANCHECKER_H
#define CLEANCHECKER_H

void cleanBlock(Block map[7][7], Direction direction);
bool isSameColor(Block* block_1, Block* block_2);


#endif
