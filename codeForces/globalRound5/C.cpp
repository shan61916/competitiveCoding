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
ll a[100010], b[100010], c[100010]; 
bool comp(const ll &x, const ll &y) {
    if(a[x] == a[y]) {
        if(b[x] == b[y]) {
            return c[x] < c[y];
        }
        return b[x] < b[y];
    }
    return a[x] < a[y];
} 

int main(){
 IOS
// #ifdef SHAN
//     freopen("input.txt" , "r" , stdin);  
// #endif
  ll n;
  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<ll> arr;
  for(ll i = 0; i < n; i++) arr.pb(i);
  sort(all(arr), comp) ;
  for(ll i = 0; i < n; i+=2) cout << arr[i] + 1 << " " << arr[i+1] + 1 << endl; 
  return 0;
} //good night.