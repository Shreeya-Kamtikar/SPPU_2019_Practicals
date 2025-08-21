#include <iostream>
#include <queue>
#include <stack>
#include <omp.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Graph 
{
    int V;
    vector<vector<int>> adj;
    
    Graph(int V) 
    {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) 
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    void displayGraph() 
    {
        cout << "Graph representation (Adjacency List):\n";
        for (int i = 0; i < V; i++) 
        {
            cout << i << ": ";
            for (int v : adj[i]) 
                cout << v << " ";
            cout << endl;
        }
    }

    void BFS(int start) 
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from node " << start << ": ";
        while (!q.empty()) 
        {
            int u = q.front();
            q.pop();
            cout << u << " ";

            #pragma omp parallel for
            for (int i = 0; i < adj[u].size(); i++) 
            {
                int v = adj[u][i];
                if (!visited[v]) // helps reduce the number of threads that need to enter the critical section
                {
                    #pragma omp critical
                    {
                        if (!visited[v]) // another thread might have already marked visited[v] = true by the time it enters the critical section 
                                        // necessary to check correctness
                        {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) 
    {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);
        visited[start] = true;

        cout << "DFS traversal starting from node " << start << ": ";
        while (!s.empty()) 
        {
            int u = s.top();
            s.pop();
            cout << u << " ";

            // Gather neighbors not visited yet (serial)
            vector<int> neighbors;
            for (int v : adj[u]) 
            {
                if (!visited[v]) 
                {
                    neighbors.push_back(v);
                }
            }
            // Sort neighbors to control visit order
            // Sort in reverse to make smallest visited first (LIFO stack behavior)
            sort(neighbors.rbegin(), neighbors.rend());     

            // Parallel process neighbors: mark visited and push to stack
            #pragma omp parallel for
            for (int i = 0; i < (int)neighbors.size(); i++) 
            {
                int v = neighbors[i];
                // Synchronize visited flag and push to stack
                #pragma omp critical
                {
                    if (!visited[v]) 
                    {
                        visited[v] = true;
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
        // Because multiple threads are pushing neighbors to the stack at the same time, the order in which nodes are visited can change depending on 
        // how threads are scheduled. Even though a critical section is used to avoid errors, can't control the exact order in which nodes get added to 
        // the stack. Since DFS depends on the order of visiting nodes, the output can be different in each run.
    }
};

int main() 
{
    int V, edgeCount;

    cout << "Enter number of nodes: ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> edgeCount;

    cout << "Enter edges (start_node end_node): \n";
    for (int i = 0; i < edgeCount; i++) 
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.displayGraph();

    int root;
    cout << "Enter the root node of tree: ";
    cin >> root;

    cout << "BFS traversal from node " << root << ":\n";
    g.BFS(root);

    cout << "DFS traversal from node " << root << ":\n";
    g.DFS(root);

    return 0;
}