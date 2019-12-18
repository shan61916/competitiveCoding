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
  ll n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  set<ll> st;
  sort(all(a));
  sort(all(b));
  do{
    do{
      ll tot = 0;
      for(ll i = 0; i < n; i++) {
        if(a[i] != b[i]) tot+= (1ll<<i);
      }
      // if(st.find(tot) == st.end()) {
      //   cout << a << endl << b << endl << endl;
      // }
      st.insert(tot);
    } while(next_permutation(all(b))); 
  } while(next_permutation(all(a)));
  // for(auto it: st) cout << it << " ";
  cout << st.size() << endl;
  return 0;
} //good night.