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
const ll mxx = 200100;
ll n; 
vll a(200100); 
vll segtree(800010);
ll merge(ll x, ll y) {
  if(a[x] < a[y]) return x;
  return y;
}
void build(ll t, ll tl, ll tr) {
  if(tl == tr) {
    segtree[t] = tl;
    return;
  }
  ll mid = (tl + tr)/2;
  build(2*t, tl, mid);
  build(2*t+1, mid+1, tr);
  segtree[t] = merge(segtree[2*t], segtree[2*t + 1]);
  return;
}
ll query(ll t, ll tl, ll tr, ll l, ll r) {
  if(tl > tr or l > r or tl > r or l > tr) return mxx-1;
  if(l <= tl and tr <= r) { 
    return segtree[t];
  }
  ll mid = (tl + tr)/2;
  ll x = query(2*t, tl, mid, l, r);
  ll y = query(2*t+1, mid+1, tr, l, r);
  return merge(x, y);
}
ll binsearch(ll x, ll tofind) {
  ll low = x, high = 2*n-1, ans = -1, mid, v, v2;
  while(low < high) {
    mid = (low + high)/2;
    v = query(1, 0, 2*n - 1, low, mid);
    v2 = query(1, 0, 2*n -1, mid+1, high);
    if(a[v] < tofind) {
      ans = v;
      high = mid;
    } else if(a[v2] < tofind){
      ans = v2;
      low = mid + 1;
    } else {
      return -1;
    }
  }
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  set<ll> lrg;
  vector<pll> arr; 
  vll ans(n, INT_MAX);
  a[mxx-1] = INT_MAX;
  for(ll i = 0; i < n; i++) {
    ll tp;
    cin >> tp;
    a[i] = tp;
    arr.pb(mp(tp, i));
  }
  for(ll i = n; i < 2*n; i++) {
    a[i] = a[i%n];
  }
  if((2*(*min_element(a.begin(), a.begin() + n))) >= *max_element(a.begin(), a.begin()+n)) {
    for(ll i = 0; i < n; i++) {
      cout << -1 << " ";
    }
    return 0;
  }
  build(1, 0, 2*n-1);
  sort(all(arr), greater<pll>());
  for(auto it: arr) {
    ll curr = INT_MAX;
    if(!lrg.empty()) {
      auto et = lrg.upper_bound(it.ss);
      if(et == lrg.end()) et = lrg.begin();
      curr = ans[(*et)] + ((*et) - it.ss + n)%n;
    }
    // cout << curr << endl;
    ll tofind = (it.ff + 1)/2;
    ll tp = binsearch(it.ss+1, tofind);
    if(tp != -1) {
      curr = min(curr, (tp - it.ss));
    }     
    ans[it.ss] = curr;
    lrg.insert(it.ss);
  }
  for(ll i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
} //good night.