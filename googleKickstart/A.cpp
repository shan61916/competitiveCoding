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
const ll maxx = (ll)(1.2e5 + 10); 
ll n, m, q;
vll key;
vll arr(maxx), ans(maxx); 
void preprocess() {
 ans.assign(maxx, 0);
 key.assign(maxx, 0);
 for(ll i = 0; i < m; i++) key[arr[i]] = 1;
 for(ll i = 1; i < maxx; i++) {
 	for(ll j = i; j < maxx; j+=i) {
 		// cout << key[j] << endl;
 		ans[i]+= key[j];
 	}
 }
 return ;
}
int main(){
 IOS
#ifdef SHAN
    freopen("input.txt" , "r" , stdin);  
#endif
  ll tc = 1;
  ll T;
  cin >> T;
  while(T--) {
  cout << "Case #" << tc++ << ": "; 
   cin >> n >> m >> q;
   for(ll i = 0; i < m; i++) cin >> arr[i];
   ll res = 0;
   ll todo = 0;
   preprocess();
   while(q--) {
       ll xx;
       cin >> xx;
       todo = n/xx;
       // cout << todo << " " << ans[xx] << endl;
       todo-= ans[xx];
       res+=todo;
   }
   cout << res << endl;
  }
  return 0;
} //good night.