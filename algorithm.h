#ifndef ALGORITHM_H_
#define ALGORITHM_H_
#include <stdbool.h>

bool tryPut(int row, int col, int num);
bool canPutRow(int row, int col, int num);
bool canPutCol(int row, int col, int num);
bool canPutBox(int row, int col, int num);

#endif
