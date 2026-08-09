#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int T,n,k;
int ton[N];
string s;
void init(){
    for(int i=0;i<10000;i++) ton[i]=true;
}
int pd(int x,string c){
    int res=0;
    if(c[0]-48==x/1000) res++;
    if(c[1]-48==x/100%10) res++;
    if(c[2]-48==x/10%10) res++;
    if(c[3]-48==x%10) res++;
    return res;
}
void Out(int x){
    cout<<x/1000<<x/100%10<<x/10%10<<x%10<<endl;
}
void solve(){
    cin>>n;
    init();
    for(int i=1;i<=n;i++){
        cin>>s>>k;
        for(int j=0;j<10000;j++)if(ton[j]){
            if(pd(j,s)!=k) ton[j]=false;
        }
    }
    for(int i=0;i<=10000;i++)if(ton[i]){
        Out(i);
    }
    return;
} 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}