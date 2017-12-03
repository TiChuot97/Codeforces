#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxN=100010;
#define foru(i,l,r) for(int i=l;i<=r;++i)
#define ford(i,r,l) for(int i=r;i>=l;--i)
#define repu(i,r) for(int i=0;i<r;++i)
int a[maxN],ans[maxN],n;
int main(){
    scanf("%d",&n);
    foru(i,1,n*n) scanf("%d",&a[i]);
    sort(a+1,a+n*n+1);
    int num=1;
    foru(i,2,n*n){
        if (a[i]!=a[i-1]){
            if (num%2) ans[++ans[0]]=a[i-1];
            num=0;
        }
        ++num;
    }
    if (num%2) ans[++ans[0]]=a[n*n];
    foru(i,1,ans[0]) printf("%d ",ans[i]);
}

