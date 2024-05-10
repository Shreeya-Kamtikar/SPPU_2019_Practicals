from collections import deque

def bfs(adjList, start_node, visited):
    queue = deque()
    visited[start_node] = True
    queue.append(start_node)
    while queue:
        current_node = queue.popleft()
        print(current_node,end="\t")
        for neighbor in adjList[current_node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)

def dfs(adjList, start_node, visited):
    visited[start_node] = True
    print(start_node,end="\t")
    for neighbor in adjList[start_node]:
        if not visited[neighbor]:
            dfs(adjList, neighbor, visited)

def add_edge(adjList, u, v):
    adjList[u].append(v)

def main():
    vertices = int(input("Enter the number of vertices: "))
    edges = int(input("Enter the number of edges: "))

    adjacency_list = [[] for _ in range(vertices)]
    for i in range(edges):
        print(f"For edge {i+1}:")
        x = int(input("Enter the start vertex: "))
        y = int(input("Enter the end vertex: "))
        add_edge(adjacency_list, x, y)

    visited_nodes = [False] * vertices

    start_vertex = int(input("\nEnter the start vertex: "))

    print("Graph Traversal:")
    print("---------------")

    print("\nBFS Traversal:")
    bfs(adjacency_list, start_vertex, visited_nodes)

    print("\nDFS Traversal:")
    visited_nodes = [False] * vertices  # Reset visited nodes for DFS
    dfs(adjacency_list, start_vertex, visited_nodes)

if __name__ == "__main__":
    main()