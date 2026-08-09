#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P=998244353;
int add(ll a,ll b){return (a+b)%P;}
int mul(ll a,ll b){return (a*b)%P;}
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1),b(m+1),sa(n+1);
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=m;++i)cin>>b[i];
	int sb=0,s1=0,s2=0;
	for(int i=1;i<=n;++i)sa[i]=add(sa[i-1],a[i]);
	for(int i=1;i<=m;++i)sb=add(sb,b[i]);
	for(int i=1;i<=n;++i)s1=add(s1,mul(mul(i,a[i]),sb));
	for(int j=1;j<=m;++j){
		for(int k=1;k<=n/j;++k){
			int l=j*k,r=min(j*(k+1)-1,n);
			s2=add(s2,mul(mul(mul(b[j],j),k),add(sa[r],P-sa[l-1])));
		}
	}
	cout<<add(s1,P-s2);
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	while(T--)solve();
	return 0; 
}
