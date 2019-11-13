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
ll n, k;
vll arr, les, gret;
bool can(ll x) {
	for(ll i = 0; i < n; i++) {
		ll tot = 0;
        tot+=(arr[i] * i) - les[i];
        ll tos = arr[i] + x;
        auto it = upper_bound(all(arr), tos);
        if(it != arr.end()) {
        	ll idx = it - arr.begin() - 1;
        	tot+= gret[idx] - (n - idx - 1)*(tos);
        }
        if(tot <= k) return true;
	}
	for(ll i = 0; i < n; i++) {
		ll tot = 0;
		tot+= gret[i] - (arr[i] * (n - i - 1));
		ll tos = arr[i] - x;
		auto it = lower_bound(all(arr), tos);
	    ll idx = it - arr.begin();
        tot+= (idx*tos) - les[idx];
        // if(x == 1 and arr[i] == 7) cout << tos << endl;
        if(tot <= k) return true;
	}

	return false;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> k;
  arr.resize(n);
  for(auto &x : arr) cin >> x;
  sort(all(arr));
  les.resize(n), gret.resize(n);
  ll tot = 0;
  for(ll i = 0; i < n; i++) {
  	les[i] = tot;
    tot+= arr[i];
  }
  tot  = 0;
  for(ll i = n-1; i >= 0; i--) {
    gret[i] = tot;
    tot+= arr[i];
  }

  ll low = 0, high = arr[n-1] - arr[0], ans = high, mid;
  while(low <= high) {
  	mid = (low + high)/2;
    if(can(mid)) {
    	ans = mid;
    	high = mid-1;
    } else {
    	low = mid+1;
    }
  }
  cout << ans << endl;
  return 0;
} //good night.