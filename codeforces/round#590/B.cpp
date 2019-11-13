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
  ll n, k;
  cin >> n >> k;
  ll sz = 0;
  set<ll> present ;
  queue<ll> q;
  ll rem, x;
  for(ll i = 0; i < n; i++) {
  	cin >> x;
  	if(present.count(x)) continue;
  	else {
  		if(sz == k) {
  		rem = q.front();
  		q.pop();
  		present.erase(rem); 
  		sz--;
  	    } 
  		q.push(x);
  		present.insert(x);
  		sz++;
  	}
  }
  vector<ll> ans; 
  while(!q.empty()) {
  	rem = q.front();
  	q.pop();
  	ans.pb(rem);
  }
  reverse(all(ans));
  cout << ans.size() << endl;
  for(auto it: ans ) cout << it << " ";
  return 0;
} //good night.