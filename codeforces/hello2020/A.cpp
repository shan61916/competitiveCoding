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
  ll n, m;
  cin >> n >> m;
  vector<string> a(n), b(m);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < m; i++) cin >> b[i];
  ll q;
  cin >> q;
  while(q--) {
    ll x = 0;
    ll x1 = 0, x2 = 0;
    cin >> x;
    --x;
    x1= x%(n);
    x2= x%(m);
    cout << a[x1] + b[x2] << endl;
  }
  return 0;
} //good night.