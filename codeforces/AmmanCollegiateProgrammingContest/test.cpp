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
  ll n, x;
  cin >> x >> n;
  vll a(n+1, 0);
  ll curr = 1;
  ll mod = 1;
  while(x) {
    if(mod == 1) {
      a[curr]++;
      curr++;
    } if(mod == 0) {
      a[curr]++;
      curr--;
    }
    if(curr == 1 or curr == n) mod^=1;
    x--;
  }

  for(ll i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
} //good night.