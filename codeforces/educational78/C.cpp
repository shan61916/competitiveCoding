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
  ll T;
  cin >> T;
  while(T--) {
    map<pll, ll> key; 
    ll n;
    cin >> n;
    vll arr(n), arr2(n);
    ll o1 = 0, o2 = 0, t1 = 0, t2 = 0;
    for(ll i = 0; i < n; i++) {
      cin >> arr[i];
      if(arr[i] == 1) o1++;
      else t1++;
    } 
    for(ll i = 0; i < n; i++) {
      cin >> arr2[i];
      if(arr2[i] == 1) o2++;
      else t2++;
    }
    reverse(all(arr));
    ll o = 0, t = 0;
    ll orem = o1 - o, trem = t1 - t;
    ll x1 = orem - min(orem, trem);
    ll x2 = trem - min(orem, trem);
    if(key.find(mp(x1, x2)) == key.end()) key[mp(x1, x2)] = 0;
    for(ll i = 0; i < n; i++) {
      if(arr2[i] == 1) o++;
      else t++;
      orem = o1 - o, trem = t1 - t;
      x1 = orem - min(orem, trem);
      x2 = trem - min(orem, trem);
      if(key.find(mp(x1, x2)) == key.end()) key[mp(x1, x2)] = i+1;
    }
    o = 0, t = 0;
    ll ans = 2*n;
    if(o1 + o2 == t1 + t2) {
      cout << 0 << endl;
      continue;
    }
    orem = o2 - o, trem = t2 - t;
    x1 = orem - min(orem, trem);
    x2 = trem - min(orem, trem);
    if(key.find(mp(x2, x1)) != key.end()) ans = min(ans, key[mp(x2, x1)]);
    for(ll i = 0; i < n; i++) {
      if(arr[i] == 1) o++;
      else t++;
      orem = o2 - o, trem = t2 - t;
      x1 = orem - min(orem, trem);
      x2 = trem - min(orem, trem);
      if(key.find(mp(x2, x1)) != key.end()) ans = min(ans, i+1 + key[mp(x2, x1)]);
    }
    cout << ans << endl;

  }
  return 0;
} //good night.