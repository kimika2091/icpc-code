#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int N=1<<n;
	vector<int> sum(N),dp(N);
	vector<vector<int>> S(n+1);
	for(int s=0;s<N;++s){
		int cnt=0;
		for(int j=0;j<n;++j){
			if(!(s>>j&1))continue;
			cnt++;
			sum[s]^=a[j];
		}
		S[cnt].push_back(s);
	}
	for(int &s:S[1])dp[s]=1;
	for(int i=2;i<=n;++i){
		for(int &s:S[i]){
			bool f=0;
			for(int j=0;j<n;++j){
				if(!(s>>j&1))continue;
				int t=s-(1<<j);
				if(sum[t]<a[j]&&dp[t]==0){
					f=1;
					break;
				}
			}
			dp[s]=f;
		}
	}
	cout<<(dp[N-1]?"Left":"Right")<<'\n';
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
/*
1
4
2 3 6 8
*/