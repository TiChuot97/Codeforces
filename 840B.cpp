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

using namespace std;

const int maxN = 3e5 + 10;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int deg[maxN], d[maxN], check[maxN], visited[maxN], flag, m, n, res, pre_v[maxN], pre_e[maxN], q[maxN];
vector < PINT > adj[maxN];

int bfs(int s) {
    int l = 1, r = 1; q[1] = s;
    visited[s] = ++flag;
    while (l <= r) {
        int u = q[l++];
        REPU(i, adj[u].size()) {
            int v = adj[u][i].F;
            int w = adj[u][i].S;
            if (visited[v] == flag) continue;
            pre_v[v] = u;
            pre_e[v] = w;
            visited[v] = flag;
            if (d[v] == -1 || deg[v] != d[v]) return v;
            q[++r] = v;
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    FORU(i, 1, n) scanf("%d", &d[i]);
    FORU(i, 1, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].PB(MP(v, i));
        adj[v].PB(MP(u, i));
    }
    FORU(i, 1, n)
        if (d[i] != - 1 && deg[i] != d[i]) {
            int j = bfs(i);
            if (j == -1) { cout << -1; return 0; }
            while (j != i) {
                check[pre_e[j]] = 1 - check[pre_e[j]];
                deg[j] = 1 - deg[j];
                j = pre_v[j];
                deg[j] = 1 - deg[j];
            }
        }
    FORU(i, 1, m) res += check[i];
    cout << res << endl;
    FORU(i, 1, m)
        if (check[i]) printf("%d\n", i);
}
