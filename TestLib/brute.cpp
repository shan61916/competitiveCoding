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
ll dp[1001][1001];
ll a[1001];
ll n, k;
ll recurse(ll idx, ll prev) {
  if(idx == n - 1) return 0;
  ll &ans = dp[idx][prev];
  if(ans != -1) return ans;
  ans = inf;
  if(idx+1 - prev <= k) ans = recurse(idx+1, prev);
  ans = min(ans, a[idx] + recurse(idx+1, idx));
  return ans;
}

int main(){
  cin >> n >> k;
  memset(dp, -1, sizeof dp);
  for(ll i = 0; i < n; i++) cin >> a[i];
  if(n == 1) {cout << 0 << endl; return 0;}
  ll ans = a[0] + recurse(1, 0);
  cout << ans << endl;
  return 0;
} //good night.