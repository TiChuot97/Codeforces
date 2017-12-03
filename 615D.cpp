#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxN = 200010, modP = 1e9 + 7;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int n, a[maxN], b[maxN], c[maxN], num;
ll res;

void getRes() {
	bool check = false;
	repu(i, num) 
		if (c[i] % 2) check = true; 
	if (!check) 
		repu(i, n) c[i] /= 2;
	ll numN = 1;
	repu(i, n)
		foru(j, 1, c[i]) numN = (numN * b[i]) % modP;
	if (!check)
		repu(i, n) c[i] *= 2;
	res = numN;
	repu(i, n) {
		int temp = c[i] + 1;
		if (c[i] % 2 && check) temp /= 2, check = false;
		numN = res;
		foru(j, 1, temp - 1) res = (res * numN) % modP;
	}
}

int main() {
	cin >> n;
	repu(i, n) cin >> a[i];
	sort(a, a + n);
	b[0] = a[0];
	c[0] = 1;
	num = 0;
	foru(i, 1, n - 1)
		if (a[i] == a[i - 1]) ++c[num];
		else b[++num] = a[i], c[num] = 1;
	++num;
	getRes();
	cout << res;
}