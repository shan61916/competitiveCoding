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
    string s, t;
    cin >> s >> t;
    vector<pair<ll, ll>> ans;
    vll ct(26, 0);
    for(auto it: s) ct[it - 'a']++;
    for(auto it: s) ct[it - 'a']++;
    bool flag = false;
    for(ll i = 0; i < 26; i++) {
      if(ct[i]%2) flag = true;
    }
    if(flag) {
      cout << "No";
      cout << endl;
      continue;
    }
    for(ll i = 0; i < 2*n; i++) {
      ll ii = i%n;
      if(s[ii] != t[ii]) {
          ll idx = -1;
          bool foo = true;
          for(ll j = ii + 1; j < n; j++) {
            if(s[j] == s[ii]) {
              idx = j;
              foo = false;
              break;
            }
          }
          if(!foo) {
            ans.pb(mp(idx, ii));
            swap(s[idx], t[ii]);
          } else {
            for(ll j = ii + 1; j < n; j++) {
              if(t[j] == s[ii]) {
                 ans.pb(mp(j, j));
                 swap(s[j], t[j]);
                 ans.pb(mp(j, ii));
                 swap(s[j], t[ii]);
                 break;
              }
            }
          }
      }
    }
    if(s == t) {
      cout << "Yes" << endl << ans.size() << endl;
      for(auto it: ans) cout << it.ff + 1 << " " << it.ss + 1 << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
} //good night.