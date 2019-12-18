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
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  ll mx = f * min({b, c, d});
  for(ll i = 1; i <= a; i++) {
    ll mn = min(i, d);
    ll remb = d - mn;
    ll t2 = min({remb, c, b});
    ll cost = mn*e + t2*f;
    mx = max(mx, cost);
  }
  cout << mx << endl;
  return 0;
} //good night.