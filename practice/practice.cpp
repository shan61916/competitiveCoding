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
// ll modsub(ll x, ll y){return (x%mod - y%mod + mod)%mod;}
ll turn = 1;
void inc() {turn+=1;}
vector<vll> adj;
vector<ll> visited(100010, 0), had;
vector<ll> val(100010, 0);
void dfs(ll idx) {
  visited[idx] = turn;
  had[idx] = 1;
  for(auto it: adj[idx]) {
    if(visited[idx] == turn) continue;
    if(val[idx] == 1) val[it] = 2, dfs(it);
    else val[it] = 1, dfs(it);
  }
}
ll ans;
void reset(){ans = 1;};
void calc(ll idx) {
  for(auto it: adj[idx]) {
    if(visited[it] == turn) {
      if(val[it] == val[idx]) ans = modmul(0LL, ans);
      continue;
    }
    ans = modmul(ans, val[it]);
    dfs(it);
  }
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--) {
    ll n, m;
    cin >> n >> m;
    adj.clear();
    adj.resize(n+1);
    had.resize(n+1, 0);
    for(ll i = 1; i <= m; i++) {
      ll x, y;
      cin >> x >> y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    inc();
    ll res = 1;
    for(ll i = 1; i <= n; i++) {
      if(had[i] == 1) continue;
      val[i] = 1;
      ll pp = 0;
      inc();
      dfs(i);
      inc();
      reset();
      calc(i);
      pp = modadd(pp, ans);
      reset();
      inc();
      val[i] = 2;
      dfs(i);
      inc();
      calc(i);
      pp = modadd(pp, modmul(ans, 2LL));
      res = modmul(res, pp);
    }
    cout << res << endl;
  }
  return 0;
} //good night.