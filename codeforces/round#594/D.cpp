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
ll n;
ll total(string s) {
    ll o = 0, cl = 0;
    for(ll i = 0; i < n; i++) {
    	if(s[i] == '(') {
    		o++;
    	} else {
    		if(o)o--;
    		else cl++;
    	}
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
    	if(s[i] == '(') {
    	   o++;
    	   cl++;
    	} else {
    		if(o) {
    			o--;
    			cl--;
    		}
    	}
    	// cout << o << " " << cl << endl;
    	if(o == 0 and cl == 0) ans++;
    }
    return ans ;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  string s;
  cin >> s;
  // cout << calc(s) << endl;
  string p;
  ll ans = 0, l = 1, r = 1;
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) {
  	   p = s;
       swap(p[i], p[j]);
       ll xx = total(p) ;
       if(xx > ans) {
           ans = xx;
           l = i+1;
           r = j+1;
       }
  	}
  }
  cout << ans << " " << endl << l << " " << r << endl;
  return 0;
} //good night.