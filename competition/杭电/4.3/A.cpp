#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<ll> a(n+1),b(n+2),c(n+2),d(n+2);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n+1;++i)cin>>b[i];
	sort(a.begin()+1,a.end());
	sort(b.begin()+1,b.end());
	ll sum=0;
	for(int i=1;i<=n;++i){
		sum+=a[i]*b[i+1];
	}
	if(sum>=m){
		cout<<0<<'\n';
		return;
	}
	for(int i=1;i<=n;++i){
		c[i]=c[i-1]+a[i]*b[i];
		d[i]=d[i-1]+a[i]*b[i+1];
	}
	auto check=[&](ll x){
		int p=lower_bound(a.begin()+1,a.end(),x)-a.begin();
		ll ans=c[p-1]+d[n]-d[p-1]+x*b[p];
		return ans>=m;
	};
	ll l=0,r=m,mid,ans=0;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
