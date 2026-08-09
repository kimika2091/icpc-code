#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T>
struct BIT {
	int n;
	vector <T> c;
	BIT(int n): n(n), c(n + 1, 0) {}
	void add(int x, const T & v) {
		for (; x <= n; x += x & -x)
			c[x] = c[x] + v;
	}
	T sum(int x) {
		T ans {};
		for (; x > 0; x -= x & -x)
			ans = ans + c[x];
		return ans;
	}
	T sum(int x, int y) {
		return sum(y) - sum(x - 1);
	}
};
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	BIT<int> tr(n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		tr.add(i,a[i]-a[i-1]);	
	}
	for(int i=1,o,x,y,k;i<=m;++i){
		cin>>o;
		if(o==1){
			cin>>x>>y>>k;
			tr.add(x,k);
			tr.add(y+1,-k);
		}
		else{
			cin>>x;
			cout<<tr.sum(x)<<'\n';
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin>>T;
	while(T--)solve();
	return 0; 
}
