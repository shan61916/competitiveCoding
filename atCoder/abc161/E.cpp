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
vll res;
string s, p;
ll n, k, c;
ll dp[200020], dp2[200020];

ll rec1(ll idx) {
	if(idx >= n) return 0;
	ll &ans = dp[idx];
	if(ans != -1) return ans;
	ans = 0;
	if(s[idx] == 'o') ans = 1 + rec1(idx + c + 1);
	ans = max(ans, rec1(idx + 1));
	return ans;
}

ll rec2(ll idx) {
	if(idx >= n) return 0;
	ll &ans = dp2[idx];
	if(ans != -1) return ans;
	ans = 0;
	if(p[idx] == 'o') ans = 1 + rec2(idx + c + 1);
	ans = max(ans, rec2(idx + 1));
	return ans;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> k >> c;
  cin >> s;
  reverse(all(s));
  p = s;
  reverse(all(s));
  memset(dp, -1, sizeof dp);
  memset(dp2, -1, sizeof dp2);
  rec1(0);
  rec2(0);
  for(ll i = 0; i < n; i++) {
  	if(s[i] == 'x') continue;
  	ll curr = 0;
  	ll ii = n - 1 - i;
  	curr = rec1(i + 1);
  	curr+= rec2(ii + 1);
  	// cout << rec1(i + 1) << " " << rec2(ii + 1) << endl;
  	if(curr < k)  res.pb(i + 1);
  }
  for(auto it: res) cout << it << endl;
  return 0;
} //good night.	
