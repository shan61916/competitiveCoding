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
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i];
  }
  auto can = [&](ll x) {
  	ll prev = 0;
  	for(ll i = 0; i < n; i++) {
  		if(a[i] < prev and (prev - a[i]) > x) return false;
  		if(a[i] > prev) {
  			if(((prev - a[i] + m)%m) <= x) continue;
  			else prev = a[i];
   		}
  	}
  	return true;
  };
  ll low = 0, high = m-1, ans, mid; 
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