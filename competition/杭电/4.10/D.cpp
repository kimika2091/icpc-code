#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<string> all(10005);
void solve(){
	int n;
	cin>>n;
	string s;
	int k;
	map<string,int> f;
	vector<pair<string,int>> q;
	for(int i=1;i<=n;++i){
		cin>>s>>k;
		if(f[s])continue;
		q.push_back({s,k});
		f[s]=1;
	}
	for(string &num:all){
		bool ok=1;
		for(auto &[guess,k]:q){
			int cnt=0;
			for(int i=0;i<4;++i){
				cnt+=(num[i]==guess[i]);
			}
			if(cnt!=k){
				ok=0;
				break;
			}
		}
		if(ok){
			cout<<num<<'\n';
			return;
		}
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);	
	for(int i=0;i<=9999;++i){
		char buf[5];
		sprintf(buf,"%04d",i);
		all[i]=string(buf);
	}
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
/*
1
3
0123 3
1123 3
3124 3
*/
