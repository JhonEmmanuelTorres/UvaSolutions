from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()

    def generate(word, current = ""):

        n = len(current)

        if n is len(word):
            print(current)
            return

        element = word[n]
        for i in range(n):
            generate(word, current[0: i] + element + current[i:])
        generate(word, current + element)



    line_cases = False
    while True:

        word = list(cin.next_line())
        if not word:
            return

        if line_cases:
            print()
        line_cases = True

        generate(word)


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
