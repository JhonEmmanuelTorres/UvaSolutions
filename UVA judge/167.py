from sys import stdin, stdout, exit
from collections import deque
from math import inf



def main():
    pis = Scanner()

    board = [None for i in range(8)]
    solution = []

    def place(r, c):
        for i in range(c):
            if r is board[i] or abs(board[i] - r) is abs(i - c):
                return False
        return True

    def backtrack(c):
        if c is 8:
            solution.append(board.copy())

        for r in range(8):
            if (place(r, c)):
                board[c] = r
                backtrack(c + 1)
    backtrack(0)

    t = pis.next_int()
    while t is not 0:
        t -= 1

        current_board = []
        for i in range(8):
            current_board.append(pis.next_array(int))

        score = 0
        for chess in solution:
            aux = 0
            for i in range(8):
                aux += current_board[chess[i]][i]
            score = max(aux, score)

        print(repr(score).rjust(5))


class Scanner:

    def next_int(self):
        return int(self.next_line())

    def next_float(self):
        return float(self.next_line())

    def next_line(self):
        return stdin.readline().strip()

    def next_array(self, fun = str):
        line = self.next_line().split(' ')
        return line if fun is str else list(map(fun, line))


if __name__ == "__main__":
    main()
