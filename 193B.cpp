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

const int maxN = 40;
const long long oo = 1e15;

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

int n, u, r, a[maxN], b[maxN], k[maxN], p[maxN], c[maxN];
LL res;

void brute_force(int i, int j) {
    if (((i - u - 1) % 2) == 0) { 
        LL tmp = 0;
        FORU(t, 1, n) 
            tmp += 1ll * a[t] * k[t];
        res = max(res, tmp);
        if (i > u) return;
    }
    if (j != 1) {
        FORU(t, 1, n) a[t] ^= b[t];
        brute_force(i + 1, 1);
        FORU(t, 1, n) a[t] ^= b[t];
    }
    FORU(t, 1, n) c[t] = a[t];
    FORU(t, 1, n) a[t] = c[p[t]] + r;
    brute_force(i + 1, 2);
    FORU(t, 1, n) c[t] = a[t];
    FORU(t, 1, n) a[p[t]] = c[t] - r;
}

int main() {
    res = -oo;
    cin >> n >> u >> r;
    FORU(i, 1, n) cin >> a[i];
    FORU(i, 1, n) cin >> b[i];
    FORU(i, 1, n) cin >> k[i];
    FORU(i, 1, n) cin >> p[i];
    brute_force(1, 0);
    cout << res << endl;
}
