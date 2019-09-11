  //shan61916
#include <bits/stdc++.h>
    using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n" 
typedef long long ll;
typedef unsigned long long ull ;
typedef double dll ;
ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}
bool perf(ll x) {
  ll xy = (ll)(sqrt(x)) ;
  return ((xy*xy) == x);
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, d;
  cin >> n >> d;
  vector< vector<ll>> a(n) ;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < d; j++) {
      ll tp ;
      cin >> tp;
      a[i].push_back(tp);
    }
  }
  ll xx = 0 ;
  for(ll i = 0; i < n; i++) {
    for(ll j = i+1; j < n; j++) {
       ll tt = 0;
       for(ll k = 0; k < d; k++) {
        tt+= fast_exp(abs(a[i][k] - a[j][k]), 2) ;
       }
       if(perf(tt)) xx++;
    }
  }
  cout << xx ;
  return 0;
} //good night.
