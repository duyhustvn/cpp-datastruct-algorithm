#include <iostream>

using namespace std;

#define N 4

void printChessBoard(int chessBoard[N][N]);

void resetChessBoard(int chessBoard[N][N]) {
  for (int i = 0; i < N; i++) {
     for (int j = 0; j < N; j++) {
       chessBoard[i][j] = 0;
       // cout << chessBoard[i][j] << " ";
     }
   }
}

bool isSafe(int chessBoard[N][N], int row, int col) {
  return (chessBoard[row][col] != 2);
}

void setUnavailableSlot(int chessBoard[N][N], int row, int col) {
  // set for row
  for (int i = 0; i < N; i++) {
    if (i != col) {
      chessBoard[row][i] = 2;
    }
  }

  // set for column
  for (int i = 0; i < N; i++) {
    if (i != row) {
      chessBoard[i][col] = 2;

      int leftSmalTriCol = col - (i-row);
      if (0 <= leftSmalTriCol && leftSmalTriCol < N) {
        chessBoard[i][leftSmalTriCol] = 2;
      }

      int rightSmallTriCol = col + (i-row);
      if (0 <= rightSmallTriCol && rightSmallTriCol < N) {
        chessBoard[i][rightSmallTriCol] = 2;
      }
    }
  }

  cout << "row: " << row << " col: " << col << endl;
  printChessBoard(chessBoard);
  cout << endl << endl;
}

bool solveNQueenRec(int chessBoard[N][N], int curRow) {
  if (curRow == N-1) {
    for (int i = 0; i < N; i++) {
      if (chessBoard[curRow][i] == 0) {
        chessBoard[curRow][i] = 1;
        return true;
      }
    }
    return false;
  }
  for (int i = 0; i < N; i++) {
    if (curRow == 0) {
      resetChessBoard(chessBoard);
    }

    if (isSafe(chessBoard, curRow, i)) {
      chessBoard[curRow][i] = 1;
      setUnavailableSlot(chessBoard, curRow, i);
      if (solveNQueenRec(chessBoard, curRow+1)) {
        return true;
      }
    }
  }
  return false;
}

void printChessBoard(int chessBoard[N][N]) {
  for (int i = 0; i < N; i++) {
     for (int j = 0; j < N; j++) {
       cout << chessBoard[i][j] << " ";
     }
     cout << endl;
   }
}

bool solveNQueen() {
  int chessBoard[N][N];
  bool isPossible = solveNQueenRec(chessBoard, 0);
  cout << "Final result: " << endl;
  printChessBoard(chessBoard);

  return isPossible;
}

int main() {
  if (solveNQueen()) {
    cout << "Possible" << endl;
  } else {
    cout << "Not Possible" << endl;
  }
  return 0;
}
