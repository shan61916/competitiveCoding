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
  vector<ll> z_function(string s) {
    ll n = (ll) s.length();
    vector<ll> z(n);
    for (ll i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])   // here I have used ll, change if required.
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n, m, q;
  cin >> n >> m >> q;
  string s, t;
  cin >> s >> t;
  string ans = t + '@' + s;
  vector<ll> comp = z_function(ans);
  while(q--) {
  	ll l, r;
  	cin >> l >> r;
  	--l, --r;
  	l+= m+1;
  	r+=m+1;
  	ll res = 0;
  	for(ll j = l; j <= r; j++) {
  		// cout << comp[j] << " ";
  		if(comp[j] == m and j + m - 1 <= r) res++;
  	}
  	cout << res << endl;
  }
  return 0;
} //good night.