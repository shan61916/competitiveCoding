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
  ll x, y, n1, n2, n3;
  cin >> x >> y >> n1 >> n2 >> n3;
  vll a(n1), b(n2), c(n3);
  for(auto &it : a) cin >> it;
  for(auto &it: b) cin >> it;
  for(auto &it: c) cin >> it;
  sort(all(a));
  sort(all(b));
  sort(all(c), greater<ll>());
  ll curra = n1 - x , currb = n2 - y, currc = 0;
  for(ll i = 0; i < n3; i++) {
  	ll aa = 0, bb = 0;
  	if(curra < n1)aa = c[currc] - a[curra];
  	if(currb < n2)bb = c[currc] - b[currb];
  	if(aa >= bb and aa > 0) {
  		a[curra] = c[currc];
  		curra++;
  		currc++;
  	} else if(bb > aa and bb > 0) {
  		b[currb] = c[currc];
  		currb++;
  		currc++;
  	}
  }
  ll ans = 0;
  for(ll i = n1 - x; i < n1; i++){ ans+= a[i]; }
  for(ll i = n2 - y; i < n2	; i++){ ans+= b[i]; }
  cout << ans << endl;
  return 0;
} //good night.