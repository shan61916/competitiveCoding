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
  ll n, m;
  cin >> n >> m;
  vll a;
  unordered_map<ll,ll>  key;
  for(ll i = 0; i < n; i++) a.pb(1); 
  for(ll j = 0; j < m; j++) a.pb(0);
  sort(all(a)); 
  do{
     ll ct = 0;
     for(ll i = 0; i < n+m; i++) {
      if(a[i] == 1) ct++;
      if(ct == n) {
         key[i+1]++;
         break;
      }
     }
    } while(next_permutation(all(a)));
    for(ll i = 1; i <= n+m; i++) cout << key[i] << " ";
  return 0;
} //good night.