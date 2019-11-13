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
  stack<ll> a;
  vll arr(n); 
  vll arrr(n);
  for(ll i = 0; i < n; i++) cin >> arr[i];
  for(ll j = 0; j < n; j++) {
     cin >> arrr[j];
  }
  reverse(all(arrr));
  for(ll i = 0; i < n; i++) {
  	 a.push(arrr[i]);
  }

  ll ct = 0;
  unordered_map<ll, ll> key;
  for(ll i = 0; i < n; i++) {
  	if(key[arr[i]]) continue;
  	ll xx = arr[i];
  	while(a.size() > 0 and a.top() != xx) {
  		// cout << xx << " " << a.top() << endl;
  		ct++;
  		key[a.top()]++;
  	    a.pop();
  	}
  	a.pop();
  	key[xx]++;
  }
  cout << ct << endl;
  return 0;
} //good night.