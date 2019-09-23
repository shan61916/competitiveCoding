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
vector<ll> a; 
ll can(ll x) {
	ll ans = -1;
	for(ll i = 0; i < n; i++) {	
		if(a[i] % k ==0) {
			if(a[i] < x) return -1; 
			ll p = a[i];
			while(p >= x) {
				ans = max(ans, p);
				p/=k;
			}

		} 
		else if(a[i]%k) {
			if(a[i] >= x) ans = max(ans, a[i]); 
			else if(a[i]*k >= x) ans = max(ans, a[i]*k) ;
			else return -1;
		}
	}
	return ans;
}
int main(){
 // IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    cin >> n >> k;
    a.resize(n);
    ll low = 0, high = 1e10; 
    ll mid, ans = INT_MAX; 
    for(ll i = 0; i < n; i++) cin >> a[i];
    while(low <= high) {
    	mid = (low + high)/2; 
    	ll an= can(mid) ;
    	// cout << an << endl;
    	if(an == -1) {
    		high = mid - 1;
    	} else {
    		cout << an << endl;
    		ans = min(ans, abs(an - mid));
    		low = mid + 1;
    	}
    }
    // cout << ans << endl;
  }
  return 0;
} //good night.