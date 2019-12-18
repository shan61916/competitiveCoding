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
vector<vector<pll>> adj;
ll n;
ll recurse(ll idx, ll mask) {
  if(idx == n) {
    bool foo = true;
    for(ll i = 0; i < n; i++) {
      if(mask&(1ll<<i)) {
        for(auto it: adj[i+1]) {
          ll zz = (((mask)&(1ll<<(it.ff-1))) > 0);
          if(it.ss != zz) foo = false;
        }
      }
    } 
    if(foo) return __builtin_popcountll(mask);
    return -inf;
  }
  ll ans = -inf; 
  ans = max(ans, recurse(idx+1, mask));
  ans = max(ans, recurse(idx+1, (mask|1ll<<idx)));
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  adj.resize(n+1);
  for(ll i = 1; i <= n; i++) {
    ll sz;
    cin >> sz;
    for(ll j = 0; j < sz; j++) {
      ll x, y;
      cin >> x >> y;
      adj[i].pb(mp(x, y));
    }
  }
  ll ans = max(0LL, recurse(0, 0));
  cout << ans << endl;
  return 0;
} //good night.