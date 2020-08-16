#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string board[3][3] = {{" ", " ", " "},{" ", " ", " "},{" ", " ", " "}};
string currentPlayer = "x";

bool isnumeric(string& s) {
  string::const_iterator it = s.begin();
  while (it != s.end() && std::isdigit(*it)) ++it;
  return !s.empty() && it == s.end();

}

void printBoard() {
  cout << "\x1B[2J\x1B[H";
  for (int i = 0; i < 3; i++) {
    string line = " " + board[i][0] + " | " + board[i][1] + " | " + board[i][2];
    cout << line << endl;
    if (i < 2) {
      cout << "___ ___ ___ " << endl;
    }
  }
}

bool equalArray(string a[]) {
  for (int i = 0; i < 3; i++) {
    if (a[i] != a[0]) {
      return false;
    }
  }
  return true;
}

string gameOver() {
  for (int i = 0; i < 3; i++) {
    //horizontal
    if ((equalArray(board[i])) && (board[i][0] != " ")) {
      return board[i][0];
    }
    //vertical
    string vertBoard[3];
    for (int j = 0; j < 3; j++) vertBoard[i] = board[j][i];

    if ((equalArray(vertBoard)) && (vertBoard[0] != " ")) {
      return vertBoard[0];
    }
  }

  string center = board[1][1];

  if (center != " ") {
    //diag
    if ((board[0][0] == center && center == board[2][2]) || (board[0][2] == center && center == board[2][0])) {
      return center;
    }
  }
  return " ";
}

bool boardFull() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == " ") return false;
    }
  }
  return true;
}

int main() {

  printBoard();

  while (gameOver() == " ") {
    if (boardFull()) {
      cout << "cat's Game" << endl;
      break;
    }

    string x;
    string y;

    cout << "type x of your move: ";

    cin >> x;

    cout << "type y of your move: ";

    cin >> y;
    printBoard();

    if (x.size() == 1 && y.size() == 1) {
      if (isnumeric(x) && isnumeric(y)) {
        int xNum = atoi(x.c_str());
        int yNum = atoi(y.c_str());
        if (xNum >= 0 && xNum < 3 && yNum >= 0 && yNum < 3) {
          if (board[yNum][xNum] == " ") {
            board[yNum][xNum] = currentPlayer;
            currentPlayer = (currentPlayer == "x") ? "o" : "x";
            printBoard();
          } else {
            cout << "this spot is already taken" << endl;
          }
        } else {
          cout << "the inputs must follow these constraints: 0 <= input < 3" << endl;
        }
      } else {
        cout << "at least one of the inputs were not integers" << endl;
      }
    } else {
      cout << "your input was either too long or short, make sure it has correct formatting\n ex ->1 2" << endl;
    }
  }
  string winner = gameOver();
  if (winner != " ")
    cout << winner << " wins!" << endl;

  return 0;
}
