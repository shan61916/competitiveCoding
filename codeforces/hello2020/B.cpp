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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  vll mn(n), mx;
  ll tot = 0;
  vector<bool> isit(n, false);
  for(ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ll mnn = inf, mxx = -inf;
    for(ll j = 0; j < x; j++) {
      ll tp;
      cin >> tp;
      if(tp > mnn) isit[i] = true;
      mnn = min(mnn, tp);
      mxx = max(mxx, tp);
    }
    
    if(isit[i]) tot++;
    if(!isit[i])mx.pb(mxx);
    mn[i] = (mnn);
  }
  ll ans = 0;
  sort(all(mx));
  for(ll i = 0; i < n; i++) {
    ll xx = mn[i];  
    if(isit[i]) {
      ans+= n;
      continue;
    }
    ans+= tot;
    ans+= (ll)mx.size() - (upper_bound(all(mx), xx) - mx.begin());
  }
  cout << ans << endl;
  return 0;
} //good night.