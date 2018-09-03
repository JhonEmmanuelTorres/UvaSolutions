from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()

    t = cin.next_int()
    cin.next_line()
    words = None

    def generate(sizeOfSet, index, set):
        if sizeOfSet is len(set):
            print(", ".join(set))
            return

        for i in range(index, len(words)):
            generate(sizeOfSet, i + 1, set + [words[i]])

    while t is not 0:
        t -= 1

        sets = cin.next_array()
        words = []

        line = cin.next_line()
        while line is not "":
            words.append(line)
            line = cin.next_line()

        left = right = None
        if sets[0] is '*':
            left = 1
            right = len(words)
        elif len(sets) is 2:
            left, right = map(int, sets)
        else:
            left = right = int(sets[0])

        for i in range(left, right + 1):
            print(f"Size {i}")
            generate(i, 0, [])
            print()

        if t is not 0:
            print()



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
