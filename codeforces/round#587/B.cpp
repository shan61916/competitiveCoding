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
  vector<pair<ll, ll>> a(n);
  for(ll i = 0; i < n; i++) {
  	cin >> a[i].ff;
  	a[i].ss = i+1;
  }
  sort(all(a), greater<pair<ll, ll>>());
  ll cost = 0;
  for(ll i = 0; i < n; i++) {
  	cost+= a[i].ff * i;
  }
  cost+=n;
  cout << cost << endl;
  for(auto it: a) cout << it.ss << " " ;
  return 0;
} //good night.