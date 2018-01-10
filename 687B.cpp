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

const int modP = 1e9 + 7, maxN = 5010;

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

int n, k;

// Find a * x + b * y = gcd(a, b) = d
//      q = a / b; r = a % b
//      b * x1 + r * y1 = d
// =>   b * x1 + (a - q * b) * y1 = d
// =>   b * x1 + a * y1 - q * b * y1 = d
// =>   a * y1 + (x1 - q * y1) * b = d
// =>   x = y1, y = x1 - q * y1
//typedef LL long long;
pair < LL, LL > extended_gcd(LL a, LL b) {
    if (b == 0) return make_pair(1, 0);
    pair < LL, LL > xy = extended_gcd(b, a % b);
    return make_pair(xy.second, xy.first - (a / b) * xy.second);
}

LL inverse_modulo(LL a, LL m) {
    pair < LL, LL > xy = extended_gcd(a, m);
    return xy.first;
}

int main() {
    sieve();
    cin >> n >> k;
    FORU(i, 1, n) {
        int x; scanf("%d", &x);
        c.clear();
        factorize(x, c);
        int num = 0;
        REPU(i, c.size())
            if (
    }
}
