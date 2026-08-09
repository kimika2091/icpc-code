#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,S;
	cin>>n>>S;
	vector<int> a(n+1);
	bool f1=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]==S)f1=1;
	}
	if(!f1){
		cout<<"NO\n";
		return ;
	}
	bool f2=1;
	for(int i=1;i<=n;++i){
		if(a[i]!=0&&a[i]!=S){
			f2=0;
			break;
		}
	}
	if(!f2){
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
