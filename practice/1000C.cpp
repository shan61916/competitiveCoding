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
  ll n;
  cin >> n;
  map<ll, ll> key;
  for(ll i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    key[x]++;
    key[y+1]--;
  }
  set<pll> st;
  for(auto it: key) {
  	st.insert(mp(it.ff, it.ss)); 
  }
  vll ans(n+1, 0);
  ll curr = 0;
  ll prev = -1;
  for(auto it: st) {
  	ll done = it.ff - prev;
  	ans[curr]+= done;
  	prev = it.ff;
  	curr+= it.ss;
  }
  for_each(ans.begin()+1, ans.end(), [](ll x) {cout << x << " ";});
  return 0;
} //good night.