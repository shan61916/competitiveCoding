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
  ll T;
  cin >> T;
  while(T--) {
  	ll a, b;
  	cin >> a >> b;
  	ll xx = 9;
  	ll ct1 = 0, ct2 = 0;
  	while(1) {
  		if(a/xx > 0) ct1++;
  		else break;
  		xx*=10;
  		xx+=9;
  	}
  	xx = 9;
  	while(1) {
  		if(b/xx > 0) ct2++;
  		else break;
  		xx*=10;
  		xx+=9;
  	}

  }
  return 0;
} //good night.