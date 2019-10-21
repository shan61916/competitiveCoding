  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   int ll;
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
string s1, s2;
int dp[1001][1001];

ll lcs(ll i, ll j) {
	if(i < 0 or j < 0) return 0;
	ll &ans = dp[i][j];
	if(ans != -1) return ans;
	ans = 0;
	if(s1[i] == s2[j]) {
		ans = 1 + lcs(i-1, j-1);
	}
	else {
		ans = lcs(i-1, j);
		ans = max(ans, lcs(i, j-1));
	}
	return ans;
}

string ans;
void scs(ll i, ll j) {
	// cout << i << " " << j << endl;
	if(i < 0 or j < 0) {
		if(i < 0) {
			while(j >= 0) {
				ans+= s2[j];
				j--;
			}
		}
		if(j < 0) {
			while(i >= 0) {
				ans+= s1[i];
				i--;
			}
		}
		return ;
	}
  int mx = lcs(i, j);
  if(s1[i] == s2[j]) {
  	if(mx == 1 + lcs(i-1, j-1)) {
       ans+= s1[i];
       scs(i-1, j-1);
       return;
  	}
  }
  if(mx == lcs(i-1, j)) {
  	ans+= s1[i];
  	scs(i-1, j);
  	return ;
  }
  if(mx == lcs(i, j-1)) {
  	ans+= s2[j];
  	scs(i, j-1);
  	return;
  }
  return ;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> s1 >> s2;
  ll st = (ll)s1.length() - 1;
  ll en = (ll)s2.length() - 1;
  memset(dp, -1, sizeof(dp));
  ll x = lcs(st, en);
  cout << x << endl;
  ans = "";
  scs(st, en);
  reverse(all(ans));
  cout << ans << endl;
  return 0;
} //good night.