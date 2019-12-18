  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   int ll;
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
const ll mxn = (ll)(2.1e5);
const ll bits = 23;
vll arr(mxn, 0);
vll logs(mxn, 0);
ll table[bits][mxn];
// compute logs beforehand.For true O(1) queries.
void pre_log() {
  logs[1] = 0;
  for(ll i = 2; i < mxn; i++)  logs[i] = logs[i/2] + 1;
}
void build(ll n) {
  for(ll i = 0; i <= logs[n]; i++) {
    ll len = (1LL << i);
    for(ll j = 0; j + len <= n; j++) {
      if(len == 1) {
        table[i][j] = arr[j]; 
      } else {
        table[i][j] = min(table[i-1][j], table[i-1][j + (len/2)]);
      }
    }
  }
}
ll query(ll l, ll r) {
  ll p = logs[r - l + 1];
  ll len = (1LL << p);
  return min(table[p][l], table[p][r - len + 1]);
}

ll binsearch1(ll x, ll val) {
  ll low = 0, high = x, mid, ans = 0, xx;
  while(low <= high) {
    mid = (low + high)/2;
    xx = query(mid, high); 
    if(xx < val) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

ll binsearch2(ll x, ll y, ll val) {
  ll low = x, high = y, ans = y + 1, mid, xx;
  while(low <= high) {
    mid = (low + high)/2;
    xx = query(low, mid);
    if(xx < val) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  arr.assign(n+2, inf);
  for(ll i = 1; i <= n; i++) cin >> arr[i];
  pre_log();
  build(n + 1);
  vll ans(n+1, 0);
  for(ll i = 1; i <= n; i++) {
    ll from = binsearch1(i, arr[i]);
    ll to = binsearch2(i, n, arr[i]);
    ll tot = (to - from - 1);
    ans[tot] = max(ans[tot], arr[i]);
  }
  for(ll i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i+1]);
  for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
} //good night.