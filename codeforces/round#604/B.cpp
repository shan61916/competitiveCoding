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
   ll n;
   cin >> n;
   vector<ll> a(n);
   vll idx(n + 1); 
   set<ll> st;
   for(ll i = 0; i < n; i++) {
     cin >> a[i];
     idx[a[i]] = i + 1;
   }
   st.insert(idx[1]); 
   ll prev = 1;
   string ans = "1"; 
   for(ll i = 2; i <= n; i++) {
     ll xx = idx[i];
     ll s = *st.begin();
     ll e = *st.rbegin();
     // cout << s << " " << e << endl;
     if(prev == 1) {
       if(xx == s-1 or xx == e+1) {
         ans.pb('1');
         st.insert(xx);
       } else {
        prev = 0;
        ans.pb('0');
        st.insert(xx);
       }
     } else if(prev == 0){
       if(xx > s and xx < e) {
         if(e - s  + 1 == i) {
           st.insert(xx);
           ans.pb('1');
           prev = 1;
         } else {
          st.insert(xx);
          ans.pb('0');
          prev = 0;
         }
       } else {
        ans.pb('0');
        st.insert(xx);
        prev = 0;
       }
     }
   }
   cout << ans << endl;
  }
  return 0;
} //good night.