#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Class representing a Graph using an adjacency list
class Graph {
    int V; // Number of vertices
    vector<list<int>> adj; // Adjacency list

    // Private helper function for recursive DFS traversal
    void DFSUtil(int v, vector<bool>& visited) {
        // Mark the current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge into the graph (Undirected Graph)
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v); 
    }

    // Function to perform complete DFS traversal from a given source
    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        cout << "DFS Traversal starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << "\n";
    }
};

int main() {
    int vertices = 5;
    Graph g(vertices);

    // Creating a sample graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    cout << "------ Graph DFS Traversal ------\n";
    g.DFS(0); // Run DFS starting from node 0

    return 0;
}