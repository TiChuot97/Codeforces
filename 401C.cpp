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

const int maxN = 5e6 + 10;

using namespace std;

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

int n, m, f[maxN];

int main() {
    cin >> n >> m;
    if ((n + 1) * 2 < m || m < n - 1) {
        cout << -1;
        return 0;
    }
    FORU(i, 1, n + 2 * (n + 1)) f[i] = -1;
    for (int i = 3; i <= 3 * n + 2; i += 3) {
        f[i] = 0;
        if (m)
            f[i + 1] = 1, --m;
    }
    for (int i = 1; i <= 3 * n + 2; ++i) {
        if (!m) break;
        if (f[i] == -1) f[i] = 1, --m;
    }
    for (int i = 1; i <= 3 * n + 2; ++i)
        if (f[i] >= 0)
            printf("%d", f[i]);
}
