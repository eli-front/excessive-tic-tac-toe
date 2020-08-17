// Copyright (c) 2020 Eli B. Front. All rights reserved.


#!/usr/bin/swift
// If permission denied run the following in Terminal:
// chmod +x ttt.swift

private var board = [[" ", " ", " "], [" ", " ", " "], [" ", " ", " "]]

private var currentPlayer = "x"

private func printBoard() {
    // Clear terminal
    print("\u{001B}[2J")
    for i in 0...2 {
        print(" \(board[i][0]) | \(board[i][1]) | \(board[i][2])")
        if i != 2 {
            print("___ ___ ___ ")
        }
    }
}

private func gameOver() -> String {
    for i in 0...2 {
        // horizontal
        if board[i][0...1] == board[i][1...2] {
            return board[i][0]
        }
        // vertical
        var vertBoard = [String]()
        for j in 0...2 {
            vertBoard.append(board[j][i])
        }
        if vertBoard[0...1] == vertBoard[1...2] {
            return board[i][0]
        }
    }
    let center = board[1][1]
    // diagonal
    if (board[0][0] == center && center == board[2][2]) || (board[0][2] == center && center == board[2][0]) {
        return center
    }
    return " "
}

private func boardFull() -> Bool {
    for i in board {
        for j in i {
            if j == " " {
                return false
            }
        }
    }
    return true
}

printBoard()

while gameOver() == " " {
    if boardFull() {
        print("cat's game")
    }
    print("type x of your move: ", terminator: "")
    let x = Int(readLine()!)
    print("type y of your move: ", terminator: "")
    let y = Int(readLine()!)
    printBoard()
    if let x = x, let y = y {
        if (x >= 0 && x < 3) && (y >= 0 && y < 3) {
            if (board[y][x] == " ") {
                board[y][x] = currentPlayer
                currentPlayer = (currentPlayer == "x") ? "o" : "x"
                printBoard()
            } else {
                print("this spot is already taken")
            }
        } else {
            print("the inputs must follow these constraints: 0 <= input < 3")
        }
    } else {
        print("your inputs were not integers or were not formatted correctly \n ex ->1")
    }
}

private let winner = gameOver()

if winner != " " {
    print("\(winner) wins!")
}
