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
const ll mxx = (1ll << 22);

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  vector<ll> a(n);
  unordered_map<ll, ll> mp;
  vll dp(mxx, 0);
  vll ans(mxx, -1);
  for(ll i = 0; i < n; i++) {
    ll tp;
    cin >> tp;
    mp[tp]++;
    a[i] = tp;
    dp[tp]++;
    ans[tp] = tp;
  }
  for(ll i = 0; i < 22; i++) {
    for(ll j = 0; j < mxx; j++) {
      if(j&(1ll<<i)) {
        dp[j]+= dp[(j^(1ll<<i))];
        if(dp[(j^(1ll<<i))])ans[j] = ans[(j^(1ll<<i))];
      }
    }
  }
  ll toxor = mxx-1;
  for(ll i  = 0; i < n; i++) {
    cout << ans[(toxor^a[i])] << " ";
  }

  return 0;
} //good night.