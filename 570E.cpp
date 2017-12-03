#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int maxN=510,modP=1e9+7;
#define foru(i,l,r) for(int i=l;i<=r;++i)
#define ford(i,r,l) for(int i=r;i>=l;--i)
#define repu(i,r) for(int i=0;i<r;++i)
#define repd(i,r) for(int i=r-1;i>=0;--i)
#define ll long long
int m,n,res,f[2][maxN][maxN];
char s[maxN][maxN];
bool check(int x_1,int y_1,int x_2,int y_2){
	if ((x_1<=0)||(x_1>m)) return false;
	if ((x_2<=0)||(x_2>m)) return false;
	if ((y_1<=0)||(y_1>n)) return false;
	if ((y_2<=0)||(y_2>n)) return false;
	return true;
}
int main(){
    scanf("%d%d\n",&m,&n);
    foru(i,1,m) scanf("%s\n",&s[i]);
    int path=(n+m)/2;
    ford(i,path,1)
    	foru(x_1,1,m)
    		foru(x_2,1,m){
    			int y_1=i-x_1+1,y_2=(n-(i-(m-x_2+1)));
    			//if (i==2 && x_1==2 && x_2==4) printf("%d %d\n",y_1,y_2);
    			f[i%2][x_1][x_2]=0;
    			if (!check(x_1,y_1,x_2,y_2)) continue;
    			if (i==path){
    				if ((n+m-1)%2) f[i%2][x_1][x_2]=(x_1==x_2);
    				else f[i%2][x_1][x_2]=((x_1==x_2)||(y_1==y_2));
    			}
    			else{
    				foru(t_1,0,1)
    					foru(t_2,0,1){
    						//if (i==1) printf("%d %d %d\n",x_1+t_1,x_2-t_2,f[1-(i%2)][x_1+t_1][x_2+t_2]);
    						f[i%2][x_1][x_2]+=(f[1-(i%2)][x_1+t_1][x_2-t_2]);
    						f[i%2][x_1][x_2]%=modP;
    					}
    			}
    			//if (i==1) printf("%d\n",f[i%2][x_1][x_2]);
    			if (s[x_1][y_1-1]!=s[x_2][y_2-1]) f[i%2][x_1][x_2]=0;
    			//printf("%d %d %d %d %d %d\n",i,x_1,y_1,x_2,y_2,f[i%2][x_1][x_2]);
    		}
    printf("%d",f[1][1][m]);
}