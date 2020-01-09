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

ll modadd(ll x, ll y){return (x%mod + y%mod)%mod;}
ll modmul(ll x, ll y){return (x%mod * y%mod)%mod;}
ll modsub(ll x, ll y){return (x%mod - y%mod + mod)%mod;}
// ll moddiv(ll x, ll y){return modmul(x, fast_exp(y, mod-2));}

ll n;
vector<vll> adj(100100);
ll dp[100010][3];
ll dfs(ll idx, ll parent, ll color) {
  ll &ans = dp[idx][color];
  if(ans != -1) return ans;
  ans = 1;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    if(color == 0)ans = modmul(ans, dfs(it, idx, color^1)); 
    else if(color == 1) {
      ans = modmul(ans, modadd(dfs(it, idx, color), dfs(it, idx, color^1)));
    }
  }
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  for(ll i = 0; i < n - 1; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  memset(dp, -1, sizeof dp);
  ll ans = 0;
  ans = modadd(dfs(1, -1, 1), ans);
  ans = modadd(dfs(1, -1, 0), ans);
  cout << ans << endl;
  return 0;
} //good night. 