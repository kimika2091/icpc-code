#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> b(n+1,vector<int>(k+1,0));
	int t=(k-1)/2+1,s=min(m/2+1,n);
	for(int i=t;i<=k;++i){
		b[1][i]=s;
	}
	for(int i=2;i<n;++i){
		for(int j=1;j<=t+i-2;++j){
			b[i][j]=i-1;
		}
		for(int j=t+i-1;j<=k;++j){
			b[i][j]=s+i-1;
		}
	}
	for(int i=1;i<=k;++i){
		b[n][i]=s-1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k;++j){
			cout<<b[i][j]<<' ';
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
