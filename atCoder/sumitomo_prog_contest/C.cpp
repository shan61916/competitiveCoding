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
ll arr[] = {100, 101, 102, 103, 104, 105}; 
ll dp[200000][10];
ll todo;
ll can(ll x, ll idx) {
  if(x == todo and idx < 6) return 1;
  if(x > todo or idx >= 6) return 0;
  ll &ans = dp[x][idx];
  if(ans != -1) return ans;
  ans = 0;
  ans = ans|can(x + arr[idx], idx); 
  ans = ans|can(x, idx + 1);
  return ans;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  memset(dp, -1, sizeof(dp));
  cin >> todo;
  cout << can(0, 0);

  return 0;
} //good night.