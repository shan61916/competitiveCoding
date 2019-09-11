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
ll m, d, n;
const ll mod = (ll)(1e9 + 7);
string a, b;

ll dp[2001][2001][2][2];

ll modadd(ll x, ll y) {
	return (x%mod + y%mod)%mod;
}

ll recurse(ll idx, ll prod,ll fir,ll sec){
	 if(idx == n) {
	 	if(prod%m == 0) return 1;
	 	return 0;
	 }
	 ll &ans = dp[idx][prod][fir][sec];
	 if(ans != -1) return ans;
	 ll m1, m0;
	 m1 = m0 = ans = 0;
	 ll start = 0, end = 9;
	 if(fir == 0) start = (ll)(a[idx] - '0');
	 if(sec == 0) end = (ll)(b[idx] - '0');
	 if(idx%2) {
	 	if(d < end) m1 = 1;
	 	if(d > start) m0 = 1;
	 	if(d >= start and d <= end) {
	 		ans = modadd(ans, recurse(idx+1, (prod*10+d)%m, fir|m0, sec|m1));
	 	}
	 	return ans;
	 }
	 for(ll i = start; i <= end; i++) { 
	 	m1 = m0 = 0;
	 	if (i == d) continue;
	 	if(i < end) m1 = 1;
	 	if(i > start) m0 = 1;
	 	ans = modadd(ans, recurse(idx+1, (prod*10 + i)%m, fir|m0, sec|m1)) ;
	 }
	 return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> m >> d;
  cin >> a >> b;
  n = b.length();
  memset(dp, -1, sizeof(dp));
  cout << recurse(0, 0, 0, 0)%mod;
  return 0;
} //good night.