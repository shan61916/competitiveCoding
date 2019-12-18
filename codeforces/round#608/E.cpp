  //shan61916
#include <bits/stdc++.h>
  using namespace std;
typedef   unsigned long long ll;
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
ll n, k;
set<ll> st;
ll recurse(ll idx) {
   if(idx > n) return 0;
   if(idx == n) return 1;
   if(idx%2) {
     ll ans = 1;
     if(st.find(idx+ 1) == st.end()){
      st.insert(idx + 1);
      ans+= recurse(idx + 1);
      return ans;
   }
  }
   ll ans = 1;
   if(st.find(idx + 1) == st.end()){
     st.insert(idx + 1);
     ans+= recurse(idx + 1);
   }
   if(st.find(idx * 2) == st.end()){
     st.insert(idx * 2);
     ans+= recurse(idx * 2);
   }
   return ans;
}
bool can(ll x) {
  ll gv = 2*x-1;
  st.clear();
  ll ct = recurse(gv); 
  return (ct >= k);
}
bool can2(ll x) {
  ll gv = 2*x;
  st.clear();
  ll ct = recurse(gv);  
  return (ct >= k);
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  cin >> n >> k;
  if(n == k) {
    cout << 1;
    return 0;
  }
  ll even = n/2;
  ll odd = n - even;
  ll low = 1, high = odd, ans = 0, mid = 0;
  cout << recurse(2);
  // while(low < high) {
  //   mid = (low + high)/2;
  //   tot++;
  //   if(tot == 1000) break;
  //   if(can(mid)) {
  //     ans = 2 * mid - 1;
  //     low = mid + 1;
  //   } else high = mid - 1;
  // }
  // for(auto it: tt) cout << it << " ";
  // ll ans2;
  // low = 1, high = even, ans2 = 0, mid = 0;
  // while(low <  high) {
  //   mid = (low + high)/2;
  //   if(can2(mid)) {
  //     ans2 = 2 * mid;
  //     low = mid + 1 ;
  //   } else high = mid - 1;
  // }
  // // can2(2); 
  // cout << max(ans, ans2) << endl;
  return 0;
} //good night.