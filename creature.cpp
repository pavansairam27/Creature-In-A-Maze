//
//

#include "creature.h"

// Parameters: ostream of out and the creature
// Precondition: prints the row and col of creature.
// Postcondition: prints in (row,col);
// return the out.
std::ostream &operator<<(std::ostream &Out, const Creature &Creature) {
  Out << "(" << Creature.Row << "," << Creature.Col << ")";
  return Out;
}

// Default constructor.
Creature::Creature() = default;
// Parameters: Row and col of creature object;
// PreConditon: sets private varialbe to creatures parameters
// PostConditon: private row and col equals to creatures row and col and sets
// path.
Creature::Creature(int Row, int Col) : Row(Row), Col(Col) { Path = " "; }

// Parameters: object Maze reference.
// PreCondition: checks to see if Object maze exit row and col equal creatures
// row and col PostConditon: Object maze exit row and col to creatures row and
// col return bool value.
bool Creature::atExit(const Maze &Maze) const {
  if (Maze.getExitRow() == this->Row && Maze.getExitColumn() == this->Col) {
    return true;
  }
  return false;
}

// Parameters: object Maze reference;
// PreCondition: calls all the gonorth, goeast, gowest, gonorth functions.
// PostCOndtion: checks to see if they are at exit else calls gonorth, goeast,
// gowest, gonorth functions. Returns Path, where which does the Maze take.
string Creature::solve(Maze &Maze) {
  Maze.markAsPath(Row, Col);
  if (atExit(Maze)) {

    return "Found the exit";
  } else {
    Path = goNorth(Maze);
    if (Path == "X") {
      Path = goSouth(Maze);

      if (Path == "X") {
        Path = goEast(Maze);

        if (Path == "X") {
          Path = goWest(Maze);
          if (Path == "X") {
            return " No exit";
          }
        }
      }
    }
  }
  return Path;
}

// Parameters: Object Maze reference
// Preconditon: checks to see if the path is clear than gos north
// PostCondition: moves north if clear,else checks all the directions and
// backtracks to place where it started
// returns String of the moves of going north.
string Creature::goNorth(Maze &Maze) {
  // local variable.
  string newPath;
  if (Maze.isClear(Row - 1, Col)) {
    // The Maze moves up
    Row -= 1;
    Maze.markAsPath(Row, Col);
    if (atExit(Maze)) {
      return "N";
    } else {
      // calls recursively goNorth.
      newPath = goNorth(Maze);
      if (newPath == "X") {
        newPath = goWest(Maze);

        if (newPath == "X") {
          newPath = goEast(Maze);

          if (newPath == "X") {
            Maze.markAsVisited(Row, Col);
            // BackTracks to place it started
            Row += 1;
            return newPath;
          }
        }
      }
    }
    // adds direction N to path.
    return "N" + newPath;
  } else {
    newPath = "X";
  }

  return newPath;
}

// Parameters: Object Maze reference
// Preconditon: checks to see if the path is clear than gos west by recursively.
// PostCondition: moves west if clear,else checks all the directions and
// backtracks to place where it started
// returns String of the moves of going west.
string Creature::goWest(Maze &Maze) {
  string newPath;
  if (Maze.isClear(Row, Col - 1)) {
    Col -= 1;
    Maze.markAsPath(Row, Col);
    if (atExit(Maze)) {
      return "W";
    } else {
      newPath = goWest(Maze);
      if (newPath == "X") {
        newPath = goNorth(Maze);

        if (newPath == "X") {
          newPath = goSouth(Maze);

          if (newPath == "X") {
            Maze.markAsVisited(Row, Col);
            // BackTracks to place it started
            Col += 1;
            return newPath;
          }
        }
      }
    }
    // adds direction W to path.
    return "W" + newPath;
  } else {
    newPath = "X";
  }

  return newPath;
}

// Parameters: Object Maze reference
// Preconditon: checks to see if the path is clear than gos east by recursively.
// PostCondition: moves east if clear,else checks all the directions and
// backtracks to place where it started.
// returns String of the moves of going east.
string Creature::goEast(Maze &Maze) {
  string newPath;
  if (Maze.isClear(Row, Col + 1)) {
    Col += 1;
    Maze.markAsPath(Row, Col);
    if (atExit(Maze)) {
      return "E";
    } else {
      newPath = goEast(Maze);
      if (newPath == "X") {
        newPath = goNorth(Maze);

        if (newPath == "X") {
          newPath = goSouth(Maze);

          if (newPath == "X") {
            Maze.markAsVisited(Row, Col);
            // BackTracks to place it started
            Col -= 1;
            return newPath;
          }
        }
      }
    }
    // adds direction E to path.
    return "E" + newPath;
  } else {
    newPath = "X";
  }
  return newPath;
}

// Parameters: Object Maze reference
// Preconditon: checks to see if the path is clear than gos South by
// recursively.
// PostCondition: moves south if clear,else checks all the directions and
// backtracks to place where it started
// returns String of the moves of going south.
string Creature::goSouth(Maze &Maze) {
  string newPath;
  if (Maze.isClear(Row + 1, Col)) {
    Row += 1;
    // marks as path by *
    Maze.markAsPath(Row, Col);

    if (atExit(Maze)) {
      return "S";
    } else {
      newPath = goSouth(Maze);
      if (newPath == "X") {
        newPath = goWest(Maze);

        if (newPath == "X") {
          newPath = goEast(Maze);

          if (newPath == "X") {
            Maze.markAsVisited(Row, Col);
            // BackTracks to place it started
            Row -= 1;
            return newPath;
          }
        }
      }
    }
    ////adds direction S to path.
    return "S" + newPath;
  } else {
    newPath = "X";
  }
  return newPath;
}