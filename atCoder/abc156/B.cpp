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
  ll n;
  cin >> n;
  vll a(n);

  for(auto &it : a) {cin >> it;} 
  ll res = inf;
  for(ll tot = 1; tot <= 100; tot++) {
  ll ans = 0;
  for(auto it: a) {
  	ans+= (tot - it)*(tot - it);
  }
  res = min(res, ans);
 }
  cout << res << endl;
  return 0;
} //good night.