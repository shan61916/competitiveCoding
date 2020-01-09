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

const ll inf = (ll)(1e17 + 17);
const ll mod = (ll)(1e9 + 7);
vll a;
ll n;
bool can(ll x) {
  for(ll i = 0; i < n; i++) {
    if(i + x > n) continue;
    ll gcd = 0;
    for(ll j = i; j < i + x; j++){gcd = __gcd(a[j], gcd);} 
    if(gcd == 1) return true;
  }
  return false;
}

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n;
  a.resize(n);
  ll gcd = 0; 
  ll ones = 0;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
    gcd = __gcd(a[i], gcd);
    if(a[i] == 1)ones++;
  }
  if(gcd > 1) {cout << -1; return 0;}

  ll low = 1, high = n, mid, ans = -1;
  while(low <= high) {
    mid = (low + high)/2;
    if(can(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  ll res = (ans-1) + (n-1);
  if(ones) {
    res-= (ones-1);
  }
  cout << res << endl;
  return 0;
} //good night.