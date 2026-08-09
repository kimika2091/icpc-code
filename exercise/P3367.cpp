#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct DSU{
	vector<int> fa,siz;
	DSU(int n){init(n);}
	void init(int n){
		fa.resize(n);
		iota(fa.begin(),fa.end(),0);
		siz.assign(n,1);
	}
	int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
	bool merge(int x,int y){
		x=get(x),y=get(y);
		if(x==y)return 0;
		if(siz[x]<siz[y])swap(x,y);
		fa[y]=x,siz[x]+=siz[y];
		return 1;
	}
	bool same(int x,int y){return get(x)==get(y);}
};
void solve(){
    int n,m;
    cin>>n>>m;
	DSU dsu(n+1);
    for(int i=1,z,x,y;i<=m;++i){
          cin>>z>>x>>y;
          if(z==1)dsu.merge(x,y);
          else{
               cout<<(dsu.same(x,y)?"Y":"N")<<'\n';
          }
    }
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}