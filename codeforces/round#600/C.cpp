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
  ll n, m;
  cin >> n >> m;
  vll a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  sort(all(a), greater<ll>());
  vll suff(n, 0);
  vll totsuf(m, 0);
  for(ll i = 0; i < n; i++) {
    totsuf[i%m]+= a[i];
  }
  vll ans;
  ll tot = 0, d =0;
  for(ll i = 0; i < n; i++) {
    if(i%m == 0) d++;
    tot+= a[i]*d;
  }
  ans.pb(tot);
  for(ll i = 1; i < n; i++) {
    tot-= totsuf[(i - 1 + m)%m]; 
    totsuf[(i - 1 + m)%m]-= a[i-1];
    ans.pb(tot);
  } 
  reverse(all(ans));
  for(auto it : ans) cout << it << " ";
  return 0;
} //good night.