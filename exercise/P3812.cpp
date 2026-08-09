#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T,size_t N>
struct LinearBasis{
	array<T,N+1> p;
	LinearBasis(){p.fill(0);}
	bool insert(T x){
		for(int i=N;i>=0;--i){
			if(!(x>>i&1))continue;
			if(!p[i]){
				p[i]=x;
				return true;
			}
			x^=p[i];
		}
		return false;
	}
	ll query_max(){
		ll res=0;
		for(int i=N;i>=0;--i){
			res=max(res,res^p[i]);
		}
		return res;
	}
};
void solve(){
	int n;
	cin>>n;
	vector<ll> a(n+1);
	LinearBasis<ll,50> B;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		B.insert(a[i]);
	}
	cout<<B.query_max();
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin>>T;
	while(T--)solve();
	return 0; 
}