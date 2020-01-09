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
  vll a(n+1, 0);
  for(ll i = 1; i <= n; i++) cin >> a[i]; 
  set<ll> given, taken, rem, takenr; 
  for(ll i = 1; i <= n; i++) {
    if(a[i] == 0) {
      continue;
    } else {
      taken.insert(a[i]);
      given.insert(i);
    }
  }
  for(ll i = 1; i <= n; i++) {
    if(given.count(i) == 0) {
      rem.insert(i);
    } if(taken.count(i) == 0) takenr.insert(i);
  }
  ll did = 0;
  for(auto it: rem) {
    bool foo = false;
    if(takenr.count(it) == 1) {
      takenr.erase(it);
      foo = true;
    }
    if(takenr.empty()) {
      a[it] = a[did];
      a[did] = it;
      continue;
    }
    ll tog = *takenr.begin();
    a[it] = tog;
    did = it;
    takenr.erase(tog);
    if(foo) takenr.insert(it);
  }
  for(ll i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
} //good night.
