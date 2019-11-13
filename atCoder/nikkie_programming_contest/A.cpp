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
  set<pair<ll, ll>> st;
  ll n;
  cin >> n;
  ll ans = 0;
  for(ll i = 1; i < n; i++){
     if(i == n-i or i > n-i) break;
     ans++;
  }
  cout << ans << endl;
  return 0;

} //good night.