#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

// A structure to represent a node in adjacency list
struct Node
{
    int vertex;
    int weight;
};

// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    vector<Node> *adj;
};

// A utility function to create a new adjacency list node
Node newAdjListNode(int vertex, int weight)
{
    Node node;
    node.vertex = vertex;
    node.weight = weight;
    return node;
}

// A utility function that creates a graph of V vertices
Graph createGraph(int V)
{
    Graph graph;
    graph.V = V;

    // Create an array of adjacency lists.  Size of array will be V
    graph.adj = new vector<Node>[V];

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(Graph &graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the beginning
    Node node = newAdjListNode(dest, weight);
    graph.adj[src].push_back(node);

    // Since graph is undirected, add an edge from dest to src also
    node = newAdjListNode(src, weight);
    graph.adj[dest].push_back(node);
}

// A utility function to print the adjacency list representation of graph
void printGraph(Graph graph)
{
    for (int v = 0; v < graph.V; ++v)
    {
        cout << "Node " << v << ": ";

        for (int i = 0; i < graph.adj[v].size(); ++i)
        {
            cout << "(" << graph.adj[v][i].vertex << ", " << graph.adj[v][i].weight << ") ";
        }

        cout << "\n";
    }
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int *distance, bool *sptSet, int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && distance[v] <= min)
            min = distance[v], min_index = v;

    return min_index;
}

// A utility function used to print the constructed distance array
void printSolution(int *distance, int n)
{
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < n; i++)
        cout << i << " \t" << distance[i] << "\n";
}

// The main function that finds shortest distances from src to all other
// vertices using Bellman-Ford algorithm.  The function also detects negative
// weight cycles
void BellmanFord(Graph &graph, int src)
{
    int V = graph.V;

    // Create a distance array and initialize all distances as INFINITE
    int *distance = new int[V];
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    // distance[src] = 0;

    // Relax all edges |V| - 1 times. A simple shortest pa
    h from src
        // to any other vertex can have at-most |V| - 1 edges
        for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (int k = 0; k < graph.adj[j].size(); k++)
            {
                int dest = graph.adj[j][k].vertex;
                int weight = graph.adj[j][k].weight;

                if (distance[dest] > distance[j] + weight)
                    distance[dest] = distance[j] + weight;
            }
        }
    }

    // Check for negative-weight cycles.  The above step guarantees
    // shortest distances if graph doesn't contain negative weight cycle.
    // If we get a shorter path, then there is a cycle.
    for (int j = 0; j < V; j++)
    {
        for (int k = 0; k < graph.adj[j].size(); k++)
        {
            int dest = graph.adj[j][k].vertex;
            int weight = graph.adj[j][k].weight;

            if (distance[dest] > distance[j] + weight)
                cout << "Graph contains negative weight cycle\n";
        }
    }

    printSolution(distance, V);
}

// Driver program to test above functions
int main()
{
    // create the graph given in above fugure
    int V = 5;
    Graph graph = createGraph(V);

    // add edge 0-1 (or A-B in above figure)
    addEdge(graph, 0, 1, -1);

    // add edge 0-2 (or A-C in above figure)
    addEdge(graph, 0, 2, 4);

    // add edge 1-2 (or B-C in above figure)
    addEdge(graph, 1, 2, 3);

    // add edge 1-3 (or B-D in above figure)
    addEdge(graph, 1, 3, 2);

    // add edge 1-4 (or A-E in above figure)
    addEdge(graph, 1, 4, 2);

    // add edge 3-2 (or D-C in above figure)
    addEdge(graph, 3, 2, 5);

    // add edge 3-1 (or D-B in above figure)
    addEdge(graph, 3, 1, 1);

    // add edge 4-3 (or E-D in above figure)
    addEdge(graph, 4, 3, -3);

    // Calculate the single source shortest path from vertex 0
    BellmanFord(graph, 0);

    return 0;
}