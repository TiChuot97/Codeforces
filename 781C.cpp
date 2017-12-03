#include <iostream>
:x
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

const int maxN = 200010;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair

int n, m, k, T, check[maxN];
vector < int > adj[maxN], ans;

void dfs(int u) {
    repu(i, adj[u].size()) {
        int v = adj[u][i];
        if (check[v]) continue;
        check[v] = 1;
        ans.push_back(v);
        dfs(v);
        ans.push_back(u);
    }
}

int main() {
    cin >> n >> m >> k;
    T = ((2 * n) / k) + ((2 * n) % k != 0);
    foru(i, 1, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans.push_back(1);
    check[1] = 1;
    dfs(1);
    int l = 0;
    foru(i, 1, k) {
        int p = min(T, (int) ans.size() - l);
        if (p <= 0) cout << 1 << " " << 1 << endl;
        else {
            printf("%d ", p);
            foru(j, l, l + p - 1) printf("%d ", ans[j]);
            cout << endl;
            l += p;
        }
    }
}
