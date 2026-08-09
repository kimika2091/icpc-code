#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char s[15][15];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			s[i][j]='.';
			if(i==1||i==n||j==1||j==m)s[i][j]='#';
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cout<<s[i][j];
		}
		cout<<'\n';
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0; 
}
