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
ll n, m, k;

int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> m >> k;
  unordered_map<ll, ll> rc, cc; 
  unordered_map<ll, ll> rmx, cmx;
  for(ll i = 0; i < k; i++) {
  	ll x, y;
  	cin >> x >> y;
  	rc[x]++;
  	cc[y]++;
  	rmx[x] = max(rmx[x], y);
  	cmx[y] = max(cmx[y], x);
  }
  ll tohave = -1;
  for(ll i = 1; i <= n; i++) {
     if(rc[x] > tohave and rc[x] > 0) {
        tohave = rc[x];
     }
     	
  }
  return 0;
} //good night.