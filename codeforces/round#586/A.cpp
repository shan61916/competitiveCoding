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
  string s;
  cin >> s;
  vector<ll> freq(27, 0);
  for(auto it: s) freq[it - 'a']++;
  ll t = freq['z' -'a'];
  ll x = n - 4*(t);
  ll o = (x)/3;
  for(ll i = 0; i < o; i++) cout << 1 << " ";
  for(ll i = 0; i < t; i++) cout << 0 << " ";
  return 0;
} //good night.