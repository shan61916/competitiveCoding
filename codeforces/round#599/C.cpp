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
set<ll> factors;
bool isprime(ll x) {
  for(ll i = 2; i*i <= x; i++) {
      if(x%i == 0) return false;
  } 
  return true;
}
void smallest(ll n) {
  for(ll i = 2; i*i <= n; i++) {
    if(n%i == 0) {
      if(n/i == i) factors.insert(i);
      else {
        factors.insert(i);
        factors.insert(n/i);
      }
    } 
  }
  return;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  if(isprime(n) or n == 1) {
    cout << n << endl;
  } else {
    smallest(n);
    vll arr;
    for(auto it: factors) arr.pb(it);
    ll ans = 0;
    for(ll i = 0; i < (ll)arr.size(); i++) {
       ans= __gcd(ans, arr[i]);
    }
    cout << ans << endl;
  }
  return 0;
} //good night.