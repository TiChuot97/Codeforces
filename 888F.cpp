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

using namespace std;

const int maxN = 510, modP = 1e9 + 7;

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

int f[maxN][maxN][2], res, n, a[maxN][maxN];

int dp(int i, int j, int t) {
    if (f[i][j][t] != -1) return f[i][j][t];
    if (i == j - 1 && t) return 1;
    if (i == j) return 1;

    int tmp = 0;
    FORU(k, i + 1, j - 1)
        if (a[i][k])
            tmp = (tmp + (1ll * dp(i, k, 1) * dp(k, j, t)) % modP) % modP;

    if (t) tmp = (tmp + dp(i + 1, j, 0)) % modP;
    if (a[i][j] && !t)
        tmp = (tmp + dp(i, j, 1)) % modP;

    return (f[i][j][t] = tmp);
}

int main() {
    cin >> n;
    FORU(i, 1, n)
        FORU(j, 1, n)
            scanf("%d", &a[i][j]);

    memset(f, 255, sizeof(f));
    cout << dp(1, n, 0) << endl;
}
