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
  vector<ll> a(n);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i];
  }
  sort(all(a)); 
  vector<bool> vis(n, true);
  for(ll i = 0; i < n; i++) {
  	for(ll j = i+1; j < n; j++) {
  		if(vis[i] and vis[j] and a[j]%a[i] == 0 and (a[j]/a[i])%2 == 0) vis[j] = false; 
  	}
  }
  cout << count(all(vis), false);
  cout << endl;
  for(ll i = 0; i < n; i++) {
  	if(!vis[i]) cout << a[i] << endl;
  }

  return 0;
} //good night.