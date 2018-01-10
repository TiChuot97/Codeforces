#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <deque>
#include <stack>

const int maxN = 2e5 + 10;

using namespace std;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define ULL unsigned long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int n, parent[maxN], q[maxN], deg[maxN];
vector < int > d[3], adj[maxN];
LL res;

void init() {
    REPU(i, n)
        REPU(j, 3) d[j].PB(0);
}

void dfs(int u, vector < int > &depth) {
    REPU(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v - 1] = depth[u - 1] + 1;
        dfs(v, depth);
    }
}

void build(int root, vector < int > &depth) {
    parent[root] = 0;
    dfs(root, depth);
}

bool on_path(int u, int w) {
    return (d[1][u - 1] + d[2][u - 1] == d[1][w - 1]);
}

int main() {
    cin >> n;
    FORU(i, 1, n - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].PB(v);
        adj[v].PB(u);
        ++deg[u];
        ++deg[v];
    }

    init();
    int u = 1, v = 1, w = 1;
    FORU(i, 1, n)
        if (adj[i].size() == 1) {
            u = i;
            break;
        }

    build(u, d[0]);
    FORU(i, 1, n)
        if (d[0][i - 1] > d[0][v - 1]) v = i;
    build(v, d[1]);
    FORU(i, 1, n)
        if (i != v && d[1][i - 1] >= d[1][w - 1]) w = i;
    build(w, d[2]);
    FORU(i, 1, n)
        if (!on_path(i, w)) 
            res += max(d[1][i - 1], d[2][i - 1]);
    res += (1ll * d[1][w - 1] * (d[1][w - 1] + 1)) / 2;

    cout << res << endl;
    int l = 1, r = 0;
    FORU(i, 1, n)
        if (!on_path(i, w) && deg[i] == 1) q[++r] = i;
    while (l <= r) {
        int u = q[l++];
        --deg[parent[u]];
        int t = (d[1][u - 1] > d[2][u - 1]) ? v : w;
        cout << u << " " << t << " " << u << endl;
        if (deg[parent[u]] == 1 && !on_path(parent[u], w))
            q[++r] = parent[u];
    }

    while (v != w) {
        cout << v << " " << w << " " << v << endl;
        v = parent[v];
    }
}
