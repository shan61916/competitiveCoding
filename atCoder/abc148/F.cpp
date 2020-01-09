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
vector<vll> adj;
vll tin;
void dfs1(ll idx, ll parent, ll t) {
  tin[idx] = t;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    dfs1(it, idx, t+1);
  }
}
ll ans = 0;
void dfs(ll idx, ll parent, ll t) {
  if(t <= tin[idx]) ans = max(ans, tin[idx]-1);
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    dfs(it, idx, t+1);
  }
}
 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, u, v;
  cin >> n >> u >> v;
  adj.resize(n+1), tin.resize(n+1, 0);
  for(ll i = 0; i < n-1; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  dfs1(v, -1, 0);
  dfs(u, -1, 0);
  cout << ans << endl;
  return 0;
} //good night.