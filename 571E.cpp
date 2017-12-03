#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define foru(i,l,r) for(int i=l;i<=r;++i)
#define ford(i,r,l) for(int i=r;i>=l;--i)
int main(){
	scanf("%d%d",&n,&k);
	foru(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int num_L=n%k,num_S=(n/k)-num_L;
	
}