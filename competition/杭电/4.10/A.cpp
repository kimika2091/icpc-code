#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,m;
	cin>>n>>m;
	int now=0;
	bool flag=1;
	for(int i=1;i<=n;++i){
		set<int> s;
		for(int i=1,a;i<=m;++i){
			cin>>a;
			s.insert(a);
		}
		auto it=s.upper_bound(now);
		if(it==s.end())flag=0;
		else{
			now=*it;	
		}
	}
	cout<<(flag?"YES":"NO")<<'\n';
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
