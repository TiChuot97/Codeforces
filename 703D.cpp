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

const int maxN = 1000010, maxL = 10010, oo = 1000000000;
const double PI = acos(-1);

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pint pair < int, int >

int n, m, s[maxN], a[maxN], l[maxN], r[maxN], pre[maxN], res[maxN], t[maxN];
map < int, int > mmap;

struct query {
    int p, v, t;
};

query c[3 * maxN];

bool cmp(query i, query j) {
    return (i.p < j.p || (i.p == j.p && i.t < j.t));
}

void update(int x, int v) {
    if (x == 0) {
        t[0] ^= v;
        return;
    }
    while (x <= n) {
        t[x] ^= v;
        x += (x & (-x));
    }
}

int get(int x) {
    int tmp = t[0];
    while (x) {
        tmp ^= t[x];
        x -= (x & (-x));
    }
    return tmp;
}

int main() {
    cin >> n;
    int num = 0;
    foru(i, 1, n) {
        scanf("%d", &a[i]);
        pre[i] = mmap[a[i]];
        mmap[a[i]] = i;
        c[++num].p = i;
        c[num].v = a[i];
        c[num].t = 1;
        s[i] = s[i - 1] ^ a[i];
    }
    cin >> m;
    foru(i, 1, m) {
        scanf("%d %d", &l[i], &r[i]);
        c[++num].p = l[i] - 1; c[num].v = i; c[num].t = 2;
        c[++num].p = r[i]; c[num].v = i; c[num].t = 2;
    }
    sort(c + 1, c + num + 1, cmp);
    foru(i, 1, num) {
        if (c[i].t == 1)
            update(pre[c[i].p], a[c[i].p]);
        else {
            res[c[i].v] ^= get(l[c[i].v] - 1);
        }
    }
    foru(i, 1, m) {
        res[i] ^= (s[r[i]] ^ s[l[i] - 1]);
        printf("%d\n", res[i]);
    }
}
