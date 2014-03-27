SudokuSolver
============

Solves a given Sudoku puzzle

Currently the sudoku puzzle is set as "puzzle.txt"
As standard, the number 1-9 are used to complete the puzzle
For blank squares, the number 0 is put in its place

The plan:

1. Make an Options aNd Constraints vector for each sudoku_cell
  a. In vector_cells 1-x (x being the length of sudoku board) have a boolean
    - true: Represents a possible answer for this sudoku_cell
    - false: Represents an impossible answer for this sudoku_cell
  b. In vector_cell[0] will be.... ?
2. When program reaches the first unsolved sudoku_cell
  a. Look for any constants in the Box/Row/Column
  b. For any constants found in the BRC, turn false that vector_cell from the respective ONC_vector
3. For each sudoku_cell that had a vector_cell changed to false,
  a. If there is only one true vector_cell, then set sudoku_cell to that value
  b. If there is any condition that is false in all other vector_cells, then set sudoku_cell to that value with a true vector_cell
  c. In the case that a sudoku_cell has been filled out, repeat proccess
