from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()
    primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31]
    container = [0 for i in range(17)]
    graph = [[] for i in range(17)]
    n = None

    for i in range(1, 17):
        for prime in primes:
            if prime > i:
                graph[i].append(prime - i)


    def search(index):
        if index is 1 and container[index] is not 0:

            repeat = 0
            for i in range(1, n + 1):
                if container[i] is not 0:
                    repeat += 1

            if repeat is n:
                print(1, end='')
                aux = container[1]
                while aux is not 1:
                    print(f' {aux}', end='')
                    aux = container[aux]
                print()

            return


        for i in graph[index]:
            if i <= n and container[index] is 0:
                container[index] = i
                search(i)
                container[index] = 0
            else:
                break

    case = 1
    while True:
        try:
            n = cin.next_int()
            if case is not 1 and n:
                print()
        except:
            exit(0)

        for i in range(1, n + 1):
            container[i] = 0

        print(f'Case {case}:')
        case += 1
        search(1)


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
