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
  vll a(200010, 0);
  ll xx = -1;
  for(ll i = 0; i < n; i++) {
    ll tp;
    cin >> tp;
    a[tp+1]--;
    a[0]++;
    xx = max(xx, tp);
  }
  for(ll i = 1; i <= xx; i++) a[i]+= a[i-1];
  ll ct = 0; 
  ll s = 0;
  for(ll i = xx; i >= 0; i--) {
    if(a[i] == n) break;
    if(s + a[i] <= k) {
      s+= a[i];
      continue;
    } else {
      ct++;
      s = a[i];
    }
  }
  if(s > 0) ct++;
  cout << ct << endl;
  return 0;
} //good night. 