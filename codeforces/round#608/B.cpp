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
char flip(char c) {
  if(c == 'W') return 'B';
  return 'W';
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  string s;
  cin >> s;
  string p; 
  p = s;
  vll res;
  for(ll i = 0; i < n - 1; i++) {
    if(s[i] == 'W') continue;
    if(s[i] == 'B') {
      res.pb(i+1);
      s[i] = 'W';
      s[i+1] = flip(s[i+1]);
    }
  }
  for(ll i = 0; i < n - 1; i++) {
    if(s[i] == 'W') continue;
    if(s[i] == 'B') {
      res.pb(i+1);
      s[i] = 'W';
      s[i+1] = flip(s[i+1]);
    }
  }
  for(ll i = 0; i < n - 1; i++) {
    if(s[i] == 'W') continue;
    if(s[i] == 'B') {
      res.pb(i+1);
      s[i] = 'W';
      s[i+1] = flip(s[i+1]);
    }
  }
  ll ct = 0;
  for(ll i = 0; i < n; i++) {
    if(s[i] == 'W')ct++;
  }
  if(ct == n) {
    cout << res.size();
    // cout << "sdsd" << endl;
    cout << endl;
    
    for(auto it: res) cout << it << " ";
    return 0;
  } 
  res.clear();
  for(ll i = 0; i < n - 1; i++) {
    if(s[i] == 'B') continue;
    if(s[i] == 'W') {
      res.pb(i+1);
      s[i] = 'B';
      s[i+1] = flip(s[i+1]);
    }
  }
  for(ll i = 0; i < n - 1; i++) {
    if(s[i] == 'B') continue;
    if(s[i] == 'W') {
      res.pb(i+1);
      s[i] = 'B';
      s[i+1] = flip(s[i+1]);
    }
  }
  for(ll i = 0; i < n - 1; i++) {
  if(s[i] == 'B') continue;
    if(s[i] == 'W') {
      res.pb(i+1);
      s[i] = 'B';
      s[i+1] = flip(s[i+1]);
    }
  }
  ct = 0;
  for(ll i = 0; i < n; i++) {
    if(s[i] == 'B')ct++;
  }
  if(ct == n) {
    cout << res.size();
    cout << endl;
    for(auto it: res) cout << it << " ";
    return 0;
  } 
  cout << -1 << endl;
  return 0;
} //good night.