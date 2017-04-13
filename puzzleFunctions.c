#include <stdbool.h>
#include <stdio.h>

int * importPuzzle(char *path);
void printPuzzle(int *puzzle);
bool verifyPuzzle(int * puzzle);
bool verifyPuzzleRow(int * puzzle);
bool verifyPuzzleCol(int * puzzle);
bool verifyPuzzleBox(int * puzzle);


int * importPuzzle(char *path) {
  char c;
  int p;
  static int puzzle[80];
  FILE *file;

  file = fopen(path, "r");
  int i = 0;
  if(file) {
    while ((c = getc(file)) != EOF) {
      if (c != 44 && c != 10) { // newline and comma
        p = c - '0';
        puzzle[i]=p;
        i++;
      }
    }
    fclose(file);
  }

  return puzzle;
}

void printPuzzle(int *puzzle) {
	int i = 0;
	while(i < 81) {
		printf("%d ", puzzle[i]);
		i++;
		if (i%9 == 0)
			printf("\n");
	}
}

bool verifyPuzzle(int * puzzle) {
	if(verifyPuzzleRow(puzzle)) {
		if(verifyPuzzleCol(puzzle)) {
			if(verifyPuzzleBox(puzzle)) {
				return true;
			}
		}
	}
	return false;
}

bool verifyPuzzleRow(int * puzzle) {
	int check[9] = { 0 };
	int j;
	int i = 0;
	while (i < 81) {
		if (puzzle[i] == 0) {
			return false;
		} else if (check[puzzle[i]-1] == 0) {
			check[puzzle[i]-1] = 1;

		} else {
			return false;
		}
		i++;
		if (i%9==0) {
			j = 0;
			while (j < 9) {
				check[j] = 0;
				j++;
			}
		}
	}
	return true;
}

bool verifyPuzzleCol(int * puzzle) {
	int check[9] = { 0 };
	int j;
	int i = 0;
	int k = 0;
	while (k < 9) {
		if (puzzle[i*9+k] == 0) {
			return false;
		} else if (check[puzzle[i*9+k]-1] == 0) {
			check[puzzle[i*9+k]-1] = 1;

		} else {
			return false;
		}
		i++;
		if (i%9==0) {
			i=0;
			k++;
			j = 0;
			while (j < 9) {
				check[j] = 0;
				j++;
			}
		}
	}
	return true;
}

bool verifyPuzzleBox(int * puzzle) {
	int check[9] = { 0 };
	int j, k = 0;
	int i = 0;
	while (i < 81) {
		if (puzzle[((i/3)%3)*9+(i%3)+k] == 0) {
			return false;
		} else if (check[puzzle[((i/3)%3)*9+(i%3)+k]-1] == 0) {
			check[puzzle[((i/3)%3)*9+(i%3)+k]-1] = 1;
		} else {
			return false;
		}
		i++;
		if (i%9==0) {
			k+=3;
			if (i%27==0) {
				k+=18;
			}

			j = 0;
			while (j < 9) {
				check[j] = 0;
				j++;
			}
		}
	}
	return true;
}
