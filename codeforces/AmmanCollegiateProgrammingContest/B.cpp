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
  ll T;
  cin >> T;
  while(T--){
    ll n, x;
    cin >> x >> n;
    if(n == 1) {
      cout << x << endl;
      continue;
    }
    vll a(n+1, 0);
    ll tt = (x/(n-1));
    ll fir = (tt+1)/2;
    ll sec = tt - fir;
    a[1]+=fir, a[2]+=sec, a[n]-=fir;
    for(ll i = 2; i <= n; i++) a[i]+=a[i-1];
    x-= tt*(n-1);
    ll curr = 1, mod = 0;
    tt%2 ? curr = n : curr = 1;
    tt%2 ? mod = 1 : mod = 0;
    while(x) {
      a[curr]++;
      x--;
      mod ? curr-- : curr++;
      if(curr == 1 or curr == n) mod^=1;
    }
    for(ll i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
  }
  return 0;
} //good night.