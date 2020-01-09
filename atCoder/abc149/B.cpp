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
ll dp[200010][3];
ll dfs(ll idx, ll parent, ll color) {
  ll &ans = dp[idx][color];
  if(ans != -1) return ans;
  ans = 0;
  ll x1 = 0, x2 = 0;
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    x1+= max(x1, dfs(it, idx, 0));
    if(color == 0) {
      ans = max(x2, 1 + dfs(it, idx, 1));
    }
  }
  ans = x1 + x2;
  return ans;
} 
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  adj.resize(n + 1);
  for(ll i = 0; i < n-1; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  memset(dp, -1, sizeof dp);
  ll ans = 0;
  ans = max(dfs(1, -1, 1), dfs(1, -1, 0));
  cout << ans << endl;
  return 0;
} //good night.