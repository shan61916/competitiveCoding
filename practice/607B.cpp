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
ll n;
vll pos, power; 
ll dp[100010][2];
ll recurse(ll idx, ll mode) {
  if(idx <= 0) return 0;
  ll &ans = dp[idx][mode];
  if(ans != -1) return ans;
  ans = 0;
  ll nidx = pos[idx] - power[idx];
  ll tg = lower_bound(all(pos), nidx) - pos.begin();
  tg--;
  ans = 1 + recurse(tg, 0);
  if(mode == 1) {
    ans = max(ans, recurse(idx-1, 1));
  }
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  vector<pll> arr(n);
  for(auto &it: arr) cin >> it.ff >> it.ss;
  sort(all(arr));
  pos.resize(n+1, 0), power.resize(n+1, 0);
  power[0] = INT_MAX;
  for(ll i = 1; i <= n; i++) {
    pos[i] = arr[i-1].ff;
    power[i] = arr[i-1].ss;
  }
  memset(dp, -1, sizeof dp);
  ll ans = recurse(n, 1);
  cout << n - ans << endl;
  return 0;
} //good night.