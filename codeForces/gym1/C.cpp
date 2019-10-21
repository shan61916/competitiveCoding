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
  vll tot;
  vector<ll> arr(n);
  for(ll i = 0; i < n; i++) {
     vll given(3);
     for(ll ii = 0; ii < 3; ii++) cin >> given[ii];
     arr[i] = given[0] + given[1] + given[2];
     sort(all(given));
     ll req = given[0] + given[1] + 2;
     tot.pb(req);
  }
  sort(all(tot)) ;
  for(ll i = 0; i < n; i++) {
    auto it = upper_bound(all(tot), arr[i]);
    if(it == tot.end()) {
      cout << max(0ll, n-1) << " ";
    } else {
      ll xo = it - tot.begin();
      cout << max(0ll, xo - 1) << " ";
    }
  }

  return 0;
} //good night.