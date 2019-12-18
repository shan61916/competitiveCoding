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

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  string s;
  cin >> n >> s;
  vector<set<ll>> pref(n); 
  vector<set<ll>> suff(n);
  set<ll> take;
  for(ll i = 0; i < n; i++) {
    for(auto it: take) pref[i].insert(it);
    take.insert(s[i] - '0');
  }
  ll ans[10][10][10];
  for(ll i = 0; i < 10; i++) {
    for(ll j = 0; j < 10; j++) {
      for(ll k = 0; k < 10; k++) {
        ans[i][j][k] = 0;
      }
    }
  }
  take.clear();
  for(ll i = n-1; i >= 0; i--) {
    for(auto it: take) suff[i].insert(it);
    take.insert(s[i] - '0');
  }
  for(ll i = 0; i < n; i++) {
    for(auto it: pref[i]) {
      for(auto et: suff[i]) {
        ans[it][s[i]-'0'][et]++;
      }
    }
  }
  ll res = 0;
  for(ll i = 0; i < 10; i++) {
    for(ll j = 0; j < 10; j++) {
      for(ll k = 0; k < 10; k++) {
        if(ans[i][j][k] > 0) res++;
      }
    }
  }
  cout << res << endl;
} //good night.