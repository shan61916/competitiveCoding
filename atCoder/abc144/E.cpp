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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  auto can = [&](ll x) -> bool {
    ll reqd = 0;
    for(ll i = 0; i < n; i++) {
    	if(a[i] * b[i] <= x) continue;
    	ll isp = x/b[i];
    	reqd+= a[i] - isp;
    }
    return reqd <= k;
  };
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) cin >> b[i];
  sort(all(a), greater<ll>());
  sort(all(b));
  ll low = 0, high = (ll)(1e18), ans = -1, mid;
  while(low <= high) {
  	mid = (low + high)/2;
  	if(can(mid)) {
  		ans =  mid;
  		high = mid - 1;
  	} else {
  		low = mid+1;
  	}
  }
  cout << ans << endl;
  return 0;
} //good night.