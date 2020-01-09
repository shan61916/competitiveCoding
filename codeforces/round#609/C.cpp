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
ll val, n, k;
string s, pp;
bool islarge(string a) {
  for(ll i = 0; i < n; i++) {
    if(pp[i] > a[i]) return false;
  }
  return true;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> k;
  cin >> s; 
  cout << n << endl;
  pp = s;
  string a;
  ll mn = n;
  for(ll i = k; i < n; i++) {
    if(s[i%k] < s[i]) mn = min(mn, i%k);
  }
  bool foo = false;

  for(ll i = 0; i < n; i++) a.pb(s[i%k]);
  for(ll i = k-1; i >= 0; i--) {
    if((mn != n and mn >= i+k) or foo) {
      if(s[i] == '9') {
        foo = true;
        continue;
      } else {
        s[i] = (char)((ll)(s[i]-'0' + 1) + '0');
        break;
      }
    } else {
      s[i] = '0';
    }
  }
  for(ll i = 0; i < n; i++) s[i] = s[i%k];
  if(islarge(a)) {
    cout << a << endl;
  } else {
    cout << s << endl;
  }
  return 0;
} //good night.