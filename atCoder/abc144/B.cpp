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
  set<ll> st;
  for(ll i = 1; i < 10; i++) {
  	for(ll j = 1; j < 10; j++) {
        st.insert(i*j);
  	}
  }
  if(st.find(n) != st.end()) cout << "Yes";
  else cout << "No";
  return 0;
} //good night.