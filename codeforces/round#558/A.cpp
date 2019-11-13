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
  if(m == 0) {
    cout << 1;
    return 0;
   }
  vector<bool> arr(n, true);
  ll x = 0, ans = 0;
  while(m) {
    while(!arr[x]){
      x++;
      x%=n;
    }
    arr[x] = false;
    x+=2;
    x%=n;
    m--;
  }
  for(ll i = 0; i < n-1; i++) {
     if(!arr[i] and arr[i+1]) ans++;
  }
  if(arr[0] and arr[n-1] and ans >= 1) ans--;
  cout << ans << endl;
  return 0;
} //good night.