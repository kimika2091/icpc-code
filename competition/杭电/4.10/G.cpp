#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct train{
	int l,r;
};
bool cmp(train a,train b){
	return a.r<b.r;
}
void solve(){
	int n;
	cin>>n;
	vector<train> a(n+1);
	for(int i=0;i<n;++i){
		cin>>a[i].l>>a[i].r;
	}
	sort(a.begin(),a.end(),cmp);
	vector<int> R(n),dp(n+1,0);
	for(int i=0;i<n;++i){
		R[i]=a[i].r;
	}
	int m;
	cin>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		int l=lower_bound(R.begin(),R.end(),x)-R.begin();
		int r=upper_bound(R.begin(),R.end(),y)-R.begin()-1;
		if(l>r){
			cout<<0<<'\n';
			return;
		}
		int ans=0,lst=l-1;
		for(int i=l;i<=r;++i){
			if(a[i].l>=lst){
				ans++;
				lst=a[i].r;
			}
		}
		cout<<ans<<'\n';
	}
	
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
