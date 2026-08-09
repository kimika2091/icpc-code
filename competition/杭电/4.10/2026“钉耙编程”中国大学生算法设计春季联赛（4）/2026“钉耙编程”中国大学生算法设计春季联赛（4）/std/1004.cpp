#include<bits/stdc++.h>
using namespace std;
const int M=25;
int T,n,all,a[M];
int f[(1<<20)+5],v[(1<<20)+5];
bool check(int i,int j) {
	if(!(i&(1<<j)))return 0;
	return (v[i]^a[j])<a[j];
}
int main() {
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>T;
	while(T--) {
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		cin>>n;
		for(int i=0; i<n; i++)cin>>a[i];
		all=(1<<n)-1;
		for(int i=1;i<=all;i++)for(int j=0;j<n;j++)if(i&(1<<j))v[i]^=a[j];
		for(int i=0;i<=all;i++)f[i]=0;
		for(int i=1; i<=all; i++) 
			for(int j=0; j<n; j++)
				if(check(i,j)&&f[i^(1<<j)]==0) {
					f[i]=1;
					break;
				}
		if(f[all]==1)puts("Left");
		else puts("Right");
	}
	return 0;
}

