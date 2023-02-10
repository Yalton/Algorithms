
#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <cmath>

using namespace std;

// A struct to represent a graph
struct Graph
{
    int numNodes;
    vector<set<int>> adjacencyLists;
    vector<vector<double>> weights;
};

// A struct to represent a path
struct Path
{
    vector<int> nodes;
    double weight;
};

// A struct to represent a minimum spanning tree
struct MST
{
    vector<int> edges;
    double weight;
};

// A struct to represent an odd degree vertex
struct OddVertex
{
    int vertex;
    double weight;
};

// A struct to represent an odd degree graph
struct OddGraph
{
    int numNodes;
    vector<OddVertex> vertices;
    vector<vector<double>> weights;
};

// A struct to represent a perfect matching
struct PerfectMatching
{
    vector<int> edges;
    double weight;
};

// A struct to represent an Eulerian circuit
struct EulerianCircuit
{
    vector<int> edges;
    double weight;
};

// A struct to represent a Hamiltonian circuit
struct HamiltonianCircuit
{
    vector<int> edges;
    double weight;
};

// Calculates the weight of a path
double pathWeight(Graph graph, Path path)
{
    // YOUR CODE HERE
}

// Finds a minimum spanning tree of a graph
MST minimumSpanningTree(Graph graph)
{
    // YOUR CODE HERE
}

// Finds the odd degree vertices of a graph
vector<OddVertex> findOddVertices(MST mst)
{
    // YOUR CODE HERE
}

// Builds an odd degree graph
OddGraph buildOddGraph(Graph graph, vector<OddVertex> oddVertices)
{
    // YOUR CODE HERE
}

// Finds a minimum weight perfect matching of a graph
PerfectMatching minimumWeightPerfectMatching(OddGraph graph)
{
    // YOUR CODE HERE
}

// Builds an Eulerian circuit from a perfect matching
EulerianCircuit eulerianCircuit(OddGraph graph, PerfectMatching matching)
{
    // YOUR CODE HERE
}

// Finds a Hamiltonian circuit of a graph
HamiltonianCircuit hamiltonianCircuit(Graph graph, EulerianCircuit circuit)
{
    // YOUR CODE HERE
}

// Finds the shortest path between two nodes
Path shortestPath(Graph graph, int start, int end)
{
    // YOUR CODE HERE
}

// Finds the christofides path of a graph
Path christofidesPath(Graph graph)
{
    // YOUR CODE HERE
}

int main()
{
    // Read in the graph
    int numNodes;
    cin >> numNodes;

    Graph graph;
    graph.numNodes = numNodes;
    graph.adjacencyLists.resize(numNodes);
    graph.weights.resize(numNodes);
    for (int i = 0; i < numNodes; i++)
    {
        graph.weights[i].resize(numNodes);
    }

    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++)
    {
        int node1;
        int node2;
        double weight;
        cin >> node1 >> node2 >> weight;

        graph.adjacencyLists[node1].insert(node2);
        graph.adjacencyLists[node2].insert(node1);
        graph.weights[node1][node2] = weight;
        graph.weights[node2][node1] = weight;
    }

    // Find the christofides path
    Path path = christofidesPath(graph);

    // Print the path
    for (int node : path.nodes)
    {

        cout << node << " ";
    }
    cout << endl;
    cout << path.weight << endl;

    return 0;
}