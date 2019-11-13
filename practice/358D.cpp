  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   long long ll;
typedef   unsigned long long ull ;
typedef   long double dll ;

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
  ll ct = 1;
  ll sum = 0; 
  vector<pll> arr(200002, mp(0, 0));
  for(ll i = 0; i < n; i++) {
    ll tp;
    cin >> tp;
    if(tp == 1) {
      ll x, y;
      cin >> x >> y;
      sum+= x*y;
      arr[x].ss+= y;
    } else if(tp == 2) {
      ll k;
      cin >> k;
      arr[++ct].ff = k; 
      sum+=k;
    } else if(tp == 3){
      arr[ct-1].ss+= arr[ct].ss;
      sum = sum - arr[ct].ff - arr[ct].ss;
      arr[ct].ss = 0;
      arr[ct].ff = 0;
      ct--;
    }
    cout << fixed << setprecision(20) << (dll)(sum)/(dll)(ct) << endl;
  }
  return 0;
} //good night.