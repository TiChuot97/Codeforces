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

const int maxN = 2e5 + 10, maxV = 1e6 + 10;

using namespace std;

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

int n, q, a[maxN], cnt[maxV];
LL res, ans[maxN];

struct Query {
    int l, r, p;
};

Query query[maxN];

bool cmp_mo(Query i, Query j) {
    int s = (int) sqrt(n);
    return ((i.l - 1) / s < (j.l - 1) / s || ((i.l - 1) / s == (j.l - 1) / s && i.r < j.r));
}

void add(int v, int t) {
    res -= 1ll * v * cnt[v] * cnt[v];
    cnt[v] += t;
    res += 1ll * v * cnt[v] * cnt[v];
}

int main() {
    cin >> n >> q;
    FORU(i, 1, n) scanf("%d", &a[i]);
    FORU(i, 1, q) {
        scanf("%d %d", &query[i].l, &query[i].r);
        query[i].p = i;
    }

    sort(query + 1, query + q + 1, cmp_mo);

    int l = 0, r = 0;
    FORU(i, 1, q) {
        while (r < query[i].r) ++r, add(a[r], 1);
        while (r > query[i].r) add(a[r], -1), --r;
        while (l < query[i].l) add(a[l], -1), ++l;
        while (l > query[i].l) --l, add(a[l], 1);
        ans[query[i].p] = res;
    }

    FORU(i, 1, q) cout << ans[i] << endl;
}
