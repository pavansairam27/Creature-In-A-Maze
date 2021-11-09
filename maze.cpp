//
//

#include "maze.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
//prints the maze
ostream &operator<<(ostream &Out, const Maze &Maze) {
  for (int Row = 0; Row < Maze.Height; ++Row) {
    for (int Col = 0; Col < Maze.Width; ++Col) {
      Out << Maze.Field[Row][Col];
    }
    Out << endl;
  }
  Out << endl;
  return Out;
}

// For Clion, need the following line in CMakeLists.txt so maze.txt is found
// at the same location as the cpp files
// # need to load data files from current directory as cpp files
// set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

// Parameters takes in file
// Precondition: checks the file if there
// PostCondition: Sets the width and height to Maze.
Maze::Maze(const string &FileName) {
  ifstream InFile;
  InFile.open(FileName);
  if (!InFile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  InFile >> Width >> Height;
  InFile >> ExitRow >> ExitColumn;
  string Str;
  getline(InFile, Str);
  for (int Row = 0; Row < Height; ++Row) {
    for (int Col = 0; Col < Width; ++Col) {
      InFile.get(Field[Row][Col]);
      // cout << Row << ", " << col << ": " << field[Row][col] << endl;
    }
    getline(InFile, Str);
  }
}
// Parameters: none
// Precondition: sets getexitRow to exitrow which is parivate variable.
// PostConditoin: returns exitrow
// returns int value.
int Maze::getExitRow() const { return ExitRow; }
// Parameters: none
// Precondition: sets getexitRow to exitcolumn which is parivate variable.
// PostConditoin: returns exitcolumn
// returns int value.
int Maze::getExitColumn() const { return ExitColumn; }

// Parameters: Takes int row and int col
// Precondition: checks for space in Maze
// Postcondition: row and col will equal to space;
// Returns the field of row and col.
bool Maze::isClear(int Row, int Col) const { return Field[Row][Col] == ' '; }

// Parameters: Takes int row and int col
// Precondition: places array field with row and col to *
// Postcondition: row and col will equal to *;
// Returns the field of row and col.
void Maze::markAsPath(int Row, int Col) { Field[Row][Col] = '*'; }

// Parameters: Takes int row and int col
// Precondition: places array field with row and col to +
// Postcondition: row and col will equal to +;
// Returns the field of row and col.
void Maze::markAsVisited(int Row, int Col) { Field[Row][Col] = '+'; }