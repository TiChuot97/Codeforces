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

const int maxN = 2e5 + 10, maxC = 110;

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

int t[4 * maxN][maxC], n, a[maxN], q, marked[4 * maxN];

void init(int k) {
    marked[k] = 0;
    FORU(i, 1, 100) t[k][i] = i;
}

void build(int k, int l, int r) {
    init(k);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
}

void lazy_update(int k) {
    FORU(i, 1, 100) {
        t[k * 2][i] = t[k][t[k * 2][i]];
        t[k * 2 + 1][i] = t[k][t[k * 2 + 1][i]];
    }
    init(k);
}

void print(int k) {
    FORU(i, 1, 5) cout << t[k][i] << " ";
    cout << endl;
}

void update(int k, int l, int r, int i, int j, int x, int y) {
    if (j < l || r < i) return;
    if (l != r)
        lazy_update(k);
    if (l == r) {
        FORU(i, 1, 100)
            if (t[k][i] == x) t[k][i] = y;
        return;
    }
    if (i <= l && r <= j) {
        t[k][x] = y;
        return;
    }
    int mid = (l + r) >> 1;
    update(k * 2, l, mid, i, j, x, y);
    update(k * 2 + 1, mid + 1, r, i, j, x, y);
}

int get(int k, int l, int r, int i, int x) {
    if (i < l || r < i) return 0;
    if (l == r) return t[k][x];
    int mid = (l + r) >> 1;
    if (i <= mid)
        return t[k][get(k * 2, l, mid, i, x)];
    return t[k][get(k * 2 + 1, mid + 1, r, i, x)];
}

int main() {
    cin >> n;
    FORU(i, 1, n) scanf("%d", &a[i]);
    cin >> q;
    build(1, 1, n);
    FORU(i, 1, q) {
        int l, r, x, y;
        scanf("%d %d %d %d", &l, &r, &x, &y);
        update(1, 1, n, l, r, x, y);
    }
    FORU(i, 1, n) 
        printf("%d ", get(1, 1, n, i, a[i]));
}
