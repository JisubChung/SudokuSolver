#include "puzzleFunctions.h"
#include "algorithm.h"

int main() {
	char *path = "puzzle.txt";
	char *puzzle = importPuzzle(path);


	printPuzzle(puzzle);

	return 0;
}
