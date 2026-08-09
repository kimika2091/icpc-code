#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N=10000005;

ll n,m,p;

ll sumphi[N];
int mu[N],phi[N];
bool vis[N];
int pr[N],len=0;
void sieve(int n){
  phi[1]=mu[1]=1;
  for(register int i=2;i<=n;i++){
    if(!vis[i])pr[len++]=i,phi[i]=i-1,mu[i]=-1;
    for(register int j=0;j<len&&pr[j]*i<=n;j++){
      int v=pr[j]*i;
      vis[v]=1;
      if(i%pr[j]==0){
        phi[v]=phi[i]*pr[j];
        break;
      }
      mu[v]=-mu[i];
      phi[v]=phi[i]*(pr[j]-1);
    }
  }
}
void build_sumphi(int n){
  for(register int i=1;i<=n;i++){
    sumphi[i]=(sumphi[i-1]+phi[i])%p;
  }
}
ll MU(ll n){
  if(n<=1e7)return mu[n];
  ll res=1,cur=0;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      cur=0,res*=-1;
      while(n%i==0)cur++,n/=i;
      if(cur>=2)return 0;
    }
  }
  return res;
}
ll PHI(ll n){
  if(n<=1e7)return phi[n];
  ll res=n;
  for(ll i=2;i*i<=n;i++){
    if(n%i==0){
      res=res/i*(i-1);
      while(n%i==0)n/=i;
    }
  }
  if(n>1)res=res/n*(n-1); 
  return res;
}
map<ll,ll>Map;
ll sumPHI(ll n){
  if(n<=1e7)return sumphi[n];
  if(Map[n])return Map[n];
  ll res;
  if(n&1)res=(n%p)*((n+1)/2%p)%p;
  else res=(n/2%p)*((n+1)%p)%p;
  for(ll i=2,j;i<=n;i=j+1){
    j=n/(n/i);
    (res-=1ll*(j-i+1)%p*sumPHI(n/i)%p)%=p;
  }
  if(res<0)res+=p;
  return Map[n]=res;
}

ll S(ll n,ll m){
  if(m==0)return 0;
  if(n==1)return sumPHI(m);
  ll phi_n=PHI(n),T,ans=0;
  for(ll i=1;i*i<=n;i++)if(n%i==0){
    T=i;
    if(MU(T))ans=(ans+phi_n/PHI(T)%p*S(T,m/T))%p;
    if(i==n/i)continue;
    T=n/i;
    if(MU(T))ans=(ans+phi_n/PHI(T)%p*S(T,m/T))%p;
  }
  return ans;
}

int main(){
  sieve(1e7);
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%lld%lld%lld",&n,&m,&p);
    build_sumphi(1e7);
    Map.clear();
    printf("%lld\n",S(n,m));
  }
  return 0;
}
