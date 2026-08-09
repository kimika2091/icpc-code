#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    vector<array<int,26>> nxt(n+1);
    nxt[n].fill(n);
    for(int i=n-1;i>=0;--i){
        nxt[i]=nxt[i+1];
        nxt[i][s[i]-'a']=i;
    }
    ll ans=0;
    for(int i=0;i<n;++i){
        int j=i;
        bool f=1;
        for(auto c:t){
            j=nxt[j][c-'a'];
            if(j==n){
                f=0;
                break;
            }
            j++;
        }
        if(!f)ans+=n-i;
        else ans+=j-i-1;
    }
    cout<<ans<<'\n';
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
    int T=1;
    while(T--)solve();
	return 0; 
}