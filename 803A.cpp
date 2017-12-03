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

const int maxN = 200010, maxL = 10010, oo = 1000000000;
const double PI = acos(-1);

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pint pair < ll, int >

int n, k, res[maxN][maxN];

void print() {
    if (k) { cout << -1; return; }
    foru(i, 1, n) {
        foru(j, 1, n) printf("%d ", res[i][j]);
        cout << endl;
    }
}

int main() {
    cin >> n >> k;
    foru(i, 1, n)
        foru(j, i, n) {
            if (k) {
                if (i == j) --k, res[i][j] = 1;
                else
                    if (k >= 2) res[i][j] = res[j][i] = 1, k -= 2;
            }
        }
    print();
}
