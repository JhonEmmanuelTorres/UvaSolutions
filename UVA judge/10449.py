from sys import stdin, exit
from math import inf

def main():
    graph = [None for i in range(201)]
    depth = [None for i in range(201)]
    cases = 1

    while True:
        try:
            juntions = list(map(int, stdin.readline().strip().split()))
            n = juntions[0] + 1
        except:
            exit(0)

        for i in range(1, n):
            graph[i] = []
            depth[i] = inf

        times = int(stdin.readline().strip())
        while times > 0:
            times -= 1
            u, v = map(int, stdin.readline().strip().split())
            graph[u].append([(juntions[v] - juntions[u]) ** 3, v])


        if n > 1:
            depth[1] = 0

        for _ in range(n - 2):
            for node in range(1, n):
                for [weight, neighbor] in graph[node]:
                    depth[neighbor] = min(depth[neighbor], depth[node] + weight)

        for node in range(1, n):
            for [weight, neighbor] in graph[node]:
                if depth[neighbor] > depth[node] + weight:
                    depth[neighbor] = -1


        print(f"Set #{cases}")

        times = int(stdin.readline().strip())
        while times > 0:
            times -= 1
            node = int(stdin.readline().strip())
            if depth[node] < 3 or depth[node] is inf:
                print('?')
            else:
                print(depth[i])

        cases += 1



if __name__ == "__main__":
    main()

