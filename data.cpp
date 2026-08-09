#include<bits/stdc++.h>
using namespace std;
using ll=long long;
mt19937 mt(time(nullptr));
inline ll rnd(ll l,ll r){
	uniform_int_distribution<ll>rd(l,r);
	return rd(mt);
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false) ;
	int T = 1;
	cout << T << '\n';
	ll n = rnd(2, 1e6),k = rnd(1, n - 1);
	cout << n << ' ' << k << '\n';
	for(int i=1;i<=n;++i){
		cout << rnd(0, 1);
	}
	cout << endl;

}