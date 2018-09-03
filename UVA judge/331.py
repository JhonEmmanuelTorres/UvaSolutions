from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()
    array = None
    sortList = None


    def searchPair():
        answer = 0
        if array == sortList:
            return 1

        for i in range(n - 1):
            if array[i] > array[i + 1]:
                array[i], array[i + 1] = array[i + 1], array[i]
                answer += searchPair()
                array[i], array[i + 1] = array[i + 1], array[i]

        return answer

    c = 1
    line = cin.next_array(int)
    while line != [0]:
        n = line[0]
        array = line[1:]
        sortList = sorted(array)

        answer = 0 if array == sortList else searchPair()

        print(f"There are {answer} swap maps for input data set {c}.")
        c += 1

        line = cin.next_array(int)


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
