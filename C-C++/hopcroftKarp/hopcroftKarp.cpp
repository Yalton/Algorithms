#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <stdio.h>

using namespace std;

const int MAXN = 500;
const int INF = 1000000000;

int n, m, k;
vector<int> G[MAXN];
int match[MAXN];
int layer[MAXN];
int father[MAXN];
int visited[MAXN];

void bfs()
{
    queue<int> que;
    memset(layer, -1, sizeof(layer));
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            layer[i] = 0;
            que.push(i);
        }
    }
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i];
            if (layer[match[v]] == -1)
            {
                layer[match[v]] = layer[u] + 1;
                que.push(match[v]);
            }
        }
    }
}

bool dfs(int u)
{
    for (int i = 0; i < G[u].size(); ++i)
    {
        int v = G[u][i];
        int w = match[v];
        if (w == -1 || (layer[w] == layer[u] + 1 && dfs(w)))
        {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int hopcroft_karp()
{
    memset(match, -1, sizeof(match));
    int ans = 0;
    while (true)
    {
        bfs();
        int d = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= n; ++i)
        {
            if (match[i] == -1 && dfs(i))
            {
                ++d;
            }
        }
        if (d == 0)
        {
            break;
        }
        ans += d;
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
    }
    printf("%d\n", hopcroft_karp());
    return 0;
}