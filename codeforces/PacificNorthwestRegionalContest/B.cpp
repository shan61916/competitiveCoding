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
const int MAX = 1e3 + 3;
const int MOD = 998244353;
vll a;
ll n, k;
map<ll, pair<ll, ll>> key;
ll modmul(ll x, ll y) {
  return (x%MOD * y%MOD)%MOD;
}
ll modadd(ll x, ll y) {
  return (x%MOD + y%MOD)%MOD;
}
ll dp[1001][1001];
ll recurse(ll idx, ll tot) {
  if(idx == n) {
    if(tot == k) return 1;
    return 0;
  }
  ll &ans = dp[idx][tot];
  if(ans != -1) return ans;
  ans = 0;
  ll end = key[a[idx]].ss;
  ans = modadd(ans, recurse(idx+1, tot));
  ans = modadd(ans, recurse(end+1, tot+1));
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> k;
  a.resize(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  sort(all(a)); 
  memset(dp, -1, sizeof dp);
  for(auto it: a) key[it].ff = -1, key[it].ss = -1;
  for(ll i = 0; i < n; i++) {
    if(key[a[i]].ff == -1) {
      key[a[i]].ff = i;
    } else {
      key[a[i]].ss = i;
    }
  }
  for(ll i = 0; i < n; i++) {
    if(key[a[i]].ff != -1 and key[a[i]].ss == -1) key[a[i]].ss = key[a[i]].ff;
  }
  ll ans = recurse(0, 0);
  cout << ans << endl;
  return 0;
} //good night.