#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	vector<int> q(n+1);
	int h=1,t=0;
	for(int i=1;i<=n;++i){
		while(h<=t&&a[q[t]]>=a[i])t--;
		while(h<=t&&i-q[h]+1>k)h++;
		q[++t]=i;
		if(i>=k)cout<<a[q[h]]<<' ';
	}
	cout<<'\n';
	h=1,t=0;
	for(int i=1;i<=n;++i){
		while(h<=t&&a[q[t]]<=a[i])t--;
		while(h<=t&&i-q[h]+1>k)h++;
		q[++t]=i;
		if(i>=k)cout<<a[q[h]]<<' ';
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin>>T;
	while(T--)solve();
	return 0; 
}
