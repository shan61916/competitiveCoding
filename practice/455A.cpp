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
ll dp[100010];
ll mx = 0, n;
unordered_map<ll, ll> freq;
ll recurse(ll idx) {
	// cout << idx << endl;
	if(idx > mx) return 0;
	ll &ans = dp[idx];
	if(ans != -1) return ans;
	ans = 0;
	ans = recurse(idx+1);
    ans = max(ans, (freq[idx]*idx) + recurse(idx+2));
    return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif 
  cin >> n;
  freq.clear();
  for(ll i = 0; i < n; i++) {
  	ll tp;
  	cin >> tp;
  	mx = max(mx, tp);
  	freq[tp]++;
  }
  // mx = (ll)(1e5 + 1);
  memset(dp, -1, sizeof(dp));
  cout << recurse(0);

  return 0;
} //good night.