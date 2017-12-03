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

const int maxN = 5010, oo = 23041997;
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

int m, n;

int main() {
    cin >> m >> n;

    if (m == 0) {
        cout << 0 << " " << 1 << endl;
        cout << 0 << " " << n << endl;
        cout << 0 << " " << 0 << endl;
        cout << 0 << " " << n - 1 << endl;
        return 0;
    }

    if (n == 0) {
        cout << 1 << " " << 0 << endl;
        cout << m << " " << 0 << endl;
        cout << 0 << " " << 0 << endl;
        cout << m - 1 << " " << 0 << endl;
        return 0;
    }

    cout << 0 << " " << 0 << endl;
    cout << m << " " << n << endl;
    if (m < n) {
        cout << m << " " << 0 << endl;
        cout << 0 << " " << n << endl;
    }
    else {
        cout << 0 << " " << n << endl;
        cout << m << " " << 0 << endl;
    }
}
