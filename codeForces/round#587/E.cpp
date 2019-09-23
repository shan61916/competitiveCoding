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
const ll inf = 10000;
ll countdig(ll n) {
	ll ct = 0;
	while(n) {
      ct++;
      n/=10;
	}
	return ct;
}
ll lastchar(ll x) {
	ll ans = 0;
	while(x)  {
		ans = x%10;
		x/=10;
	}
	return ans;
}
string create(ll x) {
	string res = "";
	ll ct = 1;
	while(1) {
		if((ll)res.length() >= x) break;
        string p = to_string(ct);
        res+=p;
        ct++;
	}
	return res;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  vector<ll> a(inf, 0) ;
  for(ll i = 1; i < inf; i++) {
  	a[i] = a[i-1] + countdig(i);
  }
  for(ll i = 1; i < inf; i++) a[i] += a[i-1];
  ll q;
  cin >> q;
  while(q--) {
  	ll x;
  	cin >> x;
  	auto it = lower_bound(all(a), x) ;
  	ll idx = it - a.begin();
  	// cout << idx << endl;
  	while(a[idx] >= x ) idx--;
  	// cout << idx << endl;
  	ll tt = x - a[idx]; 
    string xo = create(tt); 
    cout << xo[tt-1] << endl;
   }
  return 0;
} //good night.
