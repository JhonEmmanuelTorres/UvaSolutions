from sys import stdin, stdout, exit
from collections import deque
from math import inf

def main():
    cin = Scanner()
    graph = None
    visit = None
    m = None
    paths = None

    def dfs(path, node):
        if len(path) is m + 1:
            paths.append(f'({",".join(map(lambda x: str(x + 1), path))})')
            return


        for neighbor in graph[node]:
            if not visit[neighbor]:
                visit[neighbor] = True
                dfs(path + [neighbor], neighbor)
                visit[neighbor] = False


    while True:
        n, m = cin.next_array(int)
        graph = [[] for i in range(n)]
        visit = [False for i in range(n)]

        for i in range(n):
            line = cin.next_array(int)
            for j in range(n):
                if line[j] is 1:
                    graph[i].append(j)

        paths = []
        visit[0] = True
        dfs([0], 0)
        if len(paths) is 0:
            print(f'no walk of length {m}')
        else:
            print("\n".join(paths))
        try:
            div = cin.next_int()
            if div is not -9999: print()
        except:
            exit(0)




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
