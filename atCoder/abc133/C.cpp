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
  ll l, r;
  cin >> l >> r;
   ll mn = (ll)1e19;
    for(ll i = l ; i < r; i++) {
      for(ll j = i+1; j <= r; j++) {
        if(((i%2019 * j%2019)%2019)  <= mn) mn = ((i%2019 * j%2019)%2019) ;
        if(mn == 0) {
          cout << 0;
          return 0;
        }
      }
   }
    cout << mn%2019;
} //good night.
