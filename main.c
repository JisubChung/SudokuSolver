#include "puzzleFunctions.h"
#include "algorithm.h"
#include <time.h>
#include <stdio.h>
#include <stdbool.h>


int main() {
	char *path = "puzzle.txt";
	int *puzzle = importPuzzle(path);

	printPuzzle(puzzle);

	clock_t start = clock(), diff;
	solve(puzzle);
	diff=clock()-start;

	int msec=diff*1000/CLOCKS_PER_SEC;

	if(verifyPuzzle(puzzle)) {
		printf("Time taken %d seconds %d milliseconds\n", msec/1000, msec%1000);
	} else {
		printf("Not correctly solved\n");
	}

	return 0;
}
