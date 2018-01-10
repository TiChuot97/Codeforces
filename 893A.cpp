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

int n;

int main() {
    cin >> n;
    int p1 = 1, p2 = 2, s = 3;
    FORU(i, 1, n) {
        int w; cin >> w;
        if (w == s) {
            cout << "NO";
            return 0;
        }
        if (w == p1) swap(p2, s);
        else swap(p1, s);
    }
    cout << "YES" << endl;
}
