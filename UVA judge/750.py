from sys import stdin, stdout, exit
from collections import deque
from math import inf



def main():
    pis = Scanner()
    t = pis.next_int()
    aux = t
    pis.next_line()
    board = [None for i in range(8)]
    a = None
    b = None
    solution = []

    def place(r, c):
        for i in range(c):
            if r is board[i] or abs(board[i] - r) is abs(i - c):
                return False
        return True

    def backtrack(c):
        if c is 8 and board[b] is a:
            solution.append(f'      {" ".join(map(lambda x: str(x + 1), board))}')

        for r in range(8):
            if (place(r, c)):
                board[c] = r
                backtrack(c + 1)


    while t is not 0:
        t -= 1
        try:
            a, b = pis.next_array(int)
            if t + 1 is not aux:
                print()
        except:
            exit(0)

        for i in range(8):
            board[i] = 0
        a -= 1
        b -= 1
        solution = []

        print('SOLN       COLUMN')
        print(' #      1 2 3 4 5 6 7 8\n')
        backtrack(0)
        for i in range(len(solution)):
            print(repr(i + 1).rjust(2), end="")
            print(solution[i])

        pis.next_line()

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
