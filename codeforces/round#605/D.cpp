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
  ll n;
  cin >> n;
  vll a(n+1);
  for(ll i = 1; i <= n; i++) cin >> a[i];
  vll dp(n+2, 0);
  dp[1] = 1;
  for(ll i = 2; i <= n; i++) {
    if(a[i] > a[i-1]) dp[i] = dp[i-1] + 1;
    else dp[i] = 1;
  }
  vll dp2(n+2, 0);
  dp2[n] = 1;
  for(ll i = n-1; i >= 1; i--) {
    if(a[i] < a[i+1]) dp2[i] = 1 + dp2[i+1];
    else dp2[i] = 1;
  }
  ll ans = 1;
  for(ll i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
    if(a[i-1] < a[i+1]) ans = max(ans, dp[i-1] + dp2[i+1]);
  }
  cout << ans << endl;
  return 0;
} //good night.