from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    pis = Scanner()
    answer = 0
    n = pis.next_int()
    while n is not 0:
        answer += n
        n = pis.next_int()
    print(answer)


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
