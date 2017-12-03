#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <queue>
#include <cstring>

using namespace std;
const int maxN = 5010, modP = 1e9 + 7, oo = 23041997;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second

int n, f[maxN][26], res, c[maxN][maxN];
char s[maxN];

int main() {
    scanf("%d\n", &n);
    scanf("%s", s);
    foru(i, 0, n) c[i][0] = 1, c[0][i] = 0;
    c[0][0] = 1;
    foru(i, 1, n)
        foru(j, 1, i)
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % modP;
    foru(i, 1, n) {
        foru(j, 1, i) {
            f[j][s[i - 1] - 'a'] = 0;
            repu(t, 26)
                if (t != s[i - 1] - 'a') {
                    f[j][s[i - 1] - 'a'] += f[j - 1][t];
                    f[j][s[i - 1] - 'a'] %= modP;
                }
        }
        f[1][s[i - 1] - 'a'] = 1;
    }
    foru(i, 1, n)
        repu(j, 26) {
            int tmp = (1ll * f[i][j] * c[n - 1][i - 1]) % modP;
            res = (res + tmp) % modP;
        }
    cout << res;
}
