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

using namespace std;

const int maxn = 2e5 + 10;
const long long oo = 1e15;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pint pair < int, int >
#define bit(x, i) ((x >> i) & 1)
#define num_set_bit __builtin_popcountll

unordered_map < int, int > parent[maxn], res[maxn];
int n, m, q, flag, check[maxn];
vector < int > color[maxn];

int find_root(int u, int w) {
    if (parent[w].find(u) == parent[w].end()) return u;
    ++d;
    if (parent[w][u] == u) return u;
    return (parent[w][u] = find_root(parent[w][u], w, d));
}

void join(int u, int v, int w) {
    int du = 0, dv = 0;
    auto root_u = find_root(u, w, du);
    auto root_v = find_root(v, w, dv);
    if (root_u == root_v) return;
}

int main() {
    cin >> n >> m;
    repu(i, m) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        color[u].pb(w);
        color[v].pb(w);
        join(u, v, w);
    }
    cin >> q;
    repu(i, q) {
        int u, v, d;
        scanf("%d %d", &u, &v);
        if (color[u].size() > color[v].size() ||
            (color[u].size() == color[v].size() && u > v)) swap(u, v);
        if (res[u].find(v) == res[u].end()) {
            res[u][v] = 0;
            ++flag;
            for (auto c : color[u]) {
                if (check[c] == flag) continue;
                check[c] = flag;
                res[u][v] += (find_root(u, c, d) == find_root(v, c, d));
            }
        }
        printf("%d\n", res[u][v]);
    }
}
