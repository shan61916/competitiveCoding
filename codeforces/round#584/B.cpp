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
  vector<ll> a(100000, 0);
  string s;
  cin >> s;;
  for(ll i = 0; i < n; i++) {
  	ll x, y;
  	cin >> x >> y;
  	if(s[i] == '1') {
      a[0]++ ;
      a[y]--;
      for(ll j = y + x; j <= 10000; j+= 2*x) {
          a[j]++ ;
          a[j+x]--;
      }
  	}
  	if(s[i] == '0') {
  		for(ll j = y; j <= 10000; j+=2*x) {
  			a[j]++ ;
  			a[j+x]--;
  		}
  	}
  }
  // for(auto it: a) cout << it << " ";
  ll mx = 0;
  for(ll i = 1; i < 12000; i++) a[i]+=a[i-1];
  for(ll i = 0; i < 10000; i++) mx = max(mx, a[i]);
  cout << mx << endl;
  return 0;
} //good night.