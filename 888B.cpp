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

const int maxN = 1e5 + 10;

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

int n, sh, sv;
string s;

int main() {
    cin >> n;
    cin >> s;
    REPU(i, n) {
        if (s[i] == 'L') --sh;
        if (s[i] == 'R') ++sh;
        if (s[i] == 'U') ++sv;
        if (s[i] == 'D') --sv;
    }
    cout << n - (int) abs(sh) - (int) abs(sv) << endl;
}
