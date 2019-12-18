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

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, m;
  cin >> n >> m;
  vll given(n+1);
  vll rem(n+1, 0);
  for(ll i = 0; i < m; i++) {
    ll x, y, z;
    cin >> x >> y >> z;
    rem[x]-= z;
    rem[y]+= z;
  } 
  set<pll> lt;
  set<pll, greater<pll>> st;
  for(ll i = 1; i<= n; i++) {
    if(rem[i] < 0) lt.insert(mp(abs(rem[i]), i));
    if(rem[i] > 0) st.insert(mp(rem[i], i));
  }
  vector<pair<ll, pll>> ans;
  while(!lt.empty()) {
    ll xx = lt.begin()->second;
    ll u = lt.begin()->first;
    lt.erase(lt.begin());
    while(!st.empty()) {
      pll gv = *st.begin();
      st.erase(st.begin());
      if(gv.ff > u) {
        ans.pb(mp(xx, mp(gv.ss, u)));
        gv.ff-=u;
        st.insert(gv);
        u = 0;
        break;
      } else {
        ans.pb(mp(xx, mp(gv.ss, gv.ff)));
        u-= gv.ff;
      }
    }
  }
  cout << ans.size() << endl;
  for(auto it : ans) cout << it.ff << " " << it.ss.ff << " " << it.ss.ss << endl;
  return 0;
} //good night.