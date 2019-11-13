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
const ll maxx = (ll)(2 * (1e5 + 10));
const ll inf = (ll)(1e15 + 15);
ll n, now;
ll dp[maxx];
vector<pll> a;
vll res;
ll recurse(ll idx) {
  if(idx == n) return 0;
  if(idx + 3 > n) return inf;
  if(idx > n) return inf;
  ll &ans = dp[idx];
  if(ans != -1) return ans;
  ans = inf;
  for(ll i = 3; i < 6; i++) {
    if(idx + i - 1 <= n-1) {
      ans = min(ans, (a[idx + i - 1].ff - a[idx].ff) + recurse(idx + i));
	}
  }
  return ans;
}
void trace(ll idx) {
  if(idx == n) return;
  if(idx + 3 > n) return;
  if(idx > n) return;
  ll ans = recurse(idx);
  for(ll i = 3; i < 6; i++) {
    if(idx + i - 1 <= n-1) {
      ll tt = a[idx+i-1].ff - a[idx].ff + recurse(idx + i);
      if(tt == ans) {
        res[idx]-=now;
        res[idx]+= ++now;
        trace(idx + i);
        return;
      }
    }
  }
  return;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  a.resize(n);
  res.resize(n, 0);
  for(ll i = 0; i < n; i++) cin >> a[i].ff;
  for(ll i = 0; i < n; i++) a[i].ss = i;
  sort(all(a));
  // for(auto it: a) cout << it.ff << endl;
  memset(dp, -1, sizeof dp);
  ll ans = recurse(0); 
  now = 0;
  trace(0);
  cout << ans << " " << now << endl;
  for(ll i = 1; i < n; i++) res[i]+=res[i-1];
  vll fin(n); 
  for(ll i = 0; i < n; i++) {
    fin[a[i].ss] = res[i];
  }
  for_each(all(fin), [](ll x){cout << x <<" ";});
  return 0;
} //good night.