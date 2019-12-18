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


int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  vll ans ;
  if(a >= b and b >= c and b >= d) {
    ans.pb(0);
    a--;
  } 
  else if(b >= a and b >= c and c >= d) {
    ans.pb(1);
    b--;
  } 
  else if(c >= b and b >= a and c >= d) {
    ans.pb(2);
    c--;
  } else {
    ans.pb(3);
    d--;
  }
  bool foo = true;
  ll n = a + b + c + d;
  for(ll i = 1; i <= n; i++) {
    ll xx = ans[i-1];
    if(xx == 1) {
      if(a < c and a > 0) {
        ans.pb(0);
        a--;
      } else if(c > 0){
        ans.pb(2);
        c--;
      }
    }
    else if(xx == 2) {
      if(b < d and b > 0) {
        ans.pb(1);
        b--;
      } else if(d > 0){
        ans.pb(3);
        d--;
      } else foo = false;
    } else if(xx == 3) {
      if(c > 0) {
        ans.pb(2);
        c--;
    } else foo = false; } else if(xx == 0) {
      if(b > 0) {
        ans.pb(1);
        b--;
      } else foo = false;
    }
  }
  if(a > 0 or b > 0 or c > 0 or d > 0) foo = false;
  if(!foo) {
    cout << "NO";
    return 0;
  } else {
    cout << "YES" << endl;
    for(auto it: ans) cout << it << " ";
  }
  return 0;
} //good night.