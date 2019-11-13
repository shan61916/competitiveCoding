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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll n;
  cin >> n;
  vll a(n);
  for(auto &x : a) cin >> x;
  vll ans(n+1, 0); 
  unordered_map<ll, ll> key; 
  vector<bool> visited(n+1, false);
  for(ll i = n-1; i >= 0; i--) {
     if(a[i] < 0) {
     	ans[i] = ans[i+1] + 1;
     	if(visited[abs(a[i])]) {
     		ans[i] = min(ans[i], key[abs(a[i])] - i);
     	}
     } else {
     	ans[i] = ans[i+1] + 1;
     	visited[a[i]] = true;
     	key[a[i]] = i;
     }
  }
  for(ll i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
} //good night.