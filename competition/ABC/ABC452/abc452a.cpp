#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,m;
	cin>>n>>m;
	if(n==1&&m==7)cout<<"Yes";
	else if(n==3&&m==3)cout<<"Yes";
	else if(n==5&&m==5)cout<<"Yes";
	else if(n==7&&m==7)cout<<"Yes";
	else if(n==9&&m==9)cout<<"Yes";
	else cout<<"No";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0; 
}
