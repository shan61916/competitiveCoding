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
    ll odd = 0, even = 0;
    for(ll i = 0; i < n; i++) {
    	ll tp;
    	cin >> tp;
    	if(tp%2) odd++;
    	else even++;
    }
    if((even == n) or (odd == n and n%2 ==0)) cout << "NO";
    else cout << "YES";
    cout << endl;
  }
  return 0;
} //good night.