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
vector<ll> spf(100010, 0) ;; 
const ll maxx = 100010;
vector<vll> ans(maxx, vll(6, 0));
void smallest_prime_factor () {
  for(ll i = 2; i < maxx; i++) {
    spf[i] = i;
  }
  for(ll i = 4; i < maxx; i+=2) spf[i] = 2; // spf of an even number is 2.
  for(ll i = 3; i*i < maxx; i++) {
    if(spf[i] == i) {
      for(ll j = i*i; j < maxx; j+=i) {
        if(spf[j] == j) spf[j] = i;
      }
    }
  }
}
ll count_primefactors(ll x) {
  ll ct = 0;
  while(x!= 1) {
    ll tt = spf[x];
    while(x%tt == 0) x/=tt;
    ct++ ;
  }
  return ct; 
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  smallest_prime_factor();
  for(ll i = 2; i < maxx; i++) {
  	ll tt = count_primefactors(i);
  	ans[i][tt]++;
  }
  for(ll i = 2; i < maxx; i++) {
  	for(ll j = 0; j <= 5; j++) {
  		ans[i][j]+= ans[i-1][j];
  	}
  }
  ll T;
  cin >> T;
  while(T--){
     ll x, y, z;
     cin >> x >> y >> z;
     cout << ans[y][z] - ans[x-1][z] << endl; 
  }

  return 0;
} //good night.