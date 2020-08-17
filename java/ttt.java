// Copyright (c) 2020 Eli B. Front. All rights reserved.

import java.util.Scanner;  // Import the Scanner class

public class ttt {

  // Prints the current board and clears the previous board
  private static void printBoard(String[][] board) {
    System.out.print("\033[H\033[2J");
    System.out.flush();
    for (int i = 0; i < 3; i++) {
      System.out.printf(" %s | %s | %s\n", board[i][0], board[i][1], board[i][2]);
      if (i != 2) {
        System.out.println("___ ___ ___ ");
      }
    }
  }

  // Checks if all elements in an array are equal
  private static boolean equalArray(String[] a) {
    return (a[0] == a[1] && a[1] == a[2]);
  }

  // If there is a winner it will return that player
  private static String gameOver(String[][] board) {
    for (int i = 0; i < 3; i++) {
      // horizontal
      if (equalArray(board[i]) && board[i][0] != " ") {
        return board[i][0];
      }
      // vertical
      String[] vertBoard = new String[3];
      for (int j = 0; j < 3; j++) vertBoard[j] = board[j][i];

      if (equalArray(vertBoard) && vertBoard[0] != " ") {
        return vertBoard[0];
      }
    }
    // diagonal
    String center = board[1][1];
    if ((board[0][0] == center && center == board[2][2]) || (board[0][2] == center && center == board[2][0])) {
      return center;
    }
    // The game is not over
    return " ";
  }

  // Checks if the board is full
  private static boolean boardFull(String[][] board) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (board[i][j] == " ") return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    String[][] board = {{" ", " ", " "},{" ", " ", " "},{" ", " ", " "}};
    String currentPlayer = "x";
    printBoard(board);

    while (gameOver(board) == " ") {
      if (boardFull(board)) {
        System.out.println("cat's game");
        break;
      }
      System.out.print("type x of your move: ");
      int x = s.nextInt();
      System.out.print("type y of your move: ");
      int y = s.nextInt();

      // Checks if the inputs fall in the correct range
      if ((x >= 0 && x < 3) && (y >= 0 && y < 3)) {
        // Checks if the input spot is empty
        if (board[y][x] == " ") {
          // Sets the board spot to the currentPlayer
          board[y][x] = currentPlayer;
          currentPlayer = (currentPlayer == "x") ? "o" : "x";
          printBoard(board);
        } else {
          System.out.println("this spot is already taken");
        }
      } else {
        System.out.println("the inputs must follow these constraints: 0 <= input < 3");
      }
    }

    // Winner of the game
    String winner = gameOver(board);
    // Checks if it was a cat's game
    if (winner != " ") System.out.println(winner + " wins!");
  }
}
