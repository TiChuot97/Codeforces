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

const int maxN = 1010;
long long oo = 100000000000000ll;

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

int n, m, check[maxN], start, target;
LL d[maxN], c[maxN][maxN];
vector < PINT > adj[maxN];

struct Cmp {
    bool operator () (PINT a, PINT b) {
        return a.S > b.S;
    }
};

priority_queue < PINT, vector < PINT >, Cmp > heap;

void dijkstra(int s) {
    FORU(i, 1, n) d[i] = oo, check[i] = 0;
    d[s] = 0; heap.push({s, d[s]});
    while (!heap.empty()) {
        PINT p = heap.top(); heap.pop();
        while (check[p.F] && !heap.empty()) {
            p = heap.top();
            heap.pop();
        }
        if (check[p.F]) continue;
        int u = p.F; check[u] = 1;
        REPU(i, adj[u].size()) {
            int v = adj[u][i].F;
            int w = adj[u][i].S;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                heap.push({v, d[v]});
            }
        }
    }
}

int main() {
    cin >> n >> m >> start >> target;
    FORU(i, 1, m) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].PB({v, w});
        adj[v].PB({u, w});
    }

    FORU(i, 1, n) {
        dijkstra(i);
        FORU(j, 1, n)
            c[i][j] = d[j];
    }

    FORU(i, 1, n) {
        int t, k; 
        scanf("%d %d", &t, &k);
        adj[i].clear();
        FORU(j, 1, n)
            if (c[i][j] <= t) adj[i].PB({j, k});
    }

    dijkstra(start);
    cout << ((d[target] == oo) ? -1 : d[target]);
}
