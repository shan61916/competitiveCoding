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
ll n, h;
vector<ll> a(14), b(14);
ll recurse(ll idx, ll mask1, ll mask2) {
	if(idx == n) {
		ll tot1 = 0, tot2 = 0;
		for(ll i = 0; i < 13; i++) {
			if((mask1&(1<<i))) {
				tot1+= a[i];
			}
		}
		for(ll i = 0; i < 13; i++) {
			if((mask2&(1<<i))) {
				tot2+= b[i];
			}
		}
		if(tot1 >= h and tot2 >= h) return 1;
		return 0;
	}
	ll ans = 0;
	ans+= recurse(idx+1, mask1|(1ll<<idx), mask2) ;
	ans+= recurse(idx+1, mask1, mask2|(1ll<<idx));
	ans+= recurse(idx+1, mask1|(1ll<<idx), mask2|(1ll<<idx));
	return ans;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll tc = 1;
  ll T;
  cin >> T;
  while(T--) {
  cout << "Case #" << tc++ << ": "; 
  cin >> n >> h;
  for(ll i = 0; i < n; i++) cin >> a[i] ;
  for(ll i = 0; i < n; i++) cin >> b[i];
  ll ans = recurse(0, 0, 0);
  cout << ans << endl;
  }
  return 0;
} //good night.