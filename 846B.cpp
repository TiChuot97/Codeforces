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

const int maxN = 1e6 + 10;

#define FORU(i, l, r) for (int i = l; i <= r; ++i)
#define FORD(i, r, l) for (int i = r; i >= l; --i)
#define REPU(i, r) for (int i = 0; i < r; ++i)
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define PINT pair < int, int >
#define BIT(x, i) ((x >> i) & 1)
#define NUM_SET_BIT __builtin_popcountll

int n, k, m, a[maxN], res;

int main() {
    cin >> n >> k >> m;
    int s = 0;
    FORU(i, 1, k) cin >> a[i], s += a[i];
    sort(a + 1, a + k + 1);
    FORU(i, 0, n)
        if (s * i <= m) {
            int tmp = m - s * i;
            int ans = i * (k + 1);
            FORU(j, 1, k)
                if (a[j] * (n - i) <= tmp) {
                    tmp -= a[j] * (n - i);
                    ans += n - i;
                }
                else {
                    ans += tmp / a[j];
                    break;
                }
            res = max(res, ans);
        }
    cout << res;
}
