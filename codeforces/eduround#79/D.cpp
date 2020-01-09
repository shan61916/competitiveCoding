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
 
const ll inf = (ll)(1e17);
const ll mod = (ll)(998244353);
ll fast_exp(ll base, ll exp) {
  ll res=1;
  while(exp>0) {
    if(exp%2==1) res=(res*base)%mod;
      base=(base*base)%mod;
      exp/=2;
  }
  return res%mod;
}
 
ll modadd(ll x, ll y){return (x%mod + y%mod)%mod;}
ll modmul(ll x, ll y){return (x%mod * y%mod)%mod;}
ll modsub(ll x, ll y){return (x%mod - y%mod + mod)%mod;}
ll moddiv(ll x, ll y){return modmul(x, fast_exp(y, mod-2));}
 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
   ll n;
   cin >> n;
   vll a(n); 
   vector<vll> adj(n);
   map<ll, ll> key;
   for(ll i = 0; i < n; i++) {
    cin >> a[i];
    for(ll j = 0; j < a[i]; j++) {
      ll xx;
      cin >> xx;
      adj[i].pb(xx);
      key[xx]++;
    }
   }
   ll ans = 0;
   for(ll i = 0; i < n; i++) {
    ll now = 0;
    for(auto it: adj[i]) now+= key[it];
    ans = modadd(ans, moddiv(now, a[i]));
   }
   ans = modmul(ans, moddiv(1LL, modmul(n, n)));
   cout << ans << endl;
  return 0;
} //good night.