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
  ll b, g, n;
  cin >> b >> g >> n;
  ll start = min(b, n), end = (n - start); 
  ll todo = min(g, n) ; 
  ll ans = 1;
  while(end != todo) {
   ans++;
   start--;
   end++;
  }
  cout << ans << endl;
  return 0;
} //good night.