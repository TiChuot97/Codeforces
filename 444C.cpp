#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define first F
#define second S

void modify(int k, int l, int r, int x) {
    if (g[k]) {
        p[k] += abs(x - g[k]);

    }
}

void update(int k, int l, int r, int i, int j, int x) {
    if (j < l || r < i) return;
    if (i <= l && r <= j) {
        modify(k, l, r, x);
        return;
    }
    int mid = (l + r) >> 1;
    update(k * 2, l, mid, i, j, x);
    update(k * 2 + 1, mid + 1, r, i, j, x);
}

int main() {
    cin >> n >> q;
    build(1, 1, n);
    foru(i, 1, q) {
        scanf("%d %d %d", &t, &l, &r);
        if (t == 1) {
            scanf("%d", &x);
            update(1, 1, n, l, r, x);
        }
        else {
            res = get(l, r);
            cout << res << endl;
        }
    }
}
