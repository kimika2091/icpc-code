#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int N=1e9;
vector<int> a,p;
void dfs(int now){
	a.push_back(now);
	for(int num:p){
		string s=to_string(now)+to_string(num);
		if(s.size()>9)return;
		dfs(stoi(s));
	}
}
void solve(){
	int n;
	cin>>n;
	cout<<a[n-1]<<'\n';
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int i=1;i<=N;i*=2)p.push_back(i);	
	for(int i:p)dfs(i);
	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	int T=1;
	// cin>>T;
	while(T--)solve();
	return 0; 
}
