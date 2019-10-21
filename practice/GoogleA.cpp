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
const int inf = (int)(1e8);
int n, limit;
int dp[10001][1001][2];
int arr[10001];

int recurse(int idx, int sum, int prev) {
	if(sum > limit) return -inf;
	if(idx == n) {
		if(sum <= limit) return sum;
		else return -inf;
	}
    int &ans = dp[idx][sum][prev];
    if(ans != -1) return ans;
    ans = 0;
    ans = recurse(idx+1, sum, 0);
    if(!prev) ans = max(ans, recurse(idx+1, sum + arr[idx], 1));
    return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> limit >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  memset(dp, -1, sizeof(dp));
  int ans = recurse(0, 0, 0);
  cout << ans << endl;
  return 0;
} 