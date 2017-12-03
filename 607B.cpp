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

const int oo = 23041997, maxN = 510, modP = 1e9 + 7;

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

int n, f[maxN][maxN], a[maxN];

int main() {
    cin >> n;
    FORU(i, 1, n) scanf("%d", &a[i]);
    FORU(i, 1, n) f[i][i] = 1;
    FORU(i, 1, n - 1) 
        f[i][i + 1] = (a[i] == a[i + 1]) ? 1 : 2;
    FORU(l, 3, n) 
        FORU(i, 1, n - l + 1) {
            int j = i + l - 1;
            f[i][j] = oo;
            FORU(t, i, j) 
                f[i][j] = min(f[i][j], f[i][t] + f[t + 1][j]);
            if (a[i] == a[j])
                f[i][j] = min(f[i][j], f[i + 1][j - 1]);
        }
    cout << f[1][n];
}
