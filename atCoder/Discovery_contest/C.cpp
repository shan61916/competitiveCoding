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
vector< vector<ll> > segtree(800125);
vector<ll> arr(800125,0);

vector<ll> combine( vector<ll> a , vector<ll> b) {
  vector<ll> merged;
  merge(all(a), all(b), back_inserter(merged)); 
  return merged ;
}

void build(ll t, ll tl, ll tr) {
  if(tl==tr) {
    segtree[t].push_back(arr[tl]) ;
  }
  else {
    ll mid= (tl+tr)/2 ;
    build(2*t,tl,mid) ;
    build(2*t+1,mid+1, tr) ;
    segtree[t]= combine(segtree[2*t],segtree[2*t+1]) ;
  }
}

vector<ll> query(ll t, ll tl, ll tr, ll l, ll r) {
  if(l>tr or r<tl) {
    vector<ll> tt ;
    return tt ;
  }
  if(tl>=l and tr<=r) {
    return segtree[t] ;
  }
  ll mid= (tl+tr)/2 ;
  vector<ll> x= query(2*t,tl, mid, l, r) ;
  vector<ll> y= query(2*t+1,mid+1,tr,l,r) ;
  vector<ll> z= combine(x,y) ;
  return z ;
}

bool cmp(pll x, pll y) {
  if(x.ff == y.ff) {
    return (x.ss < y.ss);
  }
  return x.ff > y.ff;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  unordered_map<ll, ll> key;
  vector<pll> a(n); 
  for(ll i = 0; i < n; i++) {
    cin >> a[i].ff; 
    key[i+1] = a[i].ff; 
    a[i].ss = i + 1 ;
  }
  sort(all(a), cmp);
  for(ll i = 0; i <  n; i++) {
    arr[i+1] = a[i].ss;
  }
  build(1, 1, n);
  ll q, x, y;
  vll ans;
  cin >> q;
  while(q--) {
    cin >> x >> y;
    ans.clear();
    ans = query(1, 1, n, 1, x);
    cout << key[ans[y-1]] << endl;
  }
  return 0;
} //good night.