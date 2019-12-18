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
  map<ll, ll> key;
  ll n;
  cin >> n;
  vll a(n);
  for(ll i = 0; i < n; i++) cin >> a[i];
  ll tot = 0, ct = 0, sz = 0;
  bool foo = true;
  map<ll, ll> st;
  vll ans;
  for(ll i = 0; i < n; i++) {
    if(a[i] > 0) {
      if(st[a[i]] == 0) {
      key[a[i]]++;
      sz++;
      st[a[i]] = 1;}
      else {
        foo = false;
        break;
      }
    } 
    else if(a[i] < 0) {
      if(key[0 - a[i]] != 1) {
        foo = false;
        break;
      } else {
        key[0 - a[i]]--;
        sz--;
      }
    }
    tot++;
    if(sz == 0) {
      ct++;
      ans.pb(tot);
      tot = 0;
      st.clear();
    }
  }
  if(sz != 0) foo = false;
  if(foo) {
    cout << ct << endl;
    for(auto it: ans) cout << it << " ";
  } else {
    cout << -1 << endl;
  }
  return 0;
} //good night.