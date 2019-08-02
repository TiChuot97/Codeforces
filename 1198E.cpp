#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int maxN = 210, oo = 1e9 + 10;

typedef vector < int > vi;
typedef map < int, int > mi;

int c[maxN][maxN], f[maxN][maxN], q[maxN], check[maxN], flag, m, n, pre[maxN], source, target;
int x1[maxN], x2[maxN], y1[maxN], y2[maxN];
vi lset, rset, adj[maxN];
long long flow;
mi idxl, idxr;

void add_edge(int u, int v, int w) {
    c[u][v] = w;
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool find_path() {
    int l = 1, r = 1; ++flag;
    q[1] = source; check[source] = flag;
    while (l <= r) {
        int u = q[l++];
        for (auto v : adj[u])
            if (check[v] != flag && c[u][v] > f[u][v]) {
                pre[v] = u;
                check[v] = flag;
                if (v == target) return true;
                q[++r] = v;
            }
    }
    return false;
}

void augment() {
    int v = target, delta = oo;
    while (v != source) {
        int u = pre[v];
        delta = min(c[u][v] - f[u][v], delta);
        v = u;
    }
    v = target; flow += delta;
    while (v != source) {
        int u = pre[v];
        f[u][v] += delta;
        f[v][u] -= delta;
        v = u;
    }
}

void remove_dup(vi& x, mi& idx) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < x.size(); ++i) idx[x[i]] = i;
}

int main() {
    cin >> n >> m;
    lset.push_back(1); lset.push_back(n + 1);
    rset.push_back(1); rset.push_back(n + 1);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
        lset.push_back(x1[i]);
        lset.push_back(x2[i] + 1);
        rset.push_back(y1[i]);
        rset.push_back(y2[i] + 1);
    }
    remove_dup(lset, idxl);
    remove_dup(rset, idxr);

    source = 0; target = lset.size() + rset.size() + 1;
    for (int i = 0; i + 1 < lset.size(); ++i)
        add_edge(source, i + 1, lset[i + 1] - lset[i]);
    for (int i = 0; i + 1 < rset.size(); ++i)
        add_edge(i + lset.size() + 1, target, rset[i + 1] - rset[i]);
    for (int i = 0; i < m; ++i) {
        for (int il = idxl[x1[i]]; lset[il] <= x2[i]; ++il)
            for (int ir = idxr[y1[i]]; rset[ir] <= y2[i]; ++ir) {
                int w = min(lset[il + 1] - lset[il], rset[ir + 1] - rset[ir]);
                add_edge(il + 1, ir + lset.size() + 1, w);
            }
    }
    while (find_path()) augment();
    cout << flow << endl;
}
