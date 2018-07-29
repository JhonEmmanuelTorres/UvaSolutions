from sys import stdin

VISITED = 1
UNVISITED = 0

def dfs(node, notVisit, color, graph):
    if notVisit is node:
        return

    color[node] = VISITED
    for neighbor in graph[node]:
        if color[neighbor] is UNVISITED:
            dfs(neighbor, notVisit, color, graph)

def division(n):
    print('+' + ('-' * (2 * n - 1)) + '+')

def line(array):
    for i in array:
        print('|N' if i is VISITED else '|Y', end='')
    print('|')

# if __name__ is "__main__":
t = int(stdin.readline())
for case in range(1, t + 1):
    n = int(stdin.readline())
    graph = {}
    for i in range(0, n):
        graph[i] = []
        aux = list(map(int, stdin.readline().strip().split(' ')))
        for j in range(0, n):
            if aux[j] is 1:
                graph[i].append(j)

    print(f"Case {case}:")
    aux_color = [UNVISITED for i in range(n)]
    dfs(0, -1, aux_color, graph)
    for i in range(n):
        aux_color[i] = 1 - aux_color[i]

    for i in range(0, n):
        color = aux_color.copy()
        dfs(0, i, color, graph)

        division(n)
        line(color)

    else:
        division(n)
