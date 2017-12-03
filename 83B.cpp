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

const int maxN = 200100, modP = 1e9 + 7;
const double PI = acos(-1);

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pint pair < ll, ll >

vector < pint > b;
pint a[maxN];
int n;
ll k;

int main() {
    cin >> n >> k;
    ll s = 0;
    repu(i, n) {
        int t;
        scanf("%d", &t);
        a[i].F = t;
        a[i].S = i + 1;
        s += a[i].F;
    }
    if (s < k) { cout << -1; return 0; }
    sort(a, a + n);
    int round = 0;
    repu(i, n) {
        if (round >= a[i].F) continue;
        ll t = min((k / (n - i)), a[i].F - round);
        round += t;
        k -= t * (n - i);
        //cout << t << " " << k << " " << round << endl;
        if (round < a[i].F) {
            foru(j, i, n - 1) {
                swap(a[j].F, a[j].S);
                a[j].S -= round;
                b.push_back(a[j]);
            }
            break;
        }
    }
    sort(b.begin(), b.end());
    if (b.size()) {
        foru(i, k, (int) b.size() - 1) 
            cout << b[i].F << " ";
        repu(i, k)
            if (b[i].S > 1) cout << b[i].F << " ";
    }
}
