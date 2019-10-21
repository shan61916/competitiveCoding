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
  ll n;
  cin >> n;
  vector<ll> a(n), b(n), c(n), d(n);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<ll> arr1, arr2;
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) {
  	  arr1.pb(a[i] + b[j]);
  	  arr2.pb(c[i] + d[j]);
    }
  }
  sort(all(arr2)); 
  for(auto et: arr1) {
  	auto it = equal_range(arr2.begin(), arr2.end(), -et);
  	ans+= (ll)(it.second - it.first);
  }
  cout << ans << endl;

  return 0;
} //good night.