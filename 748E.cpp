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

const int maxN = 1e7 + 10, oo = 23041997;
const double eps = 1e-5;

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

int n, k, cnt[maxN];

int main() {
    cin >> n >> k;
    int l = 1e9, r = 0;
    LL sum = 0;
    FORU(i, 1, n) {
        int x; 
        scanf("%d", &x);
        sum += x;
        if (i > k && l >= x) continue;
        r = max(r, x); ++cnt[x];
        if (i <= k)
            l = min(l, x);
        else
            --cnt[l];
        while (cnt[l] == 0) ++l;
    }

    if (sum < k) { cout << -1; return 0; }

    if (n < k) cnt[0] = k - n, l = 0;

    while (l <= r) {
        if (r / 2 <= l) break;
        cnt[r / 2] += cnt[r];
        cnt[r - (r / 2)] += cnt[r];
        while (cnt[r] && l <= r) {
            int tmp = min(cnt[r], cnt[l]);
            cnt[r] -= tmp;
            cnt[l] -= tmp;
            if (cnt[l] == 0) ++l;
        }
        while (cnt[l] == 0 && l <= r) ++l;
        while (cnt[r] == 0 && l <= r) --r;
    }
    cout << l << endl;
}
