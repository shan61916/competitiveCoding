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
  ll n, p;
  cin >> n >> p;
  dll totprob = 0.00;
  vector<pll> a(n);
  for(ll i = 0; i < n; i++) cin >> a[i].ff >> a[i].ss;
  for(ll i = 0; i < n; i++) {
      ll tot1 = (a[i].ss - a[i].ff + 1);
      ll tot2 = (a[(i+1)%n].ss - a[(i+1)%n].ff + 1);
      ll fprime = (a[i].ss/p) - ((a[i].ff-1)/p);
      ll sprime = (a[(i+1)%n].ss/p) - ((a[(i+1)%n].ff - 1)/p);
      dll prob = (dll)((dll)(fprime*tot2) + (dll)((sprime)*(tot1)) - (dll)(fprime*sprime));
      prob = (dll)(prob)/(dll)(tot1*tot2);
      totprob+= prob;
  }
  cout << fixed << setprecision(6) << (dll)(2000.00)*(totprob) << endl;
  return 0;
} //good night.