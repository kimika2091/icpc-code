#include<bits/stdc++.h>
using namespace std;
const int M=100005;
int n,m,tot;
struct aa{
	int l,r;
}a[M];
int l[M],r[M],b[M<<2],c[M<<2],ans[M],fa[M<<2][22];
void add(int x,int d){
	while(x)c[x]=min(c[x],d),x-=x&-x;
}
int qy(int x){
	int res=tot+1;
	while(x<=tot)res=min(res,c[x]),x+=x&-x;
	return res;
}
void Main(){
	memset(b,0,sizeof(b));
	memset(c,0x3f3f3f3f,sizeof(c));
	tot=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		b[++tot]=a[i].l,b[++tot]=a[i].r;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i];
		b[++tot]=l[i],b[++tot]=r[i];
	}
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(b+1,b+tot+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+tot+1,a[i].r)-b;
	}
	for(int i=1;i<=m;i++){
		l[i]=lower_bound(b+1,b+tot+1,l[i])-b;
		r[i]=lower_bound(b+1,b+tot+1,r[i])-b;
	}
//	for(int i=0;i<(M<<2);i++)c[i]=tot+1;
	for(int i=1;i<=n;i++)add(a[i].l,a[i].r);
	for(int i=1;i<=tot;i++)fa[i][0]=qy(i);
	fa[tot+1][0]=tot+1;
	for(int j=1;j<=20;j++)
		for(int i=1;i<=tot+1;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for(int i=1;i<=m;i++){
		int t=l[i],cnt=0;
		for(int j=20;j>=0;j--){
			if(fa[t][j]<=r[i]){
				t=fa[t][j];
				cnt+=(1<<j);
			}
		}
		printf("%d\n",cnt);
	}
}
signed main(){
//	freopen("tv.in","r",stdin);
//	freopen("tv.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int T=1;
	cin>>T;
	while(T--)Main();
}

