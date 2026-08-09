#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<typename T>
struct ST{
    int n;
    vector<vector<T>> st;
    vector<int> lg2;
    ST(const vector<T>& a){
        n=a.size()-1;
        lg2.resize(n+1,0);
        for(int i=2;i<=n;++i)lg2[i]=lg2[i/2]+1;
		st.assign(lg2[n]+1,vector<T>(n+1));
        for(int i=1;i<=n;++i)st[0][i]=a[i];
        for(int j=1;j<=lg2[n];++j){
            for(int i=1;i+(1<<j)-1<=n;++i){
                st[j][i]=max(st[j-1][i],st[j-1][i+(1<<(j-1))]);
            }
        }
    }
    T query(int l,int r){
        if(l>r)return 0; 
        int k=lg2[r-l+1];
        return max(st[k][l],st[k][r-(1<<k)+1]);
    }
};
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;++i)cin>>a[i];
	ST<int> st(a);
	for(int i=1,l,r;i<=m;++i){
		cin>>l>>r;
		cout<<st.query(l,r)<<'\n';
	}
}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int T=1;
	// cin>>T;
	while(T--)solve();
	return 0; 
}
