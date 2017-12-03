#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxN = 5 * 1e5, oo = 23041997;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int n, b[maxN + 1], pre[maxN + 1], nex[maxN + 1], realVal[maxN + 1], tree[maxN * 5], pos[maxN + 1], res[maxN + 1];

struct ioi {
	int v, p;
};

ioi a[maxN];

bool cmp(ioi i, ioi j) {
	return i.v < j.v;
}

void update(int k, int l, int r, int i, int v) {
	if (i < l || i > r) return;
	if (l == r) {
		tree[k] = v;
		return;
	}
	int mid = (l + r) >> 1;
	update(k * 2, l, mid, i, v);
	update(k * 2 + 1, mid + 1, r, i, v);
	tree[k] = min(tree[k * 2], tree[k * 2 + 1]);
}

int get(int k, int l, int r, int i, int j) {
	if (j < l || i > r) return oo;
	if (i <= l && r <= i) return tree[k];
	int mid = (l + r) >> 1;
	return min(get(k * 2, l, mid, i, j), get(k * 2 + 1, mid + 1, r, i, j));
}

int main() {
    cin >> n;
    repu(i, n) cin >> a[i].v, a[i].p = i;
    sort(a, a + n, cmp);
    int val = 1; b[a[0].p] = 1; realVal[a[0].p] = a[0].v;
    foru(i, 1, n - 1) {
        b[a[i].p] = (a[i].v != a[i - 1].v) ? ++val : val;
        realVal[a[i].p] = a[i].v;
    }
    repu(i, n) {
        pre[i] = pos[b[i]];
        nex[pos[b[i]]] = i;
        if (pre[i] == 0) pre[i] = oo;
        pos[b[i]] = i;
        update(1, 1, n, i, pre[i]);
    }
    int lastPos = 1;
    repu(i, n) {
        bool check = false;
        if (pre[i] != oo && pre[pre[i]] != oo && pre[pre[pre[i]]] != oo) {
            repu(t, 4) res[++res[0]] = realVal[i];
            check = true;
        }
        if (!check && pre[i] != oo) {
            int j = get(1, 1, n, pre[i] + 1, i - 1);
            cout << j << endl;
            if (j < pre[i]) {
                res[res[0] + 1] = res[res[0] + 3] = realVal[j];
                res[res[0] + 2] = res[res[0] + 4] = realVal[i];
                res[0] += 4;
            }
        }
        if (check)
            while (lastPos <= i) 
                update(1, 1, n, nex[lastPos++], oo);
    }
    cout << res[0] << endl;
    foru(i, 1, res[0]) cout << res[i] << " ";
}