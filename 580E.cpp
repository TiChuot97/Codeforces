#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

const int maxN = 500010, BASE1 = 1e9 + 7, BASE2 = 1e9 + 3;
const long long BASE = 1e9 + 11;

ll sum1[maxN], sum2[maxN], sum_pow1[maxN], sum_pow2[maxN], POW1[maxN], POW2[maxN], val[maxN];
bool lazy[maxN];
char s[maxN];
int n, m, k;

void build(int k, int l, int r) {
    if (l == r) {
        val[k] = s[l - 1] - '0';
        sum1[k] = (val[k] * POW1[l - 1]) % BASE1;
        sum2[k] = (val[k] * POW2[l - 1]) % BASE2;
        return;
    }
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    sum1[k] = (sum1[k * 2] + sum1[k * 2 + 1]) % BASE1;
    sum2[k] = (sum2[k * 2] + sum2[k * 2 + 1]) % BASE2;
}

void lazy_update(int k, int v, int l, int r) {
    val[k] = v;
    sum1[k] = (POW1[l - 1] * sum_pow1[r - l] * v) % BASE1;
    sum2[k] = (POW2[l - 1] * sum_pow2[r - l] * v) % BASE2;
    lazy[k] = true;
}

void update(int k, int l, int r, int i, int j, int v) {
    if (j < l || i > r) return;
    if (i <= l && r <= j) {
        lazy_update(k, v, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    if (lazy[k]) {
        lazy_update(k * 2, val[k], l, mid);
        lazy_update(k * 2 + 1, val[k], mid + 1, r);
        lazy[k] = false;
    }
    update(k * 2, l, mid, i, j, v);
    update(k * 2 + 1, mid + 1, r, i, j, v);
    sum1[k] = (sum1[k * 2] + sum1[k * 2 + 1]) % BASE1;
    sum2[k] = (sum2[k * 2] + sum2[k * 2 + 1]) % BASE2;
}

ll get1(int k, int l, int r, int i, int j) {
    if (j < l || i > r) return 0;
    if (i <= l && j >= r) return sum1[k];
    int mid = (l + r) >> 1;
    if (lazy[k]) {
        lazy_update(k * 2, val[k], l, mid);
        lazy_update(k * 2 + 1, val[k], mid + 1, r);
        lazy[k] = false;
    }
    return (get1(k * 2, l, mid, i, j) + get1(k * 2 + 1, mid + 1, r, i, j)) % BASE1;
}

ll get2(int k, int l, int r, int i, int j) {
    if (j < l || i > r) return 0;
    if (i <= l && j >= r) return sum2[k];
    int mid = (l + r) >> 1;
    if (lazy[k]) {
        lazy_update(k * 2, val[k], l, mid);
        lazy_update(k * 2 + 1, val[k], mid + 1, r);
        lazy[k] = false;
    }
    return (get2(k * 2, l, mid, i, j) + get2(k * 2 + 1, mid + 1, r, i, j)) % BASE2;
}

int main() {
    scanf("%d %d %d\n", &n, &m, &k);
    POW1[0] = sum_pow1[0] = POW2[0] = sum_pow2[0] = 1;
    foru(i, 1, n) {
        POW1[i] = (POW1[i - 1] * BASE) % BASE1;
        POW2[i] = (POW2[i - 1] * BASE) % BASE2;
        sum_pow1[i] = (sum_pow1[i - 1] + POW1[i]) % BASE1;
        sum_pow2[i] = (sum_pow2[i - 1] + POW2[i]) % BASE2;
    }
    scanf("%s\n", s);
    build(1, 1, n);
    repu(j, m + k) {
        int t, l, r, d;
        scanf("%d %d %d %d", &t, &l, &r, &d);
        if (t == 1) update(1, 1, n, l, r, d);
        else {
            ll val1 = get1(1, 1, n, l, r - d);
            ll val2 = get1(1, 1, n, l + d, r);
            //cout << val1 * POW[d] << " " << val2 << endl;
            if ((val1 * POW1[d]) % BASE1 == val2) {
                val1 = get2(1, 1, n, l, r - d);
                val2 = get2(1, 1, n, l + d, r);
                if ((val1 * POW2[d]) % BASE2 == val2) puts("YES");
                else puts("NO");
            }
            else puts("NO");
        }
    }
}
