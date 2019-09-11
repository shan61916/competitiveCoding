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
ll n, k;
const ll mod = (ll)(1e9 + 7);
vector<vll> adj;
ll ans;
void dfs(ll idx, ll parent) {
  ll mul = k - 1;
  if(parent != -1) mul--;
  for(auto it: adj[idx]) {
  	if(it == parent) continue;
  	ans = (ans%mod * mul%mod)%mod;
  	if(mul <= 0) {
  		ans = 0;
  		return;
  	}
  	mul--;
  	dfs(it, idx);
  }
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> k;
  adj.resize(n+1); 
  for(ll i = 0; i < n-1; i++) {
  	ll x, y;
  	cin >> x >> y;
  	adj[x].pb(y);
  	adj[y].pb(x);
  }
  ans = k;
  dfs(1, -1);
  cout << ans << endl;
  return 0;
} //good night.