from sys import stdin, stdout, exit
from collections import deque
from math import inf, ceil

class GraphUnweigth:
    def __init__(self):
        self.graph = {}

    def make_link(self, origin_node, final_node):

        if len(origin_node) is len(final_node):

            diffLetter = 0
            for i in range(len(origin_node)):
                if origin_node[i] is not final_node[i]:
                    diffLetter += 1

            if diffLetter is 1:
                self.graph[origin_node].append(final_node)
                self.graph[final_node].append(origin_node)

    def bfs(self, origin, final):
        color = {}
        depth = {}
        for node in self.graph:
            color[node] = 'white'
            depth[node] = inf

        depth[origin] = 0
        color[origin] = 'gray'

        node_list = deque()
        node_list.append(origin)
        while node_list:
            node = node_list.popleft()

            for neighbor in self.graph[node]:
                if color[neighbor] is 'white':
                    color[neighbor] = 'gray'
                    depth[neighbor] = depth[node] + 1
                    node_list.append(neighbor)

            color[node] = 'black'

        return depth[final]



def main():
    ps = Scanner()
    n = ps.next_int()
    stdin.readline()

    while n > 0:

        dictionary = GraphUnweigth()
        line = ps.next_line()
        while line is not '*':
            dictionary.graph[line] = []
            line = ps.next_line()

        words = list(dictionary.graph.keys())
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                dictionary.make_link(words[i], words[j])


        query = ps.next_line()
        while len(query):
            origin, final = query.split(' ')
            answer = dictionary.bfs(origin, final)
            print(origin, final, answer)
            query = ps.next_line()

        n -= 1
        if n is not 0:
            print()


class Scanner:

    def next_int(self):
        return int(stdin.readline().strip())

    def next_float(self):
        return float(stdin.readline().strip())

    def next_line(self):
        return stdin.readline().strip()

    def new_array(self):
        return map(int, stdin.readline().strip().split(' '))


if __name__ == "__main__":
    main()

