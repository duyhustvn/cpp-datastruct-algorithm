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
  // check if column have queen
  for (int i = 0; i < row; i++) {
    if (chessBoard[i][col] == 1) {
      return false;
    }
  }

  // check for left diagonal
  for (int i = row, j = col; i >=0 && j >= 0; i--, j--) {
    if (chessBoard[i][j] == 1) {
      return false;
    }
  }

  // check for right diagonal
  for (int i = row, j = col; i >= 0 && j >= 0 && j < N; i--, j++) {
    if (chessBoard[i][j] == 1) {
      return false;
    }
  }
  return true;
}

bool solveNQueenRec(int chessBoard[N][N], int curRow) {
  if (curRow == N) {
    return true;
  }

  for (int i = 0; i < N; i++) {
    if (isSafe(chessBoard, curRow, i)) {
      chessBoard[curRow][i] = 1;
      cout << "curRow: " << curRow << " curCol: " << i << endl;
      printChessBoard(chessBoard);
      if (solveNQueenRec(chessBoard, curRow+1)) {
        return true;
      }
      chessBoard[curRow][i] = 0;
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
  resetChessBoard(chessBoard);
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
