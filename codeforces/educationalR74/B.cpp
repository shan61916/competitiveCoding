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
vector<ll> a;
ll n, k;
bool can(ll x) {
	ll till = 0;
	ll done = 0;
	ll last = -1;
	for(ll i = 0; i < n; i++) {
		if(a[i] - till <= 0 or a[i] == last) continue;
        else {
        	till+= k;
        	done++;
        	last = a[i];
        }
	}
	if(done <= x) return true;
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
   cin >> n >> k;
   a.resize(n); 
   for(ll i = 0; i < n; i++) cin >> a[i];
   sort(all(a), greater<ll>());
   ll low = 1, high = n, mid, ans = 0;
   while(low <= high) {
   	mid = (low + high)/2;
   	if(can(mid)) {
   		high = mid - 1;
   		ans = mid;
   	} else {
   		low = mid + 1;
   	}
   }
   cout << ans << endl;
  }
  return 0;
} //good night.