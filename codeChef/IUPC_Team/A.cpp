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
vector<vll> adj(100010);
vll visited(100010, 0);
ll node, mx;
void dfs(ll idx, ll parent, ll dist) {
  visited[idx] = 1;
  if(dist > mx) {mx = dist; node = idx;}
  for(auto it: adj[idx]) {
    if(it == parent) continue;
    dfs(it, idx, dist + 1);
  }
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, m;
  cin >> n >> m;
  for(ll i = 0; i < m; i++) {
    ll x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  ll ans = 0;
  for(ll i = 1; i <= n; i++) {
    if(visited[i] == 0) {
      visited[i] = 1;
      mx = -1;
      dfs(i, -1, 0);
      dfs(node, -1, 1);
      ans = max(ans, mx/2);
    } else continue;
  }
  cout << ans << endl;
  return 0;
} //good night.