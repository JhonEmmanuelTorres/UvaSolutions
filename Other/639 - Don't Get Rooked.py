from sys import stdin

points = [ [0, 1], [0, -1], [1, 0], [-1, 0] ]

def isPossible( board, x, y, n ):
    for a, b in points:
        i = x + a
        j = y + b
        while i >= 0 and i < n and j >= 0 and j < n and board[i][j] != "X":
            if board[i][j] == "o":
                return False
            i += a
            j += b
    return True

n = int( stdin.readline() )

while n != 0:

    board = []
    for i in range(n):
        board.append( stdin.readline() )

    p = n*n
    answer = 0

    copyBoard = [""]*n
    for i in range( 1, 1 << p ):

        for a in range( n ):
            copyBoard[a] = board[a]


        rooks = []
        for j in range( p ):
            if i & (1 << j):
                x = int(j / n)
                y = j % n
                if copyBoard[x][y] != "X":
                    copyBoard[x] = copyBoard[x][:y] + "o" + copyBoard[x][y+1:]
                    rooks.append( [x,y] )

        count = 0
        for x, y in rooks:
            if not isPossible( copyBoard, x, y, n ):
                count = 0
                break
            else:
                count += 1

        answer = max( answer, count )

    print( answer )
    n = int( stdin.readline() )
