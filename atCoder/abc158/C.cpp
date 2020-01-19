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

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll a, b;
  cin >> a >> b;
  dll x = (dll)(0.08), y = (dll)(0.10);
  for(ll i = 1; i <= 2000; i++) {
  	ll v1 = (ll)((dll)(i) * x), v2 = (ll)((dll)(i) * y); 
  	if(v1 == a and v2 == b) {
  		cout << i << endl;
  		return 0;
  	}
  }
  cout << -1 << endl;
  return 0;
} //good night.