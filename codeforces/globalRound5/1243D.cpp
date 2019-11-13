//verma_ankit484
 
#include<bits/stdc++.h>
 
typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;
 
using namespace std;
 
set<ll> st;
vector<set<ll>> adj;
 
// vector<ll> cn;
stack<ll> cn;
void dfs(ll s) {
  if (st.size() == 0 or adj[s].size() == 0) goto here;
  while(!st.empty()) {
    if (st.size() == 0) break;
    auto i = *st.begin();
    if (adj[s].find(i) == adj[s].end()) {
      // cn.pb(i);
      cn.push(i);
      st.erase(i);
    }
  }
  here:
  while (!cn.empty()) {
    if (cn.size() == 0) break;
    ll k = cn.top();
    cn.pop();
    dfs(k);
    if (cn.size() == 0) break;
  }
}
 
int main() {
  IOS
  #ifdef SHAN
  freopen("input.txt", "r", stdin);
  #endif
  ll n, m;
  cin >> n >> m;
  adj.resize(n+1);
  for (ll i = 1; i <= n; i++) st.insert(i);
  for (ll i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }
  ll c = 0;
  while (1) {
    if (st.size() == 0) break;
    ll p = *st.begin();
    st.erase(p);
    dfs(p);
    c++;
  }
  cout << c-1 << endl;
  return 0;
}