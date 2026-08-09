#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k;
vector<int> tr;
int lowbit(int x)
{
    return x & -x;
}
void update(int x, int c) 
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}
int query(int x) 
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
void solve(){
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i)cin>>a[i];
	tr.resize(n+1);
	auto sol=[&](ll m){
		for(int i=1;i<=n;++i)tr[i]=0;
		ll inv=0,r=n,ans=0;
		for(int l=n;l>=1;--l){
			inv+=query(a[l]-1);
			update(a[l],1);
			while(l<=r&&inv>=m){
				ans+=l;
				inv-=query(n)-query(a[r]);
				update(a[r--],-1);
			}		
		}
		while(1<=r&&inv>=m){
			ans++;
			inv-=query(n)-query(a[r]);
			update(a[r--],-1);
		}
		return ans;
	};
	cout<<sol(k)-sol(k+1);
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	while(T--)solve();
	return 0; 
}
