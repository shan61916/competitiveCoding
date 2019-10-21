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
    string s;
    cin >> s;
    ll n = s.length();
    ll mx = (ll)(1e17);
    for(ll i = 0; i < n; i++) {
    	ll num = 0;
    	for(ll j = 0; j < n; j++) {
             if(i == j) continue;
             num*=10;
             num+= (ll)(s[j]-'0'); 
    	}
    	mx = min(mx, num);
    }
    cout << mx << endl;
  }
  return 0;
} //good night.