#include<bits/stdc++.h>
using namespace std;
template <class code>inline code read(const code &a)
{
    code x=0;short w=0;char ch=0;
    while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while(isdigit(ch)) {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return w?-x:x;
}
int n,m,k;
bool dp[155][155][155];
int l[35],r[35],a[35][10],sc[35][10],v[10][205],jl[10],su[10],zg;
int ans;
void cl(){
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;
    for(int i=1;i<=m;i++){
        for(int x=k;x>=a[i][0];x--){
            for(int y=k-x;y>=a[i][1];y--){
                for(int z=k-x-y;z>=a[i][2];z--){
                    dp[x][y][z]|=dp[x-a[i][0]][y-a[i][1]][z-a[i][2]];
                }
            }
        }
    }
    for(int i=0;i<=k;i++){
        int z1=0;
        if(i>=l[jl[0]])z1=v[jl[0]][i-l[jl[0]]];
        for(int j=0;j<=k;j++){
            int z2=0;
            if(j>=l[jl[1]])z2=v[jl[1]][j-l[jl[1]]];
            for(int p=0;p<=k;p++){
                int z3=0;
                if(p>=l[jl[2]])z3=v[jl[2]][p-l[jl[2]]];
                if(dp[i][j][p])ans=max(ans,z1+z2+z3);
            }
        }
    }
}
void solve(){
    ans=0;
    memset(a,0,sizeof(a));memset(v,0,sizeof(v));
    n=read(n),m=read(m),k=read(k);
    for(int i=0;i<n;i++)su[i]=0;
    for(int i=0;i<n;i++){
        l[i]=read(l[i]),r[i]=read(r[i]);
        memset(v[i],0,sizeof(v[i]));
        for(int j=0;j<=r[i]-l[i];j++){
            v[i][j]=read(v[i][j]);
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        for(int j=0;j<n;j++){
            sc[i][j]=read(sc[i][j]);
            su[j]+=sc[i][j];
        }
    }
    for(int j=0;j<n;j++){
        if(su[j]>=l[j]){
            jl[cnt]=j;
            for(int i=1;i<=m;i++){
                a[i][cnt]=sc[i][j];
            }
            ++cnt;
        }
    }
    l[7]=r[7]=0;
    for(int i=cnt;i<=2;i++)jl[i]=7;
    cl();
    printf("%d\n",ans);
}
signed main(){
    int t=read(t);
    while(t--)solve();
    return 0;
}