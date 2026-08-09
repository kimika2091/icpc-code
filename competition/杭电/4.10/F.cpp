#include<bits/stdc++.h>
using namespace std;
using ll=long long;
mt19937 rd(time(nullptr));
int Rand(int l,int r){
	uniform_int_distribution<> rng(l,r);
	return rng(rd); 
}
void solve(){
	
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("data.in","w",stdout);
	int T=1;
	cout<<1<<'\n';
	int n=2000,m=2000;
	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1&&j==1)cout<<0<<' ';
			else cout<<Rand(0,10)<<' ';
		}
		cout<<'\n';
	}
    return 0;
}
