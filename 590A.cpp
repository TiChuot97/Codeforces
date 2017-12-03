//============================================================================
// Name        : 590A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxN = 500010;

#define foru(i, l, r) for (int i = l; i <= r; ++i)
#define ford(i, r, l) for (int i = r; i >= l; --i)
#define repu(i, r) for (int i = 0; i < r; ++i)
#define ll long long

int n, a[maxN], res;

int main() {
	cin >> n;
	int l = 0; res = 0;
	foru(i, 1, n) cin >> a[i];
	foru(i, 2, n) {
		if (i != n && a[i] != a[i - 1] && a[i] != a[i + 1] && l == 0) l = i;
		if ((a[i] == a[i + 1] || i == n) && l != 0) {
			int temp = 0;
			if ((i - l) % 2) {
				foru(j, l, i - 1) a[j] = a[i];
				temp = ((i - l) / 2) + 1;
			}
			else {
				temp = (i - l) / 2;
				foru(j, l, i - 1)
					if (j <= (i + l - 1) / 2) a[j] = 1 - a[i];
					else a[j] = a[i];
			}
			res = max(res, temp);
			l = 0;
		}
	}
	cout << res << endl;
	foru(i, 1, n) cout << a[i] << " ";
}
