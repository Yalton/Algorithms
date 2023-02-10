#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct Graph
{

    int V, E;

    struct Edge *edge;
};

struct Subset
{
    int parent;
    int rank;
};

int find(struct Subset subsets[], int i)
{

    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(struct Edge a, struct Edge b)
{
    return a.weight < b.weight;
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    cout << endl;
}

void printMST(struct Edge *result, int n)
{
    cout << "Following are the edges in the constructed MST\n";
    for (int i = 1; i < n; ++i)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
}

int minKey(int key[], bool mstSet[], int V)
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void primMST(struct Graph *graph)
{
    int V = graph->V;
    int E = graph->E;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    for (i = 0; i < V; i++)
        result[i].src = result[i].dest = result[i].weight = 0;

    int key[V];

    bool mstSet[V];

    for (i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    result[0].src = -1;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minKey(key, mstSet, V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)

            if (graph->edge[u].dest == v && mstSet[v] == false &&
                graph->edge[u].weight < key[v])
            {
                result[e++] = graph->edge[u];
                key[v] = graph->edge[u].weight;
            }
    }

    printMST(result, V);
}

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

int main()
{

    int V = 9;
    int E = 14;
    struct Graph *graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 4;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 7;
    graph->edge[1].weight = 8;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 8;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 7;
    graph->edge[3].weight = 11;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 7;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 5;
    graph->edge[5].weight = 4;

    graph->edge[6].src = 2;
    graph->edge[6].dest = 8;
    graph->edge[6].weight = 2;

    graph->edge[7].src = 3;
    graph->edge[7].dest = 4;
    graph->edge[7].weight = 9;

    graph->edge[8].src = 3;
    graph->edge[8].dest = 5;
    graph->edge[8].weight = 14;

    graph->edge[9].src = 4;
    graph->edge[9].dest = 5;
    graph->edge[9].weight = 10;

    graph->edge[10].src = 5;
    graph->edge[10].dest = 6;
    graph->edge[10].weight = 2;

    graph->edge[11].src = 6;
    graph->edge[11].dest = 7;
    graph->edge[11].weight = 1;

    graph->edge[12].src = 6;
    graph->edge[12].dest = 8;
    graph->edge[12].weight = 6;

    graph->edge[13].src = 7;
    graph->edge[13].dest = 8;
    graph->edge[13].weight = 7;

    primMST(graph);

    return 0;
}