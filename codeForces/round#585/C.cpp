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
  string a ,b;
  cin >> a >> b;
  ll xx = count(all(a), 'a') + count(all(b), 'a'); 
  ll yy = count(all(a), 'b') + count(all(b),'b') ;
  if(xx%2 or yy%2) {
  	cout << -1;
  	return 0;
  }
  queue<ll> q1, q2; 
  for(ll i = 0; i < n; i++) {
  	if(a[i] == 'a' and b[i] == 'b') {
  		q1.push(i);
  	} else if(a[i] == 'b' and b[i] == 'a') q2.push(i);
  }
  ll ct = 0;
  vector<pll> ans;
  while(q1.size() > 1) {
  	ll x = q1.front();
  	q1.pop();
  	ll y = q1.front();
  	q1.pop();
  	ct++;
  	ans.push_back(mp(x, y));
  } 
  while(q2.size() > 1) {
  	ll x = q2.front();
  	q2.pop();
  	ll y = q2.front();
  	q2.pop();
  	ct++;
  	ans.push_back(mp(x, y));
  }
  if(q1.size() == 1 and q2.size() == 1) {
  	ll x = q1.front();
  	ll y = q2.front();
  	ct+=2;
  	ans.pb(mp(x, x));
  	ans.pb(mp(x, y));
  }
  cout << ct << endl;
  for(auto it: ans) cout << it.ff+1 << " " << it.ss+1 << endl;
  return 0;
} //good night.