  //shan61916
#include <bits/stdc++.h>
    using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
typedef long long ll;
typedef unsigned long long ull ;
typedef double dll ;

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  vector<ll> ans(n) ;
  ll prev = 0;
  for(ll i = 0; i < n; i++) {
    if(i == 0) {
      ll xx = 0;
      for(ll j = 1; j< n-1; j++) {
         xx+=a[j] ;
      }
      ll tt = 2 ;
      for(ll j = 2; j < n-2; j++) {
        if(j == tt) {
        xx-= 2*a[j]; 
        tt+=2;
        }
      }
      ans[i] = a[0] + a[n-1] - xx;
      prev = ans[i];
      continue;
    }
    ans[i] = 2*((a[i-1] - prev/2));
    prev = ans[i] ;
  }
  for(ll i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
} //good night.
