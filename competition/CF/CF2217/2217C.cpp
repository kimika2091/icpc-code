#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	if(gcd(a,n)==1&&gcd(b,m)==1&&gcd(n,m)<3){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0; 
}
