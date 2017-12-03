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

const int maxN = 1e5 + 10, oo = 23041997;
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

struct Cmp {
    bool operator () (LL a, LL b) {
        return b < a;
    }
};

priority_queue < LL, vector < LL >, Cmp > heap;

LL res;
int n;

int main() {
    cin >> n;
    FORU(i, 1, n) {
        int x; scanf("%d", &x);
        heap.push(x);
    }

    while (heap.size() != 1) {
        LL sum = 0;
        if (heap.size() % 2 == 0) heap.push(0);
        FORU(i, 1, 3)
            if (!heap.empty()) {
                sum += heap.top();
                heap.pop();
            }
        heap.push(sum);
        res += sum;
    }
    
    cout << res;
}
