from os import system, name

board = [[' ', ' ', ' '],[' ', ' ', ' '],[' ', ' ', ' ']]

currentPlayer = 'x'

def printBoard():
    # for windows
    if name == 'nt':
        _ = system('cls')

    # for mac and linux(here, os.name is 'posix')
    else:
        _ = system('clear')
    for i in range(3):
        print(' {} | {} | {}'.format(board[i][0],board[i][1],board[i][2]))
        if i != 2:
            print('___ ___ ___ ')

def equalArray(a):
    return a[1:] == a[:-1]

def gameOver():
    for i in range(3):

        #horizontal
        if equalArray(board[i]) and board[i][0] != ' ':
            return board[i][0]

        #vertical
        vertBoard = [j[i] for j in board]

        if equalArray(vertBoard) and vertBoard[0] != ' ':
            return vertBoard[0]

    center = board[1][1]

    if center != ' ':
        #diag
        if board[0][0] == center == board[2][2] or board[0][2] == center == board[2][0]:
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
        print("cat's Game")
        break

    x = input('type x of your move: ')
    y = input('type y of your move: ')
    printBoard()
    if len(x) == 1 and len(y) == 1:
        if x.isnumeric() and y.isnumeric():
            x = int(x)
            y = int(y)
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
        print('your input was either too long or short, make sure it has correct formatting\n ex ->1')

winner = gameOver()

if (winner != None):
    print(winner + ' wins!')
