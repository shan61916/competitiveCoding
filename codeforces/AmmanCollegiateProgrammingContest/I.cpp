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
  ll T;
  cin >> T;
  while(T--){
  ll x, n;
  cin >> x >> n;
  if(n > x or n == 0) {
    cout << -1 << endl;
    continue;
  }
  vll a(n, 0);
  ll avg = x/n;
  x = x - (n*avg);
  // cout << x << endl;
  for(ll i = 0; i < n; i++) a[i] = avg;
  ll ct = 0;
  while(x > 0) {
    a[ct]++;
    ct++;
    x--;
    if(ct >= n) ct = 0;
  }
  sort(all(a));
  for(auto it: a) cout << it << " ";
 }
  return 0;
} //good night.