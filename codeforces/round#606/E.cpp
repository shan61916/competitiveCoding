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
ll a, b,n;
vector<set<ll>> adj;
vector<bool> visited;
set<ll> et, st;
void dfs(ll idx, ll t) {
  visited[idx] = true;
  if(t)et.insert(idx);
  else st.insert(idx);
  if(t == 1 and idx == b) {
     return;
   }
   if(t == 0 and idx == a) {
     return;
   }
   for(auto it: adj[idx]) {
    if(!visited[it]) dfs(it, t);
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
    ll m;
    cin >> n >> m >> a >> b;
    adj.resize(n+2);
    for(ll i = 1; i <= n; i++) adj[i].clear();
    visited.resize(n+1, false);
    for(ll i = 1; i <= m; i++) {
      ll xx, yy;
      cin >> xx >> yy; 
      adj[xx].insert(yy);
      adj[yy].insert(xx); 
    }
    visited.assign(n+1, false);
    st.clear(), et.clear();
    dfs(a, 1);
    visited.assign(n+1, false);
    dfs(b, 0);
    ll rem1 = n - st.size();
    ll rem2 = n - et.size();
    cout << rem1*rem2 << endl;
  }
  return 0;
} //good ni