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
set<ll> st; 
set<ll> adj[200010];

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll ans = 0;
  ll n, m;
  cin >> n >> m;
  for(ll i = 1; i <= n; i++) st.insert(i);
  for(ll j = 1; j <= m; j++) {
    ll x, y;
    cin >> x >> y;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  for(ll i = 1; i <= n; i++) {
    if(st.find(i) != st.end()) {
      ans++;
      queue<ll> qt;
      qt.push(i);
      while(!qt.empty()) {
        ll xx = qt.front();
        qt.pop();
        st.erase(xx);
        vll todo;
        for(auto it: st) {
          if(adj[xx].count(it)) continue;
          else if(st.count(it)) todo.pb(it);
        }
        for(auto it: todo) st.erase(it);
        for(auto it: todo) qt.push(it); 
      }
    }
  }
  cout << ans - 1 << endl;
  return 0;
} //good night.