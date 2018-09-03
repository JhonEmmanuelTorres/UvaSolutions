from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()
    dictionary = None

    def generate(rule, index, password):
        if index is len(rule):
            print(password)
            return

        if rule[index] is '0':
            for i in range(10):
                generate(rule, index + 1, password + str(i))
        else:
            for i in dictionary:
                generate(rule, index + 1, password + i)


    while True:
        try:
            n = cin.next_int()
            print('--')
        except:
            exit(0)

        dictionary = []
        while n is not 0:
            n -= 1
            dictionary.append(cin.next_line())

        rules = []
        m = cin.next_int()
        while m is not 0:
            m -= 1
            rules.append(cin.next_line())

        for rule in rules:
            generate(rule, 0, '')



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
