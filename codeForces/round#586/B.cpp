  //shan61916
#include <bits/stdc++.h>
  using namespace std;
// typedef   long long ll;
typedef   long long ll ;
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
  vector<vector<ll>> a(n, vector<ll>(n, 0));
  for(ll i = 0; i < n; i++) {
  	for(ll j = 0; j < n; j++) cin >> a[i][j];
  }
  ll tt = (a[0][1] * a[0][2]) / a[1][2]; 
  ll f =  (ll)(sqrt)(tt);
  cout << f << " ";
  for(ll i = 1; i < n; i++) {
     cout << a[i][0]/f << " ";
  }
  
  return 0;
} //good night.