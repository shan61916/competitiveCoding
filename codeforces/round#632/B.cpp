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
    ll n;
    cin >> n;
    vll a(n), b(n);
    bool foo = true;
    for(ll i = 0; i < n; i++) cin >> a[i];
    for(ll i = 0; i < n; i++) cin >> b[i];
    vector<vll> pref(n, vll(3, 0));
    ll z = 0, o = 0, m = 0;
    for(ll i = 0; i < n; i++) {
    	if(z)pref[i][1] = 1;
    	if(m) pref[i][0] = 1;
    	if(o) pref[i][2] = 1;
    	if(a[i] == 1) o++;
    	else if(a[i] == 0) z++;
    	else m++;
    }
    for(ll i = n - 1; i >= 0; i--) {
    	ll need = b[i] - a[i];
    	if(need < 0) if (!pref[i][0]) foo = false;
    	if(need > 0) if (!pref[i][2]) foo = false;
    	if(need == 0) continue;
    }
    foo ? cout << "YES" : cout << "NO";
    cout << endl;
  }
  return 0;
} //good night.