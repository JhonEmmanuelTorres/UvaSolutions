from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()
    c = cin.next_int()

    def notPossible(possibleSet):
        for rule in rules:
            if rule[0] in possibleSet and rule[1] in possibleSet:
                return True
        return False

    def generate(index = 0, current_set = []):
        if notPossible(current_set):
            return
        if len(current_set) is s:
            answers.append(current_set)
            return

        for i in range(index, t):
            generate(i + 1, current_set + [topics[i]])

    for case in range(1, c + 1):
        t, p, s = cin.next_array(int)
        topics = []
        while t is not 0:
            t -= 1
            topics.append(cin.next_line().upper())
        t = len(topics)

        rules = []
        while p is not 0:
            p -= 1
            rules.append(cin.next_array(str.upper))

        answers = []
        topics = sorted(topics, key=lambda x: (-len(x), x))
        generate()

        print(f'Set {case}:')
        for speeds in answers:
            print(" ".join(speeds))
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
