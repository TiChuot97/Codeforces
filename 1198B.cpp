#include <iostream>

using namespace std;

const int maxN = 2e5 + 10;

int t[4 * maxN], g[4 * maxN], a[maxN], n, q;

void lazy_update(int k, int l, int r) {
    if (l == r) t[k] = max(t[k], g[k]);
    else {
        g[k * 2] = max(g[k * 2], g[k]);
        g[k * 2 + 1] = max(g[k * 2 + 1], g[k]);
    }
    g[k] = 0;
}

void update(int k, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    lazy_update(k, l, r);
    if (l == r) { t[k] = v; return; }
    int mid = (l + r) >> 1;
    update(k * 2, l, mid, i, v);
    update(k * 2 + 1, mid + 1, r, i, v);
}

void get(int k, int l, int r) {
    lazy_update(k, l, r);
    if (l == r) { a[l] = t[k]; return; }
    int mid = (l + r) >> 1;
    get(k * 2, l, mid);
    get(k * 2 + 1, mid + 1, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]), update(1, 1, n, i, a[i]);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int p, x; scanf("%d %d", &p, &x);
            update(1, 1, n, p, x);
        } else {
            int x; scanf("%d", &x);
            g[1] = max(g[1], x);
        }
    }
    get(1, 1, n);
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
}
