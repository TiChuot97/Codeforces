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

const int maxN = 2e5 + 10;

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

int n, a[maxN], s[maxN];
LL f[maxN];

int main() {
    cin >> n;
    FORU(i, 1, n) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    f[n] = s[n];
    LL max_f = s[n];
    FORD(i, n - 1, 1) {
        max_f = max(max_f, s[i] - f[i + 1]);
        f[i] = max_f;
    }
    cout << f[2];
}
