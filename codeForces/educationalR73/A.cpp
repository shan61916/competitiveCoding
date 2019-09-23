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
vector<ll> a;
ll n;
ll dp[101][3000] ;
ll recurse(ll idx, ll sum) {
	if(sum > 2048) return 0;
	if(idx == n) {
		if(sum == 2048) return 1;
		return 0;
	}
	ll &ans = dp[idx][sum];
	if(ans != -1) return ans;
	ans = 0;
    ans |= recurse(idx+1, sum + a[idx]) ;
    ans |= recurse(idx+1, sum);
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
    cin >> n;
    a.resize(n) ;
    for(ll i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    ll ans = recurse(0, 0);
    ans ? cout << "YES" : cout << "NO";
    cout << endl;
  }
  return 0;
} //good night.