// Pavan Sai Ram Korumilli
// CSS 342 Fall
// Purpose: This programs is to find the path through Maze, using recursion and
// backtracking.
//

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H

#include <ostream>

using namespace std;

enum CELL { CLEAR, WALL, PATH, VISITED };
// percondition: it creates Maze.
// postcondition: it has all the property of maze.
class Maze {
  //prints the maze
  friend ostream &operator<<(ostream &Out, const Maze &Maze);

private:
  // creates a MAX size of Maze
  const static int MAX_SIZE = 100;
  // Field array is ppartially filled with max size of 100;
  char Field[MAX_SIZE][MAX_SIZE];
  // Width and Height of the Maze.
  int Width, Height;
  // declaring Exit row and column of Maze
  int ExitRow, ExitColumn;

public:
  // Parameters takes in file
  // Precondition: checks the file if there
  // PostCondition: Sets the width and height to Maze.
  explicit Maze(const string &FileName);
  // Parameters: Takes int row and int col
  // Precondition: checks for space in Maze
  // Postcondition: row and col will equal to space;
  // Returns the field of row and col.
  bool isClear(int Row, int Col) const;
  // Parameters: Takes int row and int col
  // Precondition: places array field with row and col to *
  // Postcondition: row and col will equal to *;
  // Returns the field of row and col.
  void markAsPath(int Row, int Col);
  // Parameters: Takes int row and int col
  // Precondition: places array field with row and col to +
  // Postcondition: row and col will equal to +;
  // Returns the field of row and col.
  void markAsVisited(int Row, int Col);
  // Parameters: none
  // Precondition: sets getexitRow to exitrow which is parivate variable.
  // PostConditoin: returns exitrow
  // returns int value.
  int getExitRow() const;
  // Parameters: none
  // Precondition: sets getexitRow to exitcolumn which is parivate variable.
  // PostConditoin: returns exitcolumn
  // returns int value.
  int getExitColumn() const;
};

#endif // ASS3_MAZE_H