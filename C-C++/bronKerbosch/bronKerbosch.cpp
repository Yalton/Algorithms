#include <iostream>
#include <vector>
#include <set>

using namespace std;

// A struct to represent a graph
struct Graph
{
    int numNodes;
    vector<set<int>> adjacencyLists;
};

// A struct to represent a maximal clique
struct Clique
{
    set<int> nodes;
};

// Finds all maximal cliques in a graph
vector<Clique> findAllCliques(Graph graph)
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

    int numEdges;
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++)
    {
        int node1;
        int node2;
        cin >> node1 >> node2;

        graph.adjacencyLists[node1].insert(node2);
        graph.adjacencyLists[node2].insert(node1);
    }

    // Find all cliques
    vector<Clique> cliques = findAllCliques(graph);

    // Print the cliques
    for (Clique clique : cliques)
    {
        for (int node : clique.nodes)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}