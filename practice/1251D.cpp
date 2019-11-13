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
ll n, s;
vector<pll> arr;
bool can(ll x) {
	ll ans = 0;
    vector<pll> todo;
    for(ll i = 0; i < n; i++) {
       if(arr[i].ss < x) todo.pb(arr[i]);
    }
    for(ll i = 0; i < n; i++) {
    	if(arr[i].ss >= x) todo.pb(arr[i]);
    }
	ll ct = 0;
	for(ct = 0; ct < n; ct++) {
		pll aux = todo[ct];
		if(ct < n/2) {
			ans+= aux.ff;
		}
		if(ct >= n/2) {
			if(aux.ss < x) return false;
			ans+= max(x, aux.ff);
		}
	}
	return ans <= s;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
    cin >> n >> s;
    arr.clear();
    arr.resize(n);
    for(ll i = 0; i < n; i++) {
    	cin >> arr[i].ff >> arr[i].ss;
    }
    sort(all(arr));
    ll low = 1, high = s, ans = 0, mid;
    while(low <= high) {
    	mid = (low + high)/2;
    	if(can(mid)) {
    		ans = mid;
    		low = mid + 1;
    	} else {
    	   high = mid - 1;
    	}
    }
    cout << ans << endl;
  }
  return 0;
} //good night.