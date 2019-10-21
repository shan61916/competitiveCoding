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
  vector<ll> a;
  ll xorr = 0;
  a.pb(0);
  for(ll i = 0; i < n; i++) {
  	ll t;
  	cin >> t;
  	xorr^= t;
  	a.pb(xorr);
  }
  unordered_map<ll, ll> odd; 
  unordered_map<ll, ll> even;
  // for(auto it: a) cout << it << " ";
  // 	cout << endl;
  for(ll i = 0; i < (ll)a.size(); i++) {
     if(i%2) {
     	odd[a[i]]++;
     } else {
     	even[a[i]]++;
     }
  }
  ll ans = 0;
  for(ll i = 0; i < (ll)a.size(); i++) {
  	if(i%2) {
  		odd[a[i]]--;
  		ans+= odd[a[i]];
  	} else {
  		even[a[i]]--;
  		ans+= even[a[i]];
  	}
  }
  cout << ans << endl;
  return 0;
} //good night.