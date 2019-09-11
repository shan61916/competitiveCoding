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
ll n, k;
ll dp[1001][1001][2];
ll recurse(ll idx, ll sum, ll prev) {
	if(idx == n) {
		if(sum == k) return 1;
		return 0;
	}
	ll &ans = dp[idx][sum][prev];
	if(ans != -1) return ans;
    ans = 0;
    if(prev == 1) {
    	ans+= recurse(idx+1, sum+1, 1);
    	ans+= recurse(idx+1, sum, 0);
    } else if (prev == 0) {
    	ans+= recurse(idx+1, sum, 0);
    	ans+= recurse(idx+1, sum, 1);
    }
    return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll T;
  cin >> T;
  while(T--){
   ll tt;
   cin >> tt;
   cin >> n >> k;
   memset(dp, -1, sizeof(dp));
   ll ans = recurse(0, 0, 0);
   cout << tt << " " << ans << endl;
  }
  return 0;
} //good night.