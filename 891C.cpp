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

const int maxN = 5e5 + 10;
const unsigned long long oo = 10000000000000000000ull;
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

deque < int > deqr[maxN], deqc[maxN];
int f[maxN][maxN], n, k;

int main() {
    scanf("%d %d\n", &n, &k);
    FORU(i, 1, n) {
        scanf("%s\n", s);
        FORU(j, 1, n) a[i][j] = (s[j - 1] == '#');
    }
    
    FORU(i, 1, n)
        FORU(j, 1, n) {
            f[i][j] = oo;
            while (deqr[i].front() < j - k) deqr[i].pop_front();
            while (deqc[j].front() < i - k) deqr[j].pop_front();
            if (i == 1 && j == 1)
                f[i][j] = 0;
            else {
                int fr = f[i][deqr[i].front()];
                int fc = f[deqc[j].front()][j];
                if (a[i][j] == 0) {
                    f[i][j] = min(f[i][j], fr + 1);
                    f[i][j] = min(f[i][j], fc + 1);
                }
            }
            while (!deqr[i].empty() && f[i][deqr[i].back()] >= f[i][j]) deqr[i].pop_back();
            while (!deqc[j].empty() && f[deqc[i].back()][j] >= f[i][j]) deqc[j].pop_back();
            deqr[i].push_back(j);
            deqc[j].push_back(i);
        }

    if (f[n][n] != oo) cout << f[n][n];
    else cout << -1;
}
