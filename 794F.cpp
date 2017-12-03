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
#define pint pair < ll, ll >

int digit[maxN], n, q;
ll t[10][5 * maxN], res;

void update(int p, int k, int l, int r, int i, int x) {
    if (i < l || i > r) return;
    if (l == r) {
        t[p][k] += x;
        return;
    }
    int mid = (l + r) >> 1;
    update(p, k * 2, l, mid, i, x);
    update(p, k * 2 + 1, mid + 1, r, i, x);
    t[p][k] = t[p][k * 2] + t[p][k * 2 + 1];
}

ll get(int p, int k, int l, int r, int i, int j) {
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return t[p][k];
    int mid = (l + r) >> 1;
    return (get(p, k * 2, l, mid, i, j) + get(p, k * 2 + 1, mid + 1, r, i, j));
}

int main() {
    cin >> n >> q;
    repu(i, 10) digit[i] = i;
    foru(i, 1, n) {
        int x;
        scanf("%d", &x);
        int t = 1;
        while (x) {
            update(x % 10, 1, 1, n, i, t);
            t *= 10; x /= 10;
        }
    }
    foru(i, 1, q) {
        int t, l, r, x, y;
        scanf("%d %d %d", &t, &l, &r);
        if (t == 1) {
            scanf("%d %d", &x, &y);
            repu(i, 10)
                if (digit[i] == x) digit[i] = y;
        }
        else {
            repu(i, 10)
                res += 1ll * digit[i] * get(i, 1, 1, n, l, r);
            cout << res << endl;
        }
    }
}
