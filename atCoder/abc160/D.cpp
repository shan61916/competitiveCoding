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
  ll n, x, y;
  cin >> n >> x >> y;
  map<ll, ll> mp;
  for(ll i = 1; i <= n; i++) {
  	for(ll j = i+1; j <= n; j++) {
  		ll t = j - i;
  		t = min(t, abs(x - i) + abs(j - y) + 1);
  		t = min(t, abs(y - i) + abs(j - x) + 1);
  		mp[t]++;
  	}
  }
  for(ll i = 1; i < n; i++)cout << mp[i] << endl;
  return 0;
} //good night.n