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
ll n;
vll a(200001, 0);
vll segtree(800010, 0);
void build(ll t, ll tl, ll tr) {
  if(tl == tr) {
    segtree[t] = a[tl];
    return;
  } 
  ll mid = (tl + tr)/2;
  build(2*t , tl, mid);
  build(2*t+1, mid+1, tr);
  segtree[t] = segtree[2*t] + segtree[2*t+1];
  return;
}
ll query(ll t, ll tl, ll tr, ll p) {
  if(tl > tr or p > tr or p < tl) return 0;
  if(tl >= p and tr <= p) {
    return segtree[t];
  }
  ll mid = (tl + tr)/2;
  return query(2*t, tl, mid, p) + query(2*t+1, mid+1, tr, p);
}
void update(ll t, ll tl, ll tr, ll p, ll val) {
  if(tl > tr or p > tr or p < tl) return;
  if(tl >= p and tr <= p) {
    segtree[t]+= val;
    return;
  }
  ll mid = (tl + tr)/2;
  update(2*t, tl, mid, p, val);
  update(2*t+1, mid+1, tr, p, val);
  segtree[t] = segtree[2*t] + segtree[2*t+1];
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  for(ll i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  map<pll, ll> key;
  map<ll, vll> wasted;
  map<ll, ll> w;
  ll q;
  cin >> q;
  while(q--) {
    ll x, y, z;
    cin >> x >> y >> z;
    if(key[mp(x, y)] >= 0) {
      ll zz = key[mp(x, y)];
      if(wasted[zz].size() > 0) wasted[zz].pop_back();
      else update(1, 1, n, zz, 1);
      key[mp(x, y)] = z;
    } 
    if(z == 0) {
      cout << segtree[1] << endl;
      continue;
    }
    ll p = query(1, 1, n, z);
    if(p == 0) {
      wasted[z].pb(x);
    } else {
      update(1, 1, n, z, -1);
    }  
    p = query(1, 1, n, z);
    // cout << p << endl;
    cout << segtree[1] << endl;
  }
  return 0;
} //good night.