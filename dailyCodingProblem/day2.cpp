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
  int n, m;
  cin >> n >> m;
  ll mn = INT_MAX;
  for(ll i = 0; i < m; i++) {
  	ll x, y;
  	cin >> x >> y;
  	mn = min(mn, y - x + 1);
  }
  for(ll i = 0; i < n; i++) cout << i%mn << " ";
  cout << endl;
  return 0;
} //good night.