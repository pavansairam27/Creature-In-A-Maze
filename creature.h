//
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include "maze.h"
#include <ostream>

class Creature {
public:
  // Parameters: ostream of out and the creature
  // Precondition: prints the row and col of creature.
  // Postcondition: prints in (row,col);
  // return the out.
  friend ostream &operator<<(ostream &Out, const Creature &Creature);

private:
  // private variable row
  int Row;
  // private variable col
  int Col;
  // private variable Path.
  string Path;

public:
  // Parameters: Row and col of creature object;
  // PreConditon: sets private varialbe to creatures parameters
  // PostConditon: private row and col equals to creatures row and col and sets
  // path.
  Creature(int Row, int Col);

  // Default constructor.
  Creature();

  // Parameters: object Maze reference;
  // PreCondition: calls all the gonorth, goeast, gowest, gonorth functions.
  // PostCOndtion: checks to see if they are at exit else calls gonorth, goeast,
  // gowest, gonorth functions. Returns Path, where which does the Maze take.
  string solve(Maze &Maze);

  // Parameters: object Maze reference.
  // PreCondition: checks to see if Object maze exit row and col equal creatures
  // row and col PostConditon: Object maze exit row and col to creatures row and
  // col return bool value.
  bool atExit(const Maze &Maze) const;

  // Parameters: Object Maze reference
  // Preconditon: checks to see if the path is clear than gos north
  // PostCondition: moves north if clear,else checks all the directions and
  // backtracks to place where it started
  // returns String of the moves of going north.
  string goNorth(Maze &Maze);

  // Parameters: Object Maze reference
  // Preconditon: checks to see if the path is clear than gos South by
  // recursively.
  // PostCondition: moves south if clear,else checks all the directions and
  // backtracks to place where it started
  // returns String of the moves of going south.
  string goSouth(Maze &Maze);

  // Parameters: Object Maze reference
  // Preconditon: checks to see if the path is clear than gos east by
  // recursively.
  // PostCondition: moves east if clear,else checks all the directions and
  // backtracks to place where it started.
  // returns String of the moves of going east.
  string goEast(Maze &Maze);

  // Parameters: Object Maze reference
  // Preconditon: checks to see if the path is clear than gos west by
  // recursively.
  // PostCondition: moves west if clear,else checks all the directions and
  // backtracks to place where it started
  // returns String of the moves of going west.
  string goWest(Maze &Maze);
};

#endif // ASS3_CREATURE_H