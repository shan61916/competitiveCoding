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
const ll mod = (ll)(998244353);
ll modadd(ll x, ll y){return (x%mod + y%mod)%mod;}
ll modmul(ll x, ll y){return (x%mod * y%mod)%mod;}
ll modsub(ll x, ll y){return (x%mod - y%mod + mod)%mod;}
// ll moddiv(ll x, ll y){return modmul(x, fast_exp(y, mod-2));}
ll n, m;
vector<vll> adj;
ll turn = 2;
void inc() {turn++;}
vll visited(100001), val(100001, 0), had(100010);
ll ans = 1;
void dfs(ll idx) { 
  had[idx] = 1;
  visited[idx] = turn;
  // set<ll> st;
  for(auto it: adj[idx]) {
    if(visited[it] == turn) {
      if(val[idx] == val[it]) {
        ans*=0LL;
      }
      continue;
    }
    if(val[idx] == 1) {
      val[it] = 2;
      visited[it] = turn;
      dfs(it);
      // st.insert(it);
    } else {
      visited[it] = turn;
      // st.insert(it);
      val[it] = 1;
      ans = modmul(ans, 2LL);
      dfs(it);
    }
  }
  // for(auto it: st) {
  //   dfs(it);
  // }
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--) {
    cin >> n >> m;
    adj.clear();
    adj.resize(n+1);
    had.assign(n+1, 0);
    for(ll i = 1; i <= m; i++) {
      ll x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    ll res = 1;
    for(ll i = 1; i <= n; i++) {
      if(had[i] == 1) continue;
      inc();
      ans = 1;
      val[i] = 1;
      dfs(i);
      ll a1 = modmul(2LL, ans);
      ans = 1;
      val[i] = 2;
      inc();
      dfs(i);
      ll a2 = ans;
      ll pp = modadd(a1, a2);
      res = modmul(res, pp);
    }
    cout << res << endl;
  }
  return 0;
} //good night.