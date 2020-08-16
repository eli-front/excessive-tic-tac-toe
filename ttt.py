from os import system, name

def clear():

    # for windows
    if name == 'nt':
        _ = system('cls')

    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')

board = [[' ', ' ', ' '],[' ', ' ', ' '],[' ', ' ', ' ']]

currentPlayer = 'x'

def printBoard():
    clear()
    for i in range(3):
        print(' {} | {} | {}'.format(board[i][0],board[i][1],board[i][2]))
        if i != 2:
            print('___ ___ ___ ')


def gameOver():
    for i in range(3):

        #horizontal
        if board[i][1:] == board[i][:-1] and board[i][0] != ' ':
            return board[i][0]

        #vertical
        vertBoard = [j[i] for j in board]

        if vertBoard[1:] == vertBoard[:-1] and vertBoard[0] != ' ':
            return vertBoard[0]


    center = board[1][1]

    if center != ' ':
        #diag 1
        if board[0][0] == center == board[2][2]:
            return center

        #diag2
        if board[0][2] == center == board[2][0]:
            return center

def boardFull():
    for i in board:
        for j in i:
            if j == ' ':
                return False
    return True


printBoard()

while gameOver() == None:

    if boardFull():
        print('Cats Game')
        break

    move = input('type x & y of your move (x y):')
    printBoard()
    inputs = move.split()
    if len(inputs) == 2:
        if inputs[0].isnumeric() and inputs[1].isnumeric():
            x = int(inputs[0])
            y = int(inputs[1])
            if (x >= 0 and x < 3) and (y >= 0 and y < 3):
                if board[y][x] == ' ':
                    board[y][x] = currentPlayer
                    currentPlayer = 'x' if currentPlayer == 'o' else 'o'
                    printBoard()
                else:
                    print('this spot is already taken')
            else:
                print('the inputs must follow these constraints: 0 <= input < 3')
        else:
            print('your inputs were not integers')
    else:
        print('your input was either too long or short, make sure it has correct formatting\n ex ->1 2')
