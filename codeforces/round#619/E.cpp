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
  string s;
  cin >> s;
  vll val(26, -1);
  ll curr = 0;
  string ans = "";
  bool foo = true;
  for(ll i = 0; i < n; i++) {
  	ll oc = 0, ec = 0;
  	for(ll j = 25; j > (ll)(s[i] - 'a'); j--) {
  		if(val[j] == 1) oc++;
  		else if(val[j] == 0) ec++;
  	}
  	curr = 0;
  	if(oc and ec) foo = false;
  	if(oc and ec == 0) curr = 0;
  	else if(oc == 0 and ec) curr = 1;
  	ll tt = (ll)(s[i] - 'a');
  	if(val[tt] == -1) val[tt] = curr;
  	else {
  		if(val[tt] != curr) foo = false;
  	}
  	ans.pb(char(curr + '0'));
  }
  // cout << ans << endl;
  if(foo) cout << "YES" << endl << ans << endl;
  else cout << "NO" << endl;
  return 0;
} //good night.
