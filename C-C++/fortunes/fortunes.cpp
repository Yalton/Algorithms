#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

const int MAXN = 50000 + 100;

struct Point
{
    int x, y;
    Point() {}
    Point(int x, int y) : x(x), y(y) {}
    Point operator-(const Point &b) const
    {
        return Point(x - b.x, y - b.y);
    }
    int operator^(const Point &b) const
    {
        return x * b.y - y * b.x;
    }
    bool operator<(const Point &b) const
    {
        return x < b.x || (x == b.x && y < b.y);
    }
    void input()
    {
        scanf("%d%d", &x, &y);
    }
} p[MAXN], ch[MAXN];

int n, m;
double ans;

void add(Point p)
{
    int m = n;
    while ((m - 1) >= 1 && ((ch[m - 1] - ch[m - 2]) ^ (p - ch[m - 2])) <= 0)
    {
        m--;
    }
    ch[m++] = p;
    n = m;
}

void getHull()
{
    n = 0;
    for (int i = 1; i <= m; i++)
    {
        add(p[i]);
    }
    for (int i = m - 1, t = n + 1; i >= 1; i--)
    {
        add(p[i]);
    }
    n--;
}

int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        p[i].input();
    }
    getHull();
    for (int i = 1; i <= n; i++)
    {
        ans += sqrt((double)(ch[i] - ch[i + 1]).len2());
    }
    printf("%.2lf\n", ans);
    return 0;
}