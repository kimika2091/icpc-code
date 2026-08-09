#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1),p(k+1);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=k;++i)cin>>p[i];
	int t1=p[1],t2=p[1];
	for(int i=1;i<=p[1];++i){
		if(a[i]!=a[p[1]]){
			t1=i;
			break;
		}
	}
	for(int i=n;i>=p[1];--i){
		if(a[i]!=a[p[1]]){
			t2=i;
			break;
		}
	}
	int cnt=0,t=0;
	while(t1<p[1]||t2>p[1]){
		cnt++;
		t^=1;
		while(t1<p[1]&&a[t1]==(a[p[1]]^t))t1++;
		while(t2>p[1]&&a[t2]==(a[p[1]]^t))t2--;
	}
	if(a[p[1]]!=(a[p[1]]^t))cnt++;
	cout<<cnt<<'\n';
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	cin>>T;
	while(T--)solve();
	return 0; 
}
