#include <iostream>

using namespace std;

#define N 4

void solveMazeNaive(int maze[N][N], int curColumn, int curRow) {
    if (curColumn == N-1 && curRow == N-1 && maze[curColumn][curRow] == 1) {
      cout << "Found the way" << endl;
    } else {
      if (maze[curRow][curColumn+1] == 1) {
        solveMazeNaive(maze, curColumn+1, curRow);
      }
      if (maze[curRow+1][curColumn] == 1) {
        solveMazeNaive(maze, curColumn, curRow+1);
      }
    }
}

bool isSafe(int maze[N][N], int row, int col) {
  if (row >= N || col >= N || maze[row][col] == 0) {
    return false;
  }
  return true;
}

bool solveMazeRec(int maze[N][N], int curRow, int curCol) {
  if (curRow == N-1 && curCol == N-1 && maze[curRow][curCol] == 1) {
    return true;
  }

  if (isSafe(maze, curRow, curCol)) {
    if (solveMazeRec(maze, curRow+1, curCol)) {
      return true;
    };
    if (solveMazeRec(maze, curRow, curCol+1)) {
      return true;
    };
  }

  return false;
}

void solveMazeBackTracking(int maze[N][N]) {
  bool isFound = solveMazeRec(maze, 0, 0);
  if (isFound) {
    cout << "Found the way" << endl;
  } else {
    cout << "Not found the way" << endl;
  }
}


int main() {
  int maze[N][N] = {   { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 1, 0 },
                       { 1, 0, 1, 1 } };

  // int curColumn = 0;
  // int curRow = 0;
  // solveMazeNaive(maze, curColumn, curRow);
  solveMazeBackTracking(maze);
  return 1;
}
