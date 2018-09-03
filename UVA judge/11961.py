from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()
    t = cin.next_int()
    alphabet = { "A": 0, "C": 1, "G": 2, "T": 3 }
    inAlpha = [ "A", "C", "G", "T" ]

    def combinations(index = 0, array = []):
        if len(array) is k:
            mutations.append(array)
            return

        combinations(index + 1, array + [index])

        if n - (index + 1) + len(array) < k or index is n:
            return

        combinations(index + 1, array)

    def generate(index = 0):
        if index is len(way):
            answer.add("".join(map(lambda x: inAlpha[x], tmp)))
            return

        for i in range(0, 4):
            tmp[way[index]] = (tmp[way[index]] + i) % 4
            generate(index + 1)

    for _ in range(t):
        n, k = cin.next_array(int)
        word = list(map(lambda x: alphabet[x], list(cin.next_line())))
        mutations = []
        combinations()
        answer = set()
        for way in mutations:
            tmp = word.copy()
            generate()

        answer = sorted(answer)
        print(len(answer))
        print("\n".join(answer))


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
