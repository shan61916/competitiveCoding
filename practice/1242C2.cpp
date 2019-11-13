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
// const ll MOD  = (ll)(1e9+7);
ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   ll n;
   cin >> n;
   string s = "";
   bool foo = false;
   ll xo = 0;
   ll p = n;
   while(n) {
       ll x = n%3;
       n/=3;
       s.push_back((char)(x + '0'));
       if(x == 2) xo++;
   }
   ll idx = -1, foo2 = -1, foo3 = -1; 
   reverse(all(s));
   for(ll i = 0; i < (ll) s.length(); i++) {
     if(foo2 != -1) s[i] = '0';
     else
   	 if(s[i] == '0') {
   	 	 foo = true;
   	 	 idx = i;
   	 } else if(s[i] == '2') {
   	 	if(foo) {
          s[idx] = '1';
          s[i] = '0';
          foo2 = 1; 
   	 	} else {
   	 		foo3 = 1;
   	 		break;
   	 	}
   	 }
   }
   if(xo == 0) {
   	cout << p << endl;
   	continue;
   }
   if(foo3 != -1) {
   	cout << fast_exp(3, (ll)s.length()) << endl;
   	continue;
   } else {
   	for(ll i = idx+1; i < (ll)s.length(); i++) s[i] = '0';
   	ll ans = 0;
    reverse(all(s));
    for(ll i = 0; i < (ll)s.length(); i++) {
    	if(s[i] == '1') {
    		ans+= fast_exp(3, i);
    	}
    }
    cout << ans << endl;
   }
  }
  return 0;
} //good night.