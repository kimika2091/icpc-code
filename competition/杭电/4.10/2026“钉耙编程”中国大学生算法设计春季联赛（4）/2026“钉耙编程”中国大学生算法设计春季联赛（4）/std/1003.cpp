#include<bits/stdc++.h>
using namespace std;
inline char nc()
{
	static char buf[99999],*l,*r;
	return l==r&&(r=(l=buf)+fread(buf,1,99999,stdin),l==r)?EOF:*l++;
}
template <class code>inline code read(const code &a)
{
    code x=0;short w=0;char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=nc();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=nc();}
    return w?-x:x;
}
void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)print(x/10);
	putchar(x%10+48);
}
int a[1505][1505],jl[1505][1505][16];
int mp[16],z[16];
long long tj[1<<16],tj1[1<<16];
bool cmp(int x,int y){
    return z[x]< z[y];
}
void solve(){
    memset(tj,0,sizeof(tj));
    int n=read(n),q=read(q);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)a[i][j]=read(a[i][j]);
    }
    for(int z=0;z<16;z++){
        for(int i=1;i<=n;i++){
            int la=0;
            for(int j=1;j<=n;j++){
                if((a[i][j]>>z)&1)la=j;
                jl[i][j][z]=j-la;
            }
            la=n+1;
            for(int j=n;j>=1;j--){
                if((a[i][j]>>z)&1)la=j;
                jl[i][j][z]=min(jl[i][j][z],la-j);
            }
        }
        for(int j=1;j<=n;j++){
            int la=0;
            for(int i=1;i<=n;i++){
                if((a[i][j]>>z)&1)la=i;
                jl[i][j][z]=min(jl[i][j][z],i-la);
            }
            la=n+1;
            for(int i=n;i>=1;i--){
                if((a[i][j]>>z)&1)la=i;
                jl[i][j][z]=min(jl[i][j][z],la-i);
            }
        }
    }
    for(int i=0;i<16;i++)mp[i]=i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            memcpy(z,jl[i][j],sizeof(jl[i][j]));
            sort(mp,mp+16,cmp);
            int now=0;
            for(int k=0;k<16;k++){
                tj[now]+=z[mp[k]];
                now|=(1<<mp[k]);
                if(k<15)tj[now]-=z[mp[k]];
            }
        }
    }
    for(int i=0;i<16;i++){
        for(int j=(1<<i);j<(1<<16);j=(j+1)|(1<<i)){
            tj[j]+=tj[j^(1<<i)];
        }
    }
    while(q--){
        int x=read(x);
        printf("%lld\n",tj[(x&((1<<16)-1))]);
    }
}
signed main(){
    //  freopen("text.in","r",stdin);
	//  freopen("text.out","w",stdout);
    int t=1;
    t=read(t);
    while(t--)solve();
    return 0;
}