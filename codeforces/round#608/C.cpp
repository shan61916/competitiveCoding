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
  ll n, x, y;
  cin >> n >> x >> y;
  vector<pll> a(n); 
  for(ll i = 0; i < n; i++) cin >> a[i].ff >> a[i].ss;
  ll xx = x-1, yy = y;
  ll ct = 0;
  vector<pair<ll, pll>> ans;
  ct = 0;
  for(ll i = 0; i < n; i++) {
    if(xx >= min(a[i].ff, x) and xx <= max(a[i].ff, x) and yy >= min(a[i].ss, y) and yy <= max(a[i].ss, y)) {
      ct++;
    }
  }
  ans.pb(mp(ct, mp(xx, yy)));
  xx = x + 1, yy = y;
  ct = 0;
  for(ll i = 0; i < n; i++) {
    if(xx >= min(a[i].ff, x) and xx <= max(a[i].ff, x) and yy >= min(a[i].ss, y) and yy <= max(a[i].ss, y)) {
      ct++;
    }
  }
  ans.pb(mp(ct, mp(xx, yy)));
  xx = x, yy = y + 1;
  ct = 0;
  for(ll i = 0; i < n; i++) {
    if(xx >= min(a[i].ff, x) and xx <= max(a[i].ff, x) and yy >= min(a[i].ss, y) and yy <= max(a[i].ss, y)) {
      ct++;
    }
  }
  ans.pb(mp(ct, mp(xx, yy)));
  xx = x, yy = y - 1;
  ct = 0;
  for(ll i = 0; i < n; i++) {
    if(xx >= min(a[i].ff, x) and xx <= max(a[i].ff, x) and yy >= min(a[i].ss, y) and yy <= max(a[i].ss, y)) {
      ct++;
    }
  }
  ans.pb(mp(ct, mp(xx, yy)));
  sort(all(ans), greater<pair<ll, pll>>());
  for(auto it: ans) {
    if(it.ss.ff >= 0 and it.ss.ss >= 0) {
      cout << it.ff << endl;
      cout << it.ss.ff << " " << it.ss.ss << endl;
      return 0;
    }
  }
  return 0;
} //good night.