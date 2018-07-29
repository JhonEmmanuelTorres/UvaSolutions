from sys import stdin

class DisjointSet:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
        self.height = [0 for i in range(n)]
        self.nodes = [1 for i in range(n)]

    def find_set(self, node):
        if node is self.parent[node]:
            return node
        self.parent[node] = self.find_set(self.parent[node])
        return self.parent[node]

    def is_same_set(self, nodeP, nodeQ):
        return self.find_set(nodeP) is self.find_set(nodeQ)

    def union_set(self, nodeP, nodeQ):
        rootP = self.find_set(nodeP)
        rootQ = self.find_set(nodeQ)

        if rootP is not rootQ:
            if self.height[rootP] < self.height[rootQ]:
                self.parent[rootP] = rootQ
                self.nodes[rootQ] += self.nodes[rootP]
            else:
                self.parent[rootQ] = rootP
                self.nodes[rootP] += self.nodes[rootQ]
                if self.height[rootP] is self.height[rootQ]:
                    self.height[rootP] += 1


    def size_set(self, n):
        parentSuspect = self.find_set(n)
        return self.nodes[parentSuspect]
