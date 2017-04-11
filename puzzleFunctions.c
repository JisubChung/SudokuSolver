#include <stdio.h>

char * importPuzzle(char *path);
void printPuzzle(char *puzzle);

char * importPuzzle(char *path) {
  int c;
  static char puzzle[80];
  FILE *file;

  file = fopen(path, "r");
  int i = 0;
  if(file) {
    while ((c = getc(file)) != EOF) {
      if (c != 44 && c != 10) {
        puzzle[i]=c;
        i++;
      }
    }
    fclose(file);
  }

  return puzzle;
}

void printPuzzle(char *puzzle) {
	int i = 0;
	while(i < 81) {
		printf("%c ", puzzle[i]);
		i++;
		if (i%9 == 0)
			printf("\n");
	}
}
