#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> a(n+2,vector<int>(m+2,-1));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			cin>>a[i][j];
		}
	}
	vector<vector<int>> vis(n+2,vector<int>(m+2,-1));
	auto check=[&](int mid){
		if(a[1][1]==mid)return false;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				vis[i][j]=0;
			}
		}
		queue<pair<int,int>> q;
		q.push({1,1});
		while(!q.empty()){
			auto [x,y]=q.front();
			q.pop();
			if(x==n&&y==m)return true;
			if(a[x][y]==mid||vis[x][y]!=0)continue;
			vis[x][y]=1;
			if(vis[x+1][y]==0)q.push({x+1,y});
			if(vis[x-1][y]==0)q.push({x-1,y});
			if(vis[x][y+1]==0)q.push({x,y+1});
			if(vis[x][y-1]==0)q.push({x,y-1});
		}
		return false;
	};
	for(int i=0;i<=n+m;++i){
		if(check(i)){
			cout<<i<<'\n';
			return;
		}
	}
}
signed main(){
//	freopen("data.in","r",stdin);
	cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)solve();
    return 0;
}
/*
1
3 3
0 1 0
1 2 0
1 3 1
*/