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
  ll ans = 0;
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<ll> a(26, 0);
  for(ll i = 0; i < k; i++) {
    char tp;
    cin >> tp;
    a[tp - 'a'] = 1;
  }
  for(ll i = 0; i < n; i++) {
    if(a[s[i] -'a'] == 0) continue;
    ll curr = 0;
    ll j = i;
    while(j < n and a[s[j]-'a'] == 1) {
      curr++;
      j++;
    }
    // cout << curr << endl;
    ans+= (curr)*(curr+1)/2;
    i = j-1;
  }
  cout << ans << endl;
  return 0;
} //good night.