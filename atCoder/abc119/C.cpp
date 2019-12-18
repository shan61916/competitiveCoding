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
  string s;
  cin >> s;
  ll n = s.length();
  ll x1 = 0;
  ll x2 = 0;
  for(ll i = 0; i < n; i++) {
    if(i%2) {
      if(s[i] == '1') x2++;
      else x1++;
    } else {
      if(s[i] == '1') x1++;
      else x2++;
    }
  }
  cout << min(x1, x2) << endl;
  return 0;
} //good night.