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
  ll T;
  cin >> T;
  while(T--){
  ll n;
  cin >> n;
  vector<ll> a(n), b(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) {
  	auto it = upper_bound(all(a), a[i]);
  	if(it != a.end()) {
  		b[i] = (n ) - (ll)(it - a.begin());
  	} else b[i] = 0;
  }
  for(auto it : b) cout << it << " ";
  cout << endl;
  }
  return 0;
} //good night.