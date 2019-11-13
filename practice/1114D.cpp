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
ll sz, curr, n;
vector<pll> arr; 
ll dp[5001][5001];
ll recurse(ll x, ll y) {
  if(x == y) return 0;
  ll &ans = dp[x][y];
  if(ans != -1) return ans;
  ans = 0;
  if(arr[x].ff == arr[y].ff) {
    return ans = 1 + recurse(x+1, y-1);
  }
  ans = 1 + recurse(x+1, y);
  ans = min(ans, 1 + recurse(x, y-1));
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  vll a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) {
    ll j = i;
    ll x = a[i];
    ll ct = 0;
    while(j < n and a[j] == x) {
      ct++; 
        j++;
    }
    arr.pb(mp(x, ct));
    i = j-1;
  }
  sz = arr.size();
  memset(dp, -1, sizeof dp);
  ll ans = recurse(0, sz-1);
  cout << ans << endl;
  return 0;
} //good night.
