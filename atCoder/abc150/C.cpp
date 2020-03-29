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
  ll n;
  cin >> n;
  vll a(n), b(n);
  vll c(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  for(ll i = 0; i < n; i++) cin >> b[i];
  for(ll i = 1; i <= n; i++) c[i-1] = i;
  ll x1, x2;  
  ll pass = 1;
  do {
  	if(a == c) x1 = pass;
  	if(c == b) x2 = pass;
  	pass++;
  } while(next_permutation(all(c)));
  cout << abs(x2 - x1) << endl;
  return 0;
} //good night.