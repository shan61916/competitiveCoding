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
  ll n, m, d;
  cin >> n >> m >> d;
  vll a(m); 
  for(ll i = 0; i < m; i++) cin >> a[i];
  stack<ll> st;
  ll curr = n+1;
  for(ll i = m-1; i >= 0; i--) {
  	st.push(curr - a[i]);
  	curr-=a[i];
  }
  vll ans(n+2, 0);
  ll start = 0, now = 0;
  curr = 0;
  while(!st.empty()) {
  	ll from = st.top();
  	st.pop();
  	ll aux = min({n+1, start + d, from});
  	ans[aux]+= ++now;
  	ans[aux + a[curr]]-= now;
  	start = aux + a[curr] - 1;
  	curr++;
  }
  ll ct = 0;
  for(ll i = 1; i <= n; i++) ans[i]+= ans[i-1];
  for(ll i = n; i >= 1; i--) {
  	if(ans[i] == 0) ct++;
  	if(ct >= d) {
  		cout << "NO"; 
  		return 0;
  	} 
  	if(ans[i] != 0) break;
  }
  cout << "YES" << endl;
  for(ll i = 1; i <= n; i++) cout << ans[i] << " ";
  // cout << endl;
  return 0;
} //good night.