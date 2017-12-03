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

const int maxN = 1e3 + 10;

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

vector < int > a, b, sa, sb;
int n, res, m;

void read_input(int num, vector < int >& a) {
    FORU(i, 1, num) {
        int x; scanf("%d", &x);
        a.PB(x);
    }
}

void get_sum(vector < int >& c, vector < int >& s) {
    REPU(i, 1 << c.size()) {
        int sum = 0;
        REPU(j, c.size())
            if (BIT(i, j)) sum = (sum + c[j]) % m;
        s.PB(sum);
    }
}

int main() {
    cin >> n >> m;
    read_input(n / 2, a);
    read_input(n - (n / 2), b);

    get_sum(a, sa);
    get_sum(b, sb);
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());

    int j = sb.size() - 1; res = 0;
    REPU(i, sa.size()) {
        while (j >= 0 && sa[i] + sb[j] >= m) --j;
        if (j >= 0)
            res = max(res, sa[i] + sb[j]);
        res = max(res, (sa[i] + sb.back()) % m);
    }
    cout << res;
}
