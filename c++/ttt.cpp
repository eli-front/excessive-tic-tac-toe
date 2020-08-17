// Copyright (c) 2020 Eli B. Front. All rights reserved.

#include <stdlib.h>
#include <iostream>
#include <string>

// Checks if a string is a number
bool isnumeric(const std::string& s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && isdigit(*it)) ++it;
  return !s.empty() && it == s.end();
}

// Prints the current board and clears the previous board
void printBoard(std::string board[3][3]) {
  std::cout << "\x1B[2J\x1B[H";
  for (int i = 0; i < 3; i++) {
    std::string line =
      " " + board[i][0] + " | " + board[i][1] + " | " + board[i][2];
    std::cout << line << std::endl;
    if (i < 2) {
      std::cout << "___ ___ ___ " << std::endl;
    }
  }
}

// Checks if all elements in an array are equal
bool equalArray(std::string a[]) {
  return (a[0] == a[1] && a[1] == a[2]);
}

// If there is a winner it will return that player
std::string gameOver(std::string board[3][3]) {
  for (int i = 0; i < 3; i++) {
    // horizontal
    if ((equalArray(board[i])) && (board[i][0] != " ")) {
      return board[i][0];
    }
    // vertical
    std::string vertBoard[3];
    for (int j = 0; j < 3; j++) vertBoard[j] = board[j][i];

    if ((equalArray(vertBoard)) && (vertBoard[0] != " ")) {
      return vertBoard[0];
    }
  }

  std::string center = board[1][1];
  // diagonal
  if (center != " ") {
    const bool leftRight = (board[0][0] == center && center == board[2][2]);
    const bool rightLeft = (board[0][2] == center && center == board[2][0]);
    if (leftRight || rightLeft) {
      return center;
    }
  }
  // The game is not over
  return " ";
}

// Checks if the board is full
bool boardFull(std::string board[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == " ") return false;
    }
  }
  return true;
}

int main() {
  std::string board[3][3] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
  std::string currentPlayer = "x";

  printBoard(board);

  std::string output = "";
  while (gameOver(board) == " ") {
    if (boardFull(board)) {
      std::cout << "cat's Game" << std::endl;
      break;
    }

    std::string x;
    std::string y;

    std::cout << "type x of your move: ";

    std::cin >> x;

    std::cout << "type y of your move: ";

    std::cin >> y;
    printBoard(board);
    // Checks the size of the inputs (should be 1)
    if (x.size() == 1 && y.size() == 1) {
      // Checks if the inputs are numbers
      if (isnumeric(x) && isnumeric(y)) {
        // Converts the inputs to numbers
        int xNum = atoi(x.c_str());
        int yNum = atoi(y.c_str());
        // Checks if the inputs fall in the correct range
        if (xNum >= 0 && xNum < 3 && yNum >= 0 && yNum < 3) {
          // Checks if the input spot is empty
          if (board[yNum][xNum] == " ") {
            // Sets the board spot to the currentPlayer
            board[yNum][xNum] = currentPlayer;
            currentPlayer = (currentPlayer == "x") ? "o" : "x";
            printBoard(board);
          } else {
            output = "this spot is already taken";
          }
        } else {
          output = "the inputs must follow these constraints: 0 <= input < 3";
        }
      } else {
        output = "at least one of the inputs were not integers";
      }
    } else {
      output = "your input was either too long or short\n ex ->1";
    }
  }
  // Outputs an output if it exists
  if (output != "") {
    std::cout << output << std::endl;
  }
  // Winner of the game
  std::string winner = gameOver(board);
  // Checks if it was a cat's game
  if (winner != " ")
    std::cout << winner << " wins!" << std::endl;

  return 0;
}
