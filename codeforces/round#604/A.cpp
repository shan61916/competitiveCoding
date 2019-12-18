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
  ll T;
  cin >> T;
  while(T--) {
    string s;
    cin >> s;
    ll n = s.length();
    bool foo = true;
    for(ll i = 0; i < n; i++) {
      char prev = 'z';
      if(i-1 >= 0 ) prev = s[i-1];
      char next = 'z';
      if(i+1 < n and s[i+1] != '?') next = s[i+1];
      if(s[i] == '?') {
        if(prev == 'z') {
          if(next == 'a') s[i] = 'b';
          else s[i] = 'a';
        } else if(prev == 'a') {
          if(next == 'c') s[i] = 'b';
          else s[i] = 'c';
        } else if(prev == 'b') {
          if(next == 'c') s[i] = 'a';
          else s[i] = 'c';
        } else if(prev == 'c') {
          if(next == 'a') s[i] = 'b';
          else s[i] = 'a';
        } 
      }
      if(i-1 >= 0 and s[i] == s[i-1]) {
        foo = false;
        break;
      }
    }
    // cout << s << endl;
    foo ? cout << s << endl : cout << -1 << endl;
  }
  return 0;
} //good night.