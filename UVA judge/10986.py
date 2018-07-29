from sys import stdin
from heapq import *
import math

LINK = 1
WEIGHT = 0

class GraphUnweight:
    def __init__(self):
        self.graph = {}

    def make_link(self, origin_node, final_node):
        if origin_node not in self.graph:
            self.graph[origin_node] = []
        self.graph[origin_node].append(final_node)


    def dijkstra(self, initial_node):
        visit = {}
        depth = {}
        for node in self.graph:
            visit[node] = False
            depth[node] = math.inf

        depth[initial_node] = 0

        node_list = []
        heappush(node_list, [0, initial_node])
        while len(node_list): # node_list is not empty
            current_node = heappop(node_list)[LINK]

            if visit[current_node]:
                continue

            visit[current_node] = True

            for node in self.graph[current_node]:
                if depth[current_node] + node[WEIGHT] < depth[node[LINK]]:
                    depth[node[LINK]] = depth[current_node] + node[WEIGHT]
                    heappush(node_list, [depth[node[LINK]], node[LINK]])

        return depth



if __name__ == "__main__":

    t = int(stdin.readline())
    for case in range(1, t + 1):
        print(f'Case #{case}:', end=' ')

        network = GraphUnweight()
        n, m, S, T = map(int, stdin.readline().strip().split(' '))
        for i in range(n):
            network.graph[i] = []
        while m > 0:
            m -= 1
            u, v, w = map(int, stdin.readline().strip().split(' '))
            network.make_link(u, [w, v])
            network.make_link(v, [w, u])


        depth = network.dijkstra(S)
        print(depth[T] if depth[T] is not math.inf else 'unreachable')
