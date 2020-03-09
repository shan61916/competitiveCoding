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
  string s;
  cin >> s;
  ll n = (ll)(s.length());
  ll mx = 0;
  for(ll i = 0; i < 26; i++) {
  	ll xx = count(all(s), (char)(i+'a'));
  	mx = max(mx, (xx*(xx-1))/2);
  	mx = max(mx, xx);
  }
  for(ll i = 0; i < 26; i++) {
  	vll ct(26, 0);
  	ll tot = 0;
  	for(ll j = 0; j < n; j++) {
  		if(s[j] == (char)(i+'a')) {
  			tot++;
  		}
  		else ct[(ll)(s[j]-'a')]+=tot;
  	}
  	for(ll ii = 0; ii < 26; ii++) mx = max(mx, ct[ii]);
  }
  cout << mx << endl;
  return 0;
} //good night.