#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	int sum=0;
	for(int i=1;i<=n;++i)cin>>a[i],sum+=a[i];
	if((sum%2)||(n*k%2==0))cout<<"YES\n";
	else cout<<"NO\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0; 
}
