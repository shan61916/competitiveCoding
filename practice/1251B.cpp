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
  ll T;
  cin >> T;
  while(T--){
    ll n;
    cin >> n;
    vector<string> arr(n);
    ll o = 0, z = 0;
    vll len;
    for(auto &x: arr) {
       cin >> x;
       for(auto dig : x) {
        if(dig == '1') o++;
        else z++;
       }
       len.pb(x.length());
    }
    ll ans = 0;
    sort(all(len));
    for(ll i = 0; i < n; i++) {
       if(len[i]%2) {
         if(o%2) {
          o--;
         } else if(z%2){
          z--;
         } else if(o) o--;
         else z--;

         len[i]--;
       }
       if(o >= len[i]) {
         ans++;
         o-= len[i];
         continue;
       } else if(z >= len[i]) {
        ans++;
        z-=len[i];
        continue;
       }
       if(z%2 == 0 and o%2 == 0 and z + o >= len[i]) {
        ans++;
        ll tt = min(o, len[i]);
        o-=tt;
        len[i]-=tt;
        z-= len[i];
       }
    }
    cout << ans << endl;
  }
  return 0;
} //good night.