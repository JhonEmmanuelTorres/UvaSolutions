from sys import stdin

if __name__ == '__main__':
    try:
        while True:
            n = int(stdin.readline())
            m = int(stdin.readline())
            aux = list(stdin.readline().strip())
            graph = {}
            for i in aux:
                graph[i] = []
            wake_up = {}
            while m > 0:
                m -= 1
                u, v = list(stdin.readline().strip())
                if u not in graph:
                    graph[u] = []
                if v not in graph:
                    graph[v] = []
                graph[u].append(v)
                graph[v].append(u)
                wake_up[u] = wake_up[v] = 0

            for i in aux:
                wake_up[i] = 1


            answer = 0
            while True:
                new_node = []
                for node in graph:
                    if wake_up[node] is not 1:
                        neighbors = 0
                        for i in graph[node]:
                            neighbors += wake_up[i]
                        if neighbors >= 3:
                            new_node.append(node)

                for i in new_node:
                    wake_up[i] = 1

                if len(new_node) is 0:
                    break
                answer += 1

            if sum(list(wake_up.values())) is not n:
                print('THIS BRAIN NEVER WAKES UP')
            else:
                print(f"WAKE UP IN, {answer}, YEARS")

            stdin.readline()
    except:
        exit(0)
