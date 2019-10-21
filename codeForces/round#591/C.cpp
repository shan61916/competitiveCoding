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
vector<ll> arr;
ll x, a, b, y, k;
ll times(ll per, ll val) {
	val/=100;
	return (val * per);
}

bool can(ll mid) {
	ll gcd = __gcd(a, b);
	ll both = (a/gcd)*b; 
	both = mid/both ;
    ll fir = (mid/a) - both;
    ll sec = (mid/b) - both;
    ll ct = 0;
    for(ll i = 0; i < both; i++){
     ct+= times((x+y), arr[i]);
    }
    for(ll i = both; i < min(n, both + fir); i++) {
    	ct+= times(x, arr[i]);
    }
    for(ll i = both + fir; i < min(n, both + fir + sec); i++) {
    	ct+= times(y, arr[i]);
    }

    if(ct >= k) return true;
    return false;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    cin >> n;
    arr.resize(n, 0);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    sort(all(arr), greater<ll>());
    cin >> x >> a >> y >> b >> k;
    if(x < y) {
    	swap(x, y);
    	swap(a, b);
    }
    ll low = 1, high = n, mid, ans = -1;
    // can(6);
    while(low <= high) {
    	mid = (low + high)/2;
    	if(can(mid)) {
    		ans = mid;
    		high = mid - 1;
    	} else {
    		low = mid + 1;
    	}
    }
    cout << ans << endl;
  }
  return 0;
} //good night.