#include <iostream>
#include <string>

using namespace std;

void clear() {
  //clear terminal
}

void printBoard(string board[3][3]) {
  for (int i = 0; i < 3; i++) {
    string line = " " + board[i][0] + " | " + board[i][1] + " | " + board[i][2];
    cout << line << endl;
    if (i < 2) {
      cout << "___ ___ ___ " << endl;
    }
  }
}

int main() {
  string board[3][3] = {{" ", " ", " "},{" ", " ", " "},{" ", " ", " "}};

  printBoard(board);

  return 0;
}
