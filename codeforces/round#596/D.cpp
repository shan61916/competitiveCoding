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
ll n, kk;
vector<ll> spf(100001, 0);
const ll maxx = 100001;
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
vector<pll> count_primefactors(ll x) {
  ll ct = 0;
  vector<pll> arr;
  while(x!= 1) {
    ll tt = spf[x];
    ct = 0;
    while(x%tt == 0) {
    	x/=tt;
    	ct++;
    }
    if(ct%kk != 0) arr.pb(mp(tt, ct%kk));
  }
  return arr;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  smallest_prime_factor();
  cin >> n >> kk;
  vector<ll> arr(n);
  map<vector<pll>, ll> key;
  ll ans = 0;
  for(ll i = 0; i < n; i++) {
     cin >> arr[i];
     vector<pll> todo = count_primefactors(arr[i]);
     sort(all(todo));
     vector<pll> ntodo;
     for(auto it: todo) {
     	if((kk - it.ss)%kk == 0) continue;
      	ntodo.pb(mp(it.ff, (kk - it.ss)%kk));
       }
     ans+= key[ntodo];
     key[todo]++;
  }
  cout << ans << endl;
  // 
  return 0;
} //good night.