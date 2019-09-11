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
ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
  string s;
  cin >> s;
  ll n = s.length(); 
  vll zero(n, 0);
  ll z = 0;
  for(ll i = 0; i < n; i++) {
    zero[i] = z;
    if(s[i] == '0') z++ ;
    else if(s[i] == '1') z = 0;
  }
  ll ans = 0;
  for(ll i = 1; i <= 30; i++) {
    for(ll j = 0; j < n; j++) {
        if(s[j] == '1') {
          ll tot = 0;
           if(j + i - 1 < n) {
              for(ll x = j; x < j+i; x++) {
                if(s[x] == '1') {
                   tot+= fast_exp(2, i - 1 - (x - j)) ;
                }
              }
           }
           if(tot > 0) {
            ll req = tot - i;
            if(zero[j] >= req) {
              ans++ ;
              // cout << tot << endl;
            }
           }
        }
    }
  }
  cout << ans << endl; 
  }
  return 0;
} //good night.