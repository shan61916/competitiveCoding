  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   double dll ;

#define   mp make_pair
#define   pb push_back
#define   ff first 
#define   ss second
#define   IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define   endl "\n" 
#define   pll pair<ll, ll>
#define   all(x) x.begin(), x.end()
#define   vll vector<ll> 

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);
ll modadd(ll x, ll y) {
  return (x%mod + y%mod)%mod;
} 
ll modmul(ll x, ll y) {
  return (x%mod * y%mod)%mod;
}
const ll MOD  = (ll)(1e9+7);
ll fast_exp(ll base, ll exp) {
  ll res=1;
  while(exp>0) {
    if(exp%2==1) res=(res*base)%MOD;
      base=(base*base)%MOD;
      exp/=2;
  }
  return res%MOD;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  vll a(n);
  vector<vll> sb(n+1, vll(61, 0));
  for(auto &it : a) cin >> it;
  for(ll i = n-1; i >= 0; i--) {
    for(ll j = 0; j < 60; j++) {
      sb[i][j]+= sb[i+1][j];
      if(a[i]&(1ll<<j)) sb[i][j]++;
    }
  }
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < 60; j++) {
      if(a[i]&(1ll<<j)) {
        ll tot = (n - (i+1));
        ans= modadd(ans, modmul((tot - (sb[i+1][j])), fast_exp(2, j)));
      } else {
        ans= modadd(ans, modmul(sb[i+1][j], fast_exp(2, j)));
      }
    }
  }
  cout << ans << endl;
  return 0;
} //good night.