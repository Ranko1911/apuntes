#include <stdio.h>

#include <iostream>
#include <vector>

int const N = 9;

class Sudoku {
 public:
  int matriu[N][N];

  Sudoku() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        matriu[i][j] = 0;
      }
    }
  }
  ~Sudoku() {}

  bool checkrow(int row, int num) {
    for (int i = 0; i < N; i++) {
      if (matriu[row][i] == num) {
        return false;
      }
    }
    return true;
  }

  bool checkcol(int col, int num) {
    for (int i = 0; i < N; i++) {
      if (matriu[i][col] == num) {
        return false;
      }
    }
    return true;
  }

  bool checkblock(int row, int col, int num) {
    int rowstart = row - row % 3;
    int colstart = col - col % 3;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (matriu[i + rowstart][j + colstart] == num) {
          return false;
        }
      }
    }
    return true;
  }

  bool checkall(int row, int col, int num) {
    return checkrow(row, num) && checkcol(col, num) &&
           checkblock(row, col, num);
  }

  bool find_empty_cell(int &row, int &col) {
    for (row = 0; row < N; row++) {
      for (col = 0; col < N; col++) {
        if (matriu[row][col] == 0) {
          return true;
        }
      }
    }
    return false;
  }

  bool solve() {
    int row, col;
    if (!find_empty_cell(row, col)) {
      return true;
    }
    for (int num = 1; num <= 9; num++) {
      if (checkall(row, col, num)) {
        matriu[row][col] = num;
        if (solve()) {
          return true;
        }
        matriu[row][col] = 0;
      }
    }
    return false;
  }

  void print() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        std::cout << matriu[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }

};

int main() {
  Sudoku sudoku;



  sudoku.print();

  std::cout << "------------------------" << std::endl;

  sudoku.solve();
  
  if (sudoku.solve()) {
    sudoku.print();
  } else {
    std::cout << "No solution exists" << std::endl;
  }
  return 0;
}