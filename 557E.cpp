#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=5010;
#define foru(i,l,r) for(int i=l;i<=r;++i)
#define ford(i,r,l) for(int i=r;i>=l;--i)
#define repu(i,r) for(int i=0;i<r;++i)
#define ll long long
int len,a[maxN],k;
char s[maxN];
bool f[maxN][maxN];
class trie{
	public:
		int value;
		trie *next[2];
		void construct(){
			value=0;
			repu(i,2) next[i]=NULL;
		}
		void build(int l,int r){
			value++;
			if (l==r) return;
			if (next[s[l]-'a']==NULL){
				trie tmp; tmp.construct();
				next[s[l]-'a']=&tmp;
			}
			next[s[l]-'a']->build(l+1,r);
		}
		void get(int k){
			repu(i,2)
				if (next[i]->value>=k){
					printf("%c",(i)?'b':'a');
					next[i]->get(k);
					break; 
				}
				else k-=next[i]->value;
		}
};
int main(){
	trie root; root.construct();
	scanf("%s\n",&s);
	scanf("%d\n",&k);
	len=strlen(s);
	foru(l,1,len)
		repu(i,len){
			int j=i+l-1;
			if (j>=len) break;
			if (i==j) f[i][j]=1;
			else 
				if (i+2<=j-2) f[i][j]=(f[i+2][j-2]&(s[i]==s[j]));
				else f[i][j]=(s[i]==s[j]);
			//printf("%d %d %d\n",i,j,f[i][j]);
		}
	repu(i,len)
		foru(j,i,len) 
			if (f[i][j]) root.build(i,j);
	root.get(k);
}