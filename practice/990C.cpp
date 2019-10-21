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
  map<pair<ll, ll>, ll> key;
  string s;
  ll open = 0, close = 0;
  vector<pll> arr;
  for(ll i = 0; i < n; i++) {
  	cin >> s;
  	open = 0, close = 0;
  	for(auto it: s) {
  		if(it == '(') {
  			open++;
  		} else {
  			if(open) open--;
  			else close++;
  		}
  	}
  	arr.pb(mp(open, close));
  	key[mp(open, close)]+=1;
  }
  ll ans = 0;
  for(auto it: arr) {
  	ll x = it.ff;
  	ll y = it.ss;
  	if(x > 0 and y > 0) continue;
  	if(y == 0) {
  		ans+= key[mp(0, x)];
  	}
  }
  cout << ans << endl;
  return 0;
} //good night.