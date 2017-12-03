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
const int maxN = 21, modP = 1e9, oo = 2000000000, LCM = 2520;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second

int test, label[LCM + 1], val[50], c[maxN], check[maxN][2][50][LCM + 1], flag;
ll l, r, res, f[maxN][2][50][LCM + 1];

int gcd(int i, int j) {
    if (j == 0) return i;
    return gcd(j, i % j);
}

int lcm(int i, int j) {
    return (i * j) / gcd(i, j);
}

void init() {
    foru(i, 1, (1 << 9) - 1) {
        int tmp = 1;
        repu(j, 9)
            if ((i >> j) & 1) tmp = lcm(tmp, j + 1);
        if (!label[tmp]) {
            label[tmp] = ++label[0];
            val[label[tmp]] = tmp;
        }
    }
}

ll dp(int i, bool ok, int curr, int mod) {
    if (check[i][ok][curr][mod] == flag)
        return f[i][ok][curr][mod];
    if (i > c[0]) 
        return ((mod % val[curr]) == 0);
    check[i][ok][curr][mod] = flag;
    f[i][ok][curr][mod] = 0;
    ll tmp = dp(i + 1, (ok || 0 < c[i]), curr, (mod * 10) % LCM);
    int c_max = ok ? 9 : c[i];
    foru(t, 1, c_max)
        tmp += dp(i + 1, (ok || (t < c[i])), label[(val[curr] * t) / gcd(val[curr], t)], (mod * 10 + t) % LCM);
    return (f[i][ok][curr][mod] = tmp);
}

void get_num(ll x) {
    c[0] = 0;
    while (x) c[++c[0]] = x % 10, x /= 10;
    reverse(c + 1, c + c[0] + 1);
}

int main() {
    cin >> test;
    init();
    while (test--) {
        cin >> l >> r;
        --l;
        
        get_num(r); ++flag;
        res = dp(1, false, 1, 0) - 1;

        get_num(l); ++flag;
        res = res - (dp(1, false, 1, 0) - 1);
        cout << res << endl;
    }
}
