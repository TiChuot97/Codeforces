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

const int maxN = 5e5 + 10, oo = 23041997;
const double eps = 1e-5;

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

int n, m, q, par[maxN], dia[maxN], flag, visited[maxN];
vector < int > adj[maxN];

void dfs(int u, int d, int& max_u, int& max_d) {
    visited[u] = flag;
    if (max_d < d) {
        max_d = d;
        max_u = u;
    }
    REPU(i, adj[u].size()) {
        int v = adj[u][i];
        if (visited[v] == flag) continue;
        dfs(v, d + 1, max_u, max_d);
    }
}

int get_root(int u) {
    return (u == par[u]) ? u : (par[u] = get_root(par[u]));
}

void join(int u, int v) {
    u = get_root(u);
    v = get_root(v);
    if (u == v) return;
    par[u] = v;
    int new_dia = (dia[u] + 1) / 2 + (dia[v] + 1) / 2 + 1;
    dia[v] = max(new_dia, max(dia[u], dia[v]));
}

int main() {
    cin >> n >> m >> q;

    FORU(i, 1, n) par[i] = i;

    FORU(i, 1, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].PB(v);
        adj[v].PB(u);
        join(u, v);
    }

    FORU(i, 1, n)
        if (get_root(i) == i) {
            int u = i, v, d = 0;
            ++flag; dfs(i, 0, u, d);
            ++flag; dfs(u, 0, v, d);
            dia[i] = d;
        }

    FORU(i, 1, q) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int u; scanf("%d", &u);
            printf("%d\n", dia[get_root(u)]);
        }
        else {
            int u, v;
            scanf("%d %d", &u, &v);
            join(u, v);
        }
    }
}
