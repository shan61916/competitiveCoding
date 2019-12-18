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
vector<bool> visited;
vector<ll> ans;
vector<vll> adj;
vll a;
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  adj.resize(n+1);
  a.resize(n+1);
  ans.resize(n+1, inf);
  set<pll> st;
  for(ll i = 1; i <= n; i++) {
    cin >> a[i];
    if(i + a[i] <= n) {
      adj[i + a[i]].pb(i);
    }   
    if(i - a[i] >= 1) {
      adj[i - a[i]].pb(i);
    }
  }
  for(ll i = 1; i <= n; i++) {
    if( i + a[i] <= n and (a[i]%2 != a[i + a[i]]%2)) {
      ans[i] = 1;
      st.insert(mp(ans[i], i));
    }
    if(i - a[i] >= 1 and (a[i]%2 != a[i - a[i]]%2)) {
      ans[i] = 1;
      st.insert(mp(ans[i], i));
    }
  }
  while(!st.empty()) {
    pll xx = *st.begin();
    ll u = xx.ss;
    st.erase(st.begin());
    for(auto it: adj[u]) {
      ll nx = ans[it];
      ll can = inf;
      if(a[it]%2 != a[u]%2) {
        can = 1;
      } else {
        can = 1 + ans[u];
      }
      if(can < nx) {
        st.erase({nx, it});
        ans[it] = can;
        st.insert({can, it});
      }
    }
  }
  for(ll i = 1; i <= n; i++) {
    if(ans[i] < inf) cout << ans[i];
    else cout << -1 ;
    cout << " ";
  }
  return 0;
} //good night.