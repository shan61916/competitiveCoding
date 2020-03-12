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
  ll k, n;
  cin >> k >> n;
  vll a(n + 1);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i]; 
  }
  ll mx = k - a[n-1] + a[0];
  ll tot = mx;
  for(ll i = 1; i < n; i++) {
  	mx = max(mx, a[i] - a[i-1]);
  	tot+= a[i] - a[i-1];
  }
  cout << tot - mx << endl;
  return 0;
} //good night.