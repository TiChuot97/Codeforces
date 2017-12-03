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

const int maxN = 200100, modP = 1e9 + 7;
const double PI = acos(-1);

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pint pair < ll, int >

int a[maxN], n, d[maxN], d_leaf, parent[maxN];
vector < int > adj[maxN];
map < int, int > mmap;
ll res;

void dfs(int u) {
    //for (auto v : adj[u]) {
    repu(i, adj[u].size()) {
        int v = adj[u][i];
        if (parent[u] == v) continue;
        d[v] = d[u] + 1;
        parent[v] = u;
        dfs(v);
    }
    if (u != 1 && adj[u].size() == 0)
        d_leaf = d[u];
}

int main() {
    cin >> n;
    foru(i, 1, n)
        scanf("%d", &a[i]);
    foru(i, 2, n) {
        int u;
        scanf("%d", &u);
        adj[u].push_back(i);
    }
    dfs(1);
    int sum = 0;
    foru(i, 1, n)
        if (d[i] % 2 == d_leaf % 2) sum ^= a[i];
        else mmap[a[i]]++;
    foru(i, 1, n)
        if (d[i] % 2 == d_leaf % 2)
            res = res + mmap[sum ^ a[i]];
    if (sum == 0) {
        int num = 0;
        foru(i, 1, n)
            if (d[i] % 2 == d_leaf % 2) ++num;
        res += (1ll * num * (num - 1)) / 2;
        num = n - num;
        res += (1ll * num * (num - 1)) / 2;
    }
    cout << res;
}
