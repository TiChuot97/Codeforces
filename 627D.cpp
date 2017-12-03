#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int maxN = 200010;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)

int n, k, a[maxN], f[maxN], full[maxN], cnt[maxN], num[maxN], res, parent[maxN], all_not;
vector <int> adj[maxN];

bool dp(int u, int val) {
    num[u] = 1;
    cnt[u] = 0;
    full[u] = 0;
    int max_1 = 0, max_2 = 0;
    repu(i, adj[u].size()) {
        int v = adj[u][i];
        if (v == parent[u]) continue;
        parent[v] = u;
        dp(v, val);
        cnt[u] += cnt[v];
        num[u] += num[v];
        if (num[v] == full[v]) full[u] += full[v];
        else
            if (max_1 < f[v]) max_2 = max_1, max_1 = f[v];
            else max_2 = max(max_2, f[v]);
    }
    f[u] = full[u] + max_1;
    if (a[u] < val) {
        f[u] = 0; 
        cnt[u]++; 
        return false;
    }
    if (f[u] + max_2 + (cnt[u] == all_not ? n - num[u] : 0) >= k) return true;
    return false;
}

int main() {
    cin >> n >> k;
    foru(i, 1, n) cin >> a[i];
    foru(i, 1, n - 1) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int l = 1, r = 5;
    while (l <= r) {
        int mid = (l + r) >> 1;
        all_not = 0;
        foru(i, 1, n) all_not += (a[i] < mid);
        if (dp(1, mid)) res = mid, l = mid + 1;
        else r = mid - 1;
        break;
    }
    cout << res;
}

