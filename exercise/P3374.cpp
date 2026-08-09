#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T>
struct BIT{
    int n;
	vector<T> c;
	BIT(int n_=0){init(n_);}
	void init(int n_){
		n=n_;
		c.assign(n+1,T{});
	}
	void add(int x,const T &v){
		for(;x<=n;x+=x&-x)
			c[x]=c[x]+v;
	}
	T sum(int x){
		T ans{};
		for(;x>0;x-=x&-x)
			ans=ans+c[x];
		return ans;
	}
	T sum(int x,int y){
		return sum(y)-sum(x-1);
	}
};
void solve(){
	int n,m;
    cin>>n>>m;
    BIT<int> tr(n);
    for(int i=1,x;i<=n;++i)cin>>x,tr.add(i,x);
    for(int i=1,o,x,y;i<=m;++i){
          cin>>o>>x>>y;
          if(o==1)tr.add(x,y);
          else cout<<tr.sum(x,y)<<'\n';
     }
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin>>T;
	while(T--)solve();
	return 0; 
}
