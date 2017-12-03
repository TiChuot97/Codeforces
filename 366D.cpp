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

const int maxN = 1010;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < ll, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int n, m, visited[maxN], w[maxN][maxN], q[maxN], res, max_v;
vector < int > adj[maxN];

struct edge {
    int u, v, l, r;
};

edge e[3 * maxN];

struct comp_heap_r {
    bool operator () (edge a, edge b) {
        return b.r < a.r;
    }
};

struct comp_heap_l {
    bool operator () (edge a, edge b) {
        return b.l < a.l;
    }
};

priority_queue < edge, vector < edge >, comp_heap_r> heap_r;
priority_queue < edge, vector < edge >, comp_heap_l> heap_l;

bool bfs() {
    FORU(i, 1, n) visited[i] = false;
    int l = 1, r = 1;
    q[1] = 1; visited[1] = true;
    while (l <= r) {
        int u = q[l++];
        for (auto v : adj[u]) {
            if (w[u][v] && !visited[v]) {
                if (v == n) return true;
                visited[v] = true;
                q[++r] = v;
            }
        }
    }
    return false;
}

bool check(int len) {
    while (!heap_l.empty()) heap_l.pop();
    while (!heap_r.empty()) heap_r.pop();
    FORU(i, 1, m) heap_l.push(e[i]);
    FORU(i, 1, n)
        FORU(j, 1, n) w[i][j] = 0;
    FORU(i, 1, max_v - len + 1) {
        int l = i, r = i + len - 1;
        bool added = false;
        while (!heap_l.empty() && heap_l.top().l <= l) {
            auto min_e = heap_l.top();
            heap_l.pop();
            if (min_e.r < r) continue;
            added = true;
            heap_r.push(min_e);
            ++w[min_e.u][min_e.v];
            ++w[min_e.v][min_e.u];
        }
        while (!heap_r.empty() && heap_r.top().r < r) {
            auto min_e = heap_r.top();
            heap_r.pop();
            --w[min_e.u][min_e.v];
            --w[min_e.v][min_e.u];
        }
        if (added && bfs()) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    FORU(i, 1, m) {
        scanf("%d %d %d %d", &e[i].u, &e[i].v, &e[i].l, &e[i].r);
        max_v = max(max_v, e[i].r);
        adj[e[i].u].PB(e[i].v);
        adj[e[i].v].PB(e[i].u);
    }
    int l = 0, r = max_v;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) res = mid, l = mid + 1;
        else r = mid - 1;
    }
    if (res) cout << res << endl;
    else cout << "Nice work, Dima!" << endl;
}
