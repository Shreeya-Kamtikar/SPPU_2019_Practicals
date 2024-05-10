from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        self.max_node = -1

    def add_edge(self, u, v):
        # For an undirected graph, add edges in both directions
        self.graph[u].append(v)
        self.graph[v].append(u)
        # Update the maximum node number encountered
        self.max_node = max(self.max_node, u, v)

    def dfs_util(self, v, visited):
        # Mark the current node as visited and print it
        visited[v] = True
        print(v, end=' ')

        # Recursively traverse all adjacent nodes of the current node
        for i in self.graph[v]:
            if not visited[i]:
                self.dfs_util(i, visited)

    def dfs(self, v):
        # Initialize a visited list to keep track of visited nodes
        visited = [False] * (self.max_node + 1)
        # Call the utility function to perform DFS traversal
        self.dfs_util(v, visited)

    def bfs(self, v):
        # Initialize a visited list to keep track of visited nodes
        visited = [False] * (self.max_node + 1)
        # Initialize a queue for BFS traversal
        queue = []

        # Mark the start node as visited and enqueue it
        queue.append(v)
        visited[v] = True

        # While the queue is not empty, dequeue a node and process its neighbors
        while queue:
            v = queue.pop(0)
            print(v, end=' ')

            # Enqueue all adjacent nodes of the dequeued node
            for i in self.graph[v]:
                if not visited[i]:
                    queue.append(i)
                    visited[i] = True

# Taking input for number of nodes
num_nodes = int(input("Enter the number of nodes in the graph: "))
g = Graph()

# Asking for connections between nodes
print("Enter connections between nodes (enter -1 to stop):")
while True:
    u, v = map(int, input().split())
    if u == -1 or v == -1:
        break
    g.add_edge(u, v)

# Applying DFS
start_node_dfs = int(input("Enter the starting node for DFS traversal: "))
print("DFS Traversal:")
g.dfs(start_node_dfs)
print()

# Applying BFS
start_node_bfs = int(input("Enter the starting node for BFS traversal: "))
print("BFS Traversal:")
g.bfs(start_node_bfs)
print()
