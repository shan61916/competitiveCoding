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
  vector<pll> a(n);
  for(auto &it: a) cin >> it.ff >> it.ss;
  ll ans = -1;
  for(ll i = 1; i <= n; i++) {
    ll ct = 0;
    for(auto j: a) {
       if(i >= j.ff and i <= j.ss) ct++;
    }
    if(i == ct) ans = max(ans, ct);
  }
  cout << ans << endl;
  return 0;
} //good night.