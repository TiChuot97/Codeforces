#include <iostream>
#include <cstdio>
#include <cstdio>
#include <utility>
#include <map>
#include <vector>

using namespace std;

const int maxN = 100010;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second

int n, m, check_flag, num_node, num[maxN], q[maxN], check[maxN], root;
vector< pair<int, int> > adj[maxN];
bool avail[maxN];
map<int, int> re;
ll res;

void build(int u) {
    ++num_node;
    check[u] = check_flag;
    num[u] = 1;
    repu(i, adj[u].size()) {
        int v = adj[u][i].F;
        if (check[v] == check_flag || !avail[v]) continue;
        build(v);
        num[u] += num[v];
    }
}

void inverse_modulo(int a, int b, int i) {
    if (b == 0) {
        p[i] = p[i - 2] + p[i - 1] * q[i - 2];
        return;
    }

}

int find_root(int u) {
    check[u] = check_flag;
    bool check_root = true;
    int sum = 0;
    repu(i, adj[u].size()) {
        int v = adj[u][i].F;
        if (check[v] == check_flag || !avail[v]) continue;
        int tmp = find_root(v);
        if (tmp) return tmp;
        check_root = (check_root && tmp <= num_node / 2);
        sum += num[v];
    }
    if (check_root && num_node - 1 - sum <= num_node / 2) 
        return u;
    else
        return 0;
}

void cal(int u, int val) {
    check[u] = check_flag;
    if (re.find((m - val) % m) != re.end()) 
        res += re[(m - val) % m];
    ++re[val];
    repu(i, adj[u].size()) {
        int v = adj[u][i].F;
        int w = adj[u][i].S;
        if (check[v] == check_flag || !avail[v]) continue;
        cal(v, (1ll * val * 10 + w) % m);
    }
}

int main() {
    cin >> n >> m;
    foru(i, 1, n - 1) {
        int u, v, c;
        scanf("%d %d %d\n", &u, &v, &c);
        ++u; ++v;
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }
    foru(i, 1, n) avail[i] = true;
    int l = 1, r = 1;
    q[1] = 1;
    while (l <= r) {
        int u = q[l++];
        ++check_flag;
        num_node = 0;
        build(u);
        ++check_flag;
        root = find_root(u);
        re.clear();
        ++check_flag;
        cal(root, 0);
        cout << root << " " << res << endl;
        avail[root] = false;
        repu(i, adj[root].size()) {
            int v = adj[root][i].F;
            if (avail[v])
                q[++r] = v;
        }
    }
    cout << res;
}   
