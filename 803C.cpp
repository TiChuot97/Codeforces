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

const int maxN = 200010, maxL = 10010, oo = 1000000000;
const double PI = acos(-1);

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pint pair < ll, int >
#define ull unsigned long long

ll n, res;
ull k;

int main() {
    cin >> n >> k;
    res = -1;
    foru(i, 1, (int) sqrt(n)) {
        if ((n % i) == 0) {
            ll j = n / i;
            if (k + 1 <= (j * 2) / k) res = max(res, 1ll * i);
            if (k + 1 <= (i * 2) / k) res = max(res, 1ll * j);
        }
    }
    if (res == -1) { cout << res; return 0; }
    ll s = 0;
    for (long long i = 1; i <= k; ++i) {
        ll j = (i == k) ? (n / res) - s : i;
        printf("%lld ", j * res);
        s += i;
    }
}
