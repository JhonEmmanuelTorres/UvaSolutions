from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    pis = Scanner()
    employees = pis.next_int()
    relations = [[] for i in range(employees)]
    depth = [None for i in range(employees)]
    for i in range(employees):
        edges = pis.next_array(int)
        for j in range(1, len(edges)):
            relations[i].append(edges[j])

    t = pis.next_int()
    while t is not 0:
        t -= 1

        initial_node = pis.next_int()

        if len(relations[initial_node]) is 0:
            print('0')
        else:
            for i in range(employees):
                depth[i] = inf
            depth[initial_node] = 0

            node_list = deque()
            node_list.append(initial_node)

            while len(node_list):
                person = node_list.popleft()
                for friend in relations[person]:
                    if depth[friend] is inf:
                        depth[friend] = depth[person] + 1
                        node_list.append(friend)

            depth = sorted(depth)
            maximum, boom = 0, 0
            repeats = {}
            for i in depth:
                if i is not inf:
                    try:
                        repeats[i] += 1
                    except:
                        repeats[i] = 1

            for key in repeats:
                if repeats[key] > maximum:
                    maximum = repeats[key]
                    boom = key

            if boom is 0:
                boom += 1
            print(maximum, boom)

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
