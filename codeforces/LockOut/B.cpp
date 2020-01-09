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
  cin >> n;
  vector<dll> a(n);
  vll b(n);
  ll tot = 0;
  for(ll i = 0; i < n; i++) {
   dll p;
   cin >> p;
   a[i] = p;
   ll xx = (ll)(floor)(p);
   b[i] = xx;
   tot+= xx;
  }
  ll diff = tot;
  for(ll i = 0; i < n; i++) {
    if(b[i] == (ll)(ceil)(a[i])) continue;  
    if(diff < 0) {
      diff++;
      b[i]++;
    }
  }
  for(ll i = 0; i < n; i++) cout << b[i] << endl;
  return 0;
} //good night.