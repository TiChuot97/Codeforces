#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 100010, maxLog = 20, Log = 18;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define first F
#define second S

int n, m, parent[maxN], ancestor[maxN][maxLog], pos[maxN], P;
vector < int > q, adj[maxN];

void bfs() {
    int l = 0;
    while (l < q.size()) {
        int u = q[l++];
        pos[u] = l - 1;
        for (auto& v : adj[u]) {
            q.push_back(v);
        }
    }
}

void build() {
    foru(i, 1, n) ancestor[i][0] = parent[i];
    foru(j, 1, Log)
        foru(i, 1, n)
            ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
}

int p_ancestor(int u, int p) {
    ford(j, Log, 0)
        if ((p >> j) & 1)
            u = ancestor[u][j];
    return u;
}

int main() {
    cin >> n;
    foru(v, 1, n) {
        int u;
        scanf("%d", &u);
        if (u == 0) q.push_back(v);
        else adj[u].push_back(v);
        parent[v] = u;
    }
    bfs();
    build();
    cin >> m;
    foru(i, 1, m) {
        int v;
        scanf("%d %d", &v, &P);
        if (p_ancestor(v, P) == 0) printf("0 ");
        else {
            auto it_l = lower_bound(q.begin(),
                q.begin() + pos[v] + 1,
                v,
                [](int u, int v) {
                return p_ancestor(u, P) != p_ancestor(v, P);
            });
            auto it_r = lower_bound(
                q.begin() + pos[v],
                q.end(),
                v,
                [](int u, int v) {
                return p_ancestor(u, P) == p_ancestor(v, P);
            });

            auto l = it_l - q.begin();
            auto r = it_r - q.begin() - 1;
            printf("%d ", (int) (r - l));
        }
    }
}
