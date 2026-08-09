#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int ch[15][26];
void solve(){
	string S,T;
	int N=S.size(),M=T.size();
	int n,m;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	for(int i=1;i<=n;++i)cin>>a[i]>>b[i];
	cin>>m;
	vector<string> s(m+1);
	for(int i=1;i<=m;++i){
		cin>>s[i];
		for(int j=1;j<=n;++j){
			if(s[i].size()==a[j]){
				ch[j][s[i][b[j]-1]-'a']++;
			}
		}
	}
	for(int i=1;i<=m;++i){
		if(s[i].size()!=n){
			cout<<"No\n";
			continue;
		}
		bool p=1;
		for(int j=1;j<=n;++j){
			if(!ch[j][s[i][j-1]-'a']){
				p=0;
				break;
			}
		}
		if(p)cout<<"Yes\n";
		else cout<<"No\n";
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0; 
}
