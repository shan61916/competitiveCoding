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
const ll inf = (ll)(1e9 + 7);
ll n, c;
ll dp[200010][2];
vll a, b;

ll recurse(ll idx, ll mode) {
 if(idx == 0) {
     return 0;
 }
 ll &ans = dp[idx][mode];
 if(ans != -1) return ans;
 ans = inf;
 if(mode == 1) {
 	ans = min(ans, a[idx-1] + recurse(idx-1, 0));
 	ans = min(ans, b[idx-1] + recurse(idx-1, 1));
 } 
 if(mode == 0) {
 	ans = min(ans, b[idx-1] + c + recurse(idx-1, 1));
 	ans = min(ans, a[idx-1] + recurse(idx-1, 0));
 }
 return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> c;
  a.resize(n);
  b.resize(n);
  for(ll i = 0; i < n-1; i++) cin >> a[i];
  for(ll i = 0; i < n-1; i++) cin >> b[i];
  memset(dp, -1, sizeof(dp));
  cout << 0 << " ";
  for(ll i = 1; i < n; i++) {
      cout << min(recurse(i, 0), c + recurse(i, 1)) << " ";
  }
  return 0;
} //good night.